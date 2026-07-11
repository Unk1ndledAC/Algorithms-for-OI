#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

// 邻接表存储图
typedef struct {
    int dest;
} Edge;

// 添加边到邻接表
void addEdge(Edge adjList[], int adjListIndex, int dest, int* edgeCount) {
    adjList[adjListIndex + *edgeCount].dest = dest;
    (*edgeCount)++;
}

// 使用DFS找到子环
void findSubcircuit(Edge adjList[], int adjListIndex, int* visited, int* circuit, int* circuitIndex, int* edgeCount) {
    for (int i = 0; i < *edgeCount; i++) {
        int v = adjList[adjListIndex + i].dest;
        if (!visited[adjListIndex + i]) {
            visited[adjListIndex + i] = 1;
            findSubcircuit(adjList, v, visited, circuit, circuitIndex, edgeCount);
        }
    }
    circuit[(*circuitIndex)++] = adjListIndex;
}

// 找到欧拉回路
void findEulerCircuit(Edge adjList[], int numEdges, int* circuit) {
    int circuitIndex = 0;
    int visited[MAX_EDGES] = {0};

    // 从节点 0 开始搜索
    findSubcircuit(adjList, 0, visited, circuit, &circuitIndex, &numEdges);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Edge adjList[MAX_EDGES];
    int edgeCount = 0;

    // 添加边到邻接表
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest, &edgeCount);
    }

    // 寻找欧拉回路
    int* circuit = (int*)malloc(numEdges * sizeof(int));
    findEulerCircuit(adjList, numEdges, circuit);

    // 输出欧拉回路
    printf("Euler Circuit: ");
    for (int i = numEdges - 1; i >= 0; i--) {
        printf("%d ", circuit[i]);
    }
    printf("\n");

    free(circuit);

    return 0;
}
