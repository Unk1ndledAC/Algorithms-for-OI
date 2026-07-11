#include <stdio.h>
#include <stdbool.h>

#define MAX_E 1000   // 最大边数
#define MAX_V 100    // 最大顶点数

// 边的结构体
struct Edge {
    int from, to, weight;
};

// 并查集的初始化
void initSet(int n, int parent[]) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 查找节点所属的集合
int findSet(int x, int parent[]) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

// 合并两个集合
void unionSets(int x, int y, int parent[]) {
    int rootX = findSet(x, parent);
    int rootY = findSet(y, parent);
    parent[rootY] = rootX;
}

// 按权重升序排序边
void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal 算法求最小生成树
void kruskal(int V, int E, const struct Edge edges[]) {
    struct Edge result[MAX_V];  // 存放最小生成树的边
    int parent[MAX_V];          // 记录每个节点所属的集合

    initSet(V, parent);
    sortEdges(edges, E);

    int k = 0;  // 记录已选择的边数
    int i = 0;  // 遍历边数组的指针

    while (k < V - 1) {
        struct Edge currEdge = edges[i];
        int rootX = findSet(currEdge.from, parent);
        int rootY = findSet(currEdge.to, parent);

        // 如果两个顶点不在同一个集合中，则选择该边加入最小生成树，并合并两个集合
        if (rootX != rootY) {
            result[k++] = currEdge;
            unionSets(rootX, rootY, parent);
        }

        i++;
    }

    // 输出最小生成树的边和权重
    for (int j = 0; j < V - 1; j++) {
        printf("%d - %d\n", result[j].from, result[j].to);
    }
}

int main() {
    int V = 6; // 顶点数
    int E = 9; // 边数
    struct Edge edges[MAX_E] = {
        {0, 1, 3}, {0, 2, 1}, {1, 2, 5}, {1, 3, 4},
        {2, 3, 2}, {2, 4, 6}, {3, 4, 7}, {3, 5, 8},
        {4, 5, 9}
    };

    kruskal(V, E, edges);

    return 0;
}
