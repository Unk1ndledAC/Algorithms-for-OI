#include <stdio.h>

#define MAX_SIZE 1000
#define LOG_MAX_SIZE 10

int max(int a, int b) {
    return a > b ? a : b;
}

int st[MAX_SIZE][LOG_MAX_SIZE];

// 预处理构建ST表
void buildSparseTable(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i]; // 区间长度为1时的最大值即为元素本身
    }

    // 动态规划计算其他区间长度的最大值
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 查询区间最大值
int queryMax(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= (r - l + 1)) {
        k++;
    }
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    int arr[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildSparseTable(arr, n);

    printf("原始数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int l = 2, r = 7; // 查询区间为 [l, r]

    int maxVal = queryMax(l, r);

    printf("区间最大值：%d\n", maxVal);

    return 0;
}
