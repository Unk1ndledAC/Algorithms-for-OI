#include <stdio.h>
#include <limits.h>

#define INF 0x3f3f3f3f
int min(int a, int b) {
    return a < b ? a : b;
}
//DP+floyd
int shortestPathLength(int graphSize, int** graph, int graphColSize){
    int n = graphSize;
    int mask = 1 << n;
    // Floyd 求两点的最短路径
    int dist[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < graphColSize; j++)
            dist[i][graph[i][j]] = 1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // DP 过程，如果从 i 能够到 j 的话，使用 i 到 j 的最短距离（步长）来转移
    int f[mask][n];
    // 起始时，让所有状态的最短距离（步长）为正无穷
    for (int i = 0; i < mask; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j] = INF;
        }
    }
    // 由于可以将任意点作为起点出发，可以将这些起点的最短距离（步长）设置为 0
    for (int i = 0; i < n; i++) {
        f[1 << i][i] = 0;
    }
    // 枚举所有的 state
    for (int state = 0; state < mask; state++) {
        // 枚举 state 中已经被访问过的点
        for (int i = 0; i < n; i++) {
            if (((state >> i) & 1) == 0) continue;
            // 枚举 state 中尚未被访问过的点
            for (int j = 0; j < n; j++) {
                if (((state >> j) & 1) == 1) continue;
                f[state | (1 << j)][j] = min(f[state | (1 << j)][j], f[state][i] + dist[i][j]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, f[mask - 1][i]);
    return ans;
}
