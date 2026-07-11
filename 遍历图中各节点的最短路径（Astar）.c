#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    int mask = 1 << n;

    int** dist = (int**)malloc(sizeof(int*) * mask);
    for (int i = 0; i < mask; i++) {
        dist[i] = (int*)malloc(sizeof(int) * n);
        memset(dist[i], INF, sizeof(int) * n);
    }

    int** queue = (int**)malloc(sizeof(int*) * mask * n);
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        dist[1 << i][i] = 0;
        int* stateNodePair = (int*)malloc(sizeof(int) * 2);
        stateNodePair[0] = 1 << i;
        stateNodePair[1] = i;
        queue[rear++] = stateNodePair;
    }

    while (front != rear) {
        int* stateNodePair = queue[front];
        front++;
        int state = stateNodePair[0], u = stateNodePair[1], step = dist[state][u];
        if (state == mask - 1) return step;

        for (int i = 0; i < graphColSize[u]; i++) {
            int neighbor = graph[u][i];
            int nState = state | (1 << neighbor);
            if (dist[nState][neighbor] == INF) {
                dist[nState][neighbor] = step + 1;
                int* newStateNodePair = (int*)malloc(sizeof(int) * 2);
                newStateNodePair[0] = nState;
                newStateNodePair[1] = neighbor;
                queue[rear++] = newStateNodePair;
            }
        }

        free(stateNodePair);
    }

    return -1; // never
}