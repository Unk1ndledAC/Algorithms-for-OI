#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// 邻接表存储图
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 添加边到邻接表
void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// 删除边
void removeEdge(Node** adjList, int src, int dest) {
    Node* currNode = adjList[src];
    Node* prevNode = NULL;

    while (currNode != NULL && currNode->dest != dest) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        return;
    }

    if (prevNode == NULL) {
        adjList[src] = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}

// 使用DFS找到子环
void findSubcircuit(Node** adjList, int u, int* circuit, int* circuitIndex) {
    Node* currNode = adjList[u];

    while (currNode != NULL) {
        int v = currNode->dest;
        removeEdge(adjList, u, v); // 删除边，防止重复遍历
        findSubcircuit(adjList, v, circuit, circuitIndex);
        currNode = currNode->next;
    }

    circuit[(*circuitIndex)++] = u; // 将节点加入欧拉回路
}

// 找到欧拉回路
void findEulerCircuit(Node** adjList, int numNodes, int* circuit) {
    int circuitIndex = 0;

    // 复制邻接表，防止修改原图
    Node** adjListCopy = (Node**)malloc(numNodes * sizeof(Node*));
    for (int i = 0; i < numNodes; i++) {
        adjListCopy[i] = NULL;
        Node* currNode = adjList[i];

        while (currNode != NULL) {
            addEdge(&adjListCopy[i], currNode->dest, currNode->dest);
            currNode = currNode->next;
        }
    }

    // 从节点 0 开始搜索
    findSubcircuit(adjListCopy, 0, circuit, &circuitIndex);

    free(adjListCopy);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // 创建邻接表
    Node** adjList = (Node**)malloc(numNodes * sizeof(Node*));
    for (int i = 0; i < numNodes; i++) {
        adjList[i] = NULL;
    }

    // 添加边到邻接表
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    // 寻找欧拉回路
    int* circuit = (int*)malloc(numEdges * sizeof(int));
    findEulerCircuit(adjList, numNodes, circuit);

    // 输出欧拉回路
    printf("Euler Circuit: ");
    for (int i = numEdges - 1; i >= 0; i--) {
        printf("%d ", circuit[i]);
    }
    printf("\n");

    // 释放内存
    for (int i = 0; i < numNodes; i++) {
        Node* currNode = adjList[i];
        while (currNode != NULL) {
            Node* temp = currNode;
            currNode = currNode->next;
            free(temp);
        }
    }
    free(adjList);
    free(circuit);

    return 0;
}
