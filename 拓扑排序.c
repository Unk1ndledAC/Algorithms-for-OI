#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000000

// 边的结构体
typedef struct Edge {
    int from, to, weight;
} Edge;

// 图的结构体
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge edges[MAX_VERTICES];
} Graph;

// 拓扑排序
int topologicalSort(Graph *graph, int sorted[]) {
    int *inDegree = (int*)malloc(sizeof(int) * graph->numVertices);
    int *queue = (int*)malloc(sizeof(int) * graph->numVertices);
    int front = 0, rear = 0;

    // 初始化入度数组
    for (int i = 0; i < graph->numVertices; i++) {
        inDegree[i] = 0;
    }

    // 统计每个顶点的入度
    for (int i = 0; i < graph->numEdges; i++) {
        inDegree[graph->edges[i].to]++;
    }

    // 将入度为0的顶点入队
    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;  // 记录已经输出的顶点数

    while (front != rear) {
        int vertex = queue[front++];
        sorted[count++] = vertex;

        // 遍历与当前顶点相连的边，更新入度
        for (int i = 0; i < graph->numEdges; i++) {
            if (graph->edges[i].from == vertex) {
                inDegree[graph->edges[i].to]--;
                if (inDegree[graph->edges[i].to] == 0) {
                    queue[rear++] = graph->edges[i].to;
                }
            }
        }
    }

    free(inDegree);
    free(queue);

    if (count < graph->numVertices) {
        printf("图中存在环，无法进行拓扑排序\n");
        return -1;
    } else {
        return 0;
    }
}

// 关键路径
void criticalPath(Graph *graph, int *ve, int *vl) {
    int *sorted = (int*)malloc(sizeof(int) * graph->numVertices);
    if (topologicalSort(graph, sorted) == -1) {
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        ve[i] = 0;
    }

    for (int i = 0; i < graph->numEdges; i++) {
        int from = graph->edges[i].from;
        int to = graph->edges[i].to;
        int weight = graph->edges[i].weight;
        if (ve[from] + weight > ve[to]) {
            ve[to] = ve[from] + weight;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        vl[i] = ve[graph->numVertices - 1];
    }

    for (int i = graph->numVertices - 1; i >= 0; i--) {
        int vertex = sorted[i];
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->edges[j].from == vertex) {
                int from = graph->edges[j].from;
                int to = graph->edges[j].to;
                int weight = graph->edges[j].weight;
                if (vl[to] - weight < vl[from]) {
                    vl[from] = vl[to] - weight;
                }
            }
        }
    }

    printf("关键路径上的活动及其最早开始时间和最晚开始时间：\n");
    for (int i = 0; i < graph->numEdges; i++) {
        int from = graph->edges[i].from;
        int to = graph->edges[i].to;
        int weight = graph->edges[i].weight;
        int e = ve[from];
        int l = vl[to] - weight;
        printf("活动%d: VE=%d, VL=%d\n", i+1, e, l);
        if (e == l) {
            printf("活动%d为关键活动\n", i+1);
        }
    }

    free(sorted);
}

int main() {
    Graph graph = {
        6,  // 顶点数
        10, // 边数
        {
            {0, 1, 3},
            {0, 2, 2},
            {1, 3, 4},
            {1, 4, 5},
            {2, 3, 5},
            {2, 4, 6},
            {3, 5, 7},
            {4, 5, 8},
            {1, 2, 1},
            {3, 4, 2}
        }
    };

    int *ve = (int*)malloc(sizeof(int) * graph.numVertices);
    int *vl = (int*)malloc(sizeof(int) * graph.numVertices);
    criticalPath(&graph, ve, vl);

    free(ve);
    free(vl);

    return 0;
}
