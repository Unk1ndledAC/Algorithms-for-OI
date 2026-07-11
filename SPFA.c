#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INF 0x3f3f3f3f

typedef struct Edge {
    int to;     // 边的终点
    int weight; // 边的权重
    struct Edge* next; // 下一条边
} Edge;

// 图的邻接表表示
Edge* graph[MAX_SIZE];

// 添加一条有向边
void addEdge(int from, int to, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = to;
    e->weight = weight;
    e->next = graph[from];
    graph[from] = e;
}

// SPFA算法求解单源最短路径
void spfa(int start, int n, int dist[]) {
    bool inQueue[MAX_SIZE];
    memset(inQueue, false, sizeof(inQueue)); // 初始化所有顶点的入队状态为false

    for (int i = 0; i < n; i++) {
        dist[i] = INF; // 初始化所有顶点的距离为无穷大
    }
    dist[start] = 0; // 起点的距离为0

    int queue[MAX_SIZE]; // 队列
    int front = 0, rear = 0;
    queue[rear++] = start; // 起点入队
    inQueue[start] = true; // 标记起点已经入队

    while (front != rear) {
        int u = queue[front++]; // 出队一个顶点
        inQueue[u] = false; // 标记该顶点已经出队

        // 遍历所有邻接节点
        for (Edge* e = graph[u]; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;

            if (dist[v] > dist[u] + w) { // 如果找到更短的路径
                dist[v] = dist[u] + w; // 更新距离

                if (!inQueue[v]) { // 如果该顶点不在队列中，将其入队
                    queue[rear++] = v;
                    inQueue[v] = true;
                }
            }
        }
    }
}

int main() {
    int n = 5; // 图中顶点数
    int m = 7; // 图中边数

    int start = 0; // 起点为0

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 3, 3);
    addEdge(2, 4, 5);
    addEdge(3, 4, 1);

    int dist[MAX_SIZE]; // 存储最短路径长度

    spfa(start, n, dist);

    printf("起点到各顶点的最短路径长度：\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d : %d\n", start, i, dist[i]);
    }

    return 0;
}
