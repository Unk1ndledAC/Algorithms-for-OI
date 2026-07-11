#include <stdio.h>

#define MAX_SIZE 100

int parent[MAX_SIZE]; // 存储每个节点的父节点

// 初始化并查集
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 查找节点所属的集合（根节点）
int find(int x) {
    if (parent[x] == x) {
        return x; // 根节点
    } else {
        return find(parent[x]); // 递归查找根节点
    }
}

// 合并两个集合
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY; // 将 rootX 的根节点设为 rootY，合并两个集合
    }
}

// 判断两个节点是否属于同一个集合
int isConnected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n = 10; // 节点个数

    init(n); // 初始化并查集

    unionSet(0, 1); // 合并节点 0 和节点 1 所在的集合
    unionSet(2, 3); // 合并节点 2 和节点 3 所在的集合
    unionSet(4, 5); // 合并节点 4 和节点 5 所在的集合
    unionSet(6, 7); // 合并节点 6 和节点 7 所在的集合
    unionSet(0, 2); // 合并节点 0 和节点 2 所在的集合

    printf("0 and 3 are%s connected.\n", isConnected(0, 3) ? "" : " not");
    printf("4 and 6 are%s connected.\n", isConnected(4, 6) ? "" : " not");

    return 0;
}
