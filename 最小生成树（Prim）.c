#include <stdio.h>
#include <stdbool.h>

#define MAX_V 1000   // 最大顶点数
#define INF 1e9      // 无穷大

// 边的结构体
struct Edge {
    int to, weight;
};

// Prim 算法求最小生成树
void prim(int V, const struct Edge adj[][MAX_V]) {
    struct Edge result[MAX_V];  // 存放最小生成树的边
    int dist[MAX_V];            // 记录每个节点到已包含节点集合的最短距离
    bool used[MAX_V];           // 记录每个节点是否被包含在已包含节点集合中

    // 初始时，任意选择一个节点加入已包含节点集合中
    used[0] = true;
    for (int i = 1; i < V; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    // 依次加入节点
    for (int k = 0; k < V - 1; k++) {
        int minDist = INF;
        int u = -1;

        // 找到距离已包含节点集合最近的节点
        for (int v = 0; v < V; v++) {
            if (!used[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        // 将该节点加入已包含节点集合中，并将对应的边加入最小生成树
        used[u] = true;
        result[k].to = u;
        result[k].weight = dist[u];

        // 更新所有未包含节点到已包含节点集合的最短距离
        for (int v = 0; v < V; v++) {
            if (!used[v] && adj[u][v].weight < dist[v]) {
                dist[v] = adj[u][v].weight;
            }
        }
    }

    // 输出最小生成树的边和权重
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", result[i].to, result[i].weight);
    }
}

int main() {
    int V = 6; // 顶点数
    struct Edge adj[MAX_V][MAX_V] = {
        { {1, 3}, {2, 1}, {0, 0} },
        { {0, 3}, {2, 5}, {3, 4}, {0, 0} },
        { {0, 1}, {1, 5}, {3, 2}, {4, 6}, {0, 0} },
        { {1, 4}, {2, 2}, {4, 7}, {5, 8}, {0, 0} },
        { {2, 6}, {3, 7}, {5, 9}, {0, 0} },
        { {3, 8}, {4, 9}, {0, 0} }
    };

    prim(V, adj);

    return 0;
}
