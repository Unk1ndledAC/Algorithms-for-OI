#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INF 0x3f3f3f3f

int graph[MAX_SIZE][MAX_SIZE]; // 图的邻接矩阵表示
int dist[MAX_SIZE][MAX_SIZE]; // 存储所有顶点之间的最短路径长度

// 弗洛伊德算法求解所有顶点之间的最短路径
void floyd(int n) {
    memcpy(dist, graph, sizeof(graph)); // 初始化距离矩阵为邻接矩阵

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // 更新路径长度
                }
            }
        }
    }
}

int main() {
    int n = 5; // 图中顶点数
    int m = 7; // 图中边数

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0; // 自己到自己的距离为0
            } else {
                graph[i][j] = INF; // 其他距离初始化为无穷大
            }
        }
    }

    graph[0][1] = 2;
    graph[0][2] = 4;
    graph[1][2] = 1;
    graph[1][3] = 7;
    graph[2][3] = 3;
    graph[2][4] = 5;
    graph[3][4] = 1;

    floyd(n);

    printf("所有顶点之间的最短路径长度：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("%d -> %d : INF\n", i, j);
            } else {
                printf("%d -> %d : %d\n", i, j, dist[i][j]);
            }
        }
    }

    return 0;
}
