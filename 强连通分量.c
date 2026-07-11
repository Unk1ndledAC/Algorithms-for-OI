#include <stdio.h>
#include <stdbool.h>

#define MAX_V 100    // 最大顶点数

int min(int a, int b) {
    return a < b ? a : b;
}

// 图的结构体定义
struct Graph {
    int V;          // 顶点数
    int E;          // 边数
    int adj[MAX_V][MAX_V];  // 邻接矩阵
};

// 栈的结构体定义
struct Stack {
    int data[MAX_V];
    int top;
};

// 初始化栈
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// 入栈
void push(struct Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

// 出栈
int pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

// Tarjan算法求强连通分量
void tarjan(struct Graph *graph, int u, int dfn[], int low[], bool inStack[], struct Stack *stack, int *index, int *sccCount) {
    dfn[u] = low[u] = ++(*index);
    inStack[u] = true;
    push(stack, u);

    for (int v = 0; v < graph->V; v++) {
        if (graph->adj[u][v]) {
            if (dfn[v] == 0) {
                tarjan(graph, v, dfn, low, inStack, stack, index, sccCount);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    if (dfn[u] == low[u]) {
        int w;
        do {
            w = pop(stack);
            inStack[w] = false;
            printf("%d ", w);
        } while (w != u);
        (*sccCount)++;
        printf("\n");
    }
}

// 求强连通分量的入口函数
void findStronglyConnectedComponents(struct Graph *graph) {
    int dfn[MAX_V] = {0};
    int low[MAX_V];
    bool inStack[MAX_V];
    struct Stack stack;
    int index = 0;
    int sccCount = 0;

    initStack(&stack);

    for (int i = 0; i < graph->V; i++) {
        if (dfn[i] == 0) {
            tarjan(graph, i, dfn, low, inStack, &stack, &index, &sccCount);
        }
    }
}

int main() {
    struct Graph graph = {
        5, 7,   // 顶点数和边数
        {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0}
        }  // 邻接矩阵
    };

    findStronglyConnectedComponents(&graph);

    return 0;
}
