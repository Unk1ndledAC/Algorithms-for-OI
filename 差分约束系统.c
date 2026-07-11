#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100    // 最大变量数
#define MAX_M 10000  // 最大约束数

struct Edge {
    int u, v;
    int w;
};

struct Graph {
    int n;            // 变量数
    int m;            // 约束数
    struct Edge edges[MAX_M];   // 边列表
};

// Bellman-Ford算法判断是否存在负环
bool hasNegativeCycle(struct Graph *graph, int dist[]) {
    for (int i = 1; i <= graph->n; i++) {
        for (int j = 0; j < graph->m; j++) {
            int u = graph->edges[j].u;
            int v = graph->edges[j].v;
            int w = graph->edges[j].w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (i == graph->n) {
                    return true;  // 存在负环
                }
            }
        }
    }

    return false;  // 不存在负环
}

// SPFA算法求解差分约束系统
bool solveDifferenceConstraints(struct Graph *graph, int x[]) {
    int dist[MAX_N];
    bool inQueue[MAX_N];
    int cnt[MAX_N];
    int queue[MAX_N * 2];

    for (int i = 1; i <= graph->n; i++) {
        dist[i] = 0;
        inQueue[i] = false;
        cnt[i] = 0;
    }

    int head = 0, tail = 1;
    queue[head] = 1;
    inQueue[1] = true;

    while (head != tail) {
        int u = queue[head++];
        if (head >= MAX_N * 2) {
            head = 0;
        }
        inQueue[u] = false;

        for (int i = 0; i < graph->m; i++) {
            int v = graph->edges[i].v;
            int w = graph->edges[i].w;
            if (graph->edges[i].u == u && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                x[v] = x[u] + 1;
                if (!inQueue[v]) {
                    queue[tail++] = v;
                    if (tail >= MAX_N * 2) {
                        tail = 0;
                    }
                    inQueue[v] = true;
                    if (++cnt[v] > graph->n) {
                        return false;  // 存在负环
                    }
                }
            }
        }
    }

    return true;  // 不存在负环
}

int main() {
    struct Graph graph = {
        3, 3,    // 变量数和约束数
        {
            {1, 2, 3},
            {2, 3, -2},
            {3, 1, 4}
        }  // 边列表
    };

    int x[MAX_N] = {0};
    if (solveDifferenceConstraints(&graph, x)) {
        printf("x1=%d, x2=%d, x3=%d\n", x[1], x[2], x[3]);
    } else {
        printf("存在负环\n");
    }

    return 0;
}
