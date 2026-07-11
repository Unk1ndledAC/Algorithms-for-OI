#include <stdio.h>
#define MAXN 10005
int n, W;
int w[MAXN], v[MAXN];
int f[MAXN][MAXN];
int max(int a, int b) { return a > b ? a : b; }
int main() {
    scanf("%d %d", &n, &W);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &w[i], &v[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= W; ++j)
            if (j >= w[i])
                f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
            else
                f[i][j] = f[i-1][j];
    printf("%d\n", f[n][W]);
    return 0;
}
