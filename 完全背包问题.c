#include <stdio.h>
#define MAXN 10005
int n, W;
int w[MAXN], v[MAXN];
int f[MAXN];
int max(int a, int b) { return a > b ? a : b; }
int main() {
    scanf("%d %d", &n, &W);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &w[i], &v[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= W; ++j)
            f[j] = max(f[j], f[j-w[i]] + v[i]);
    printf("%d\n", f[W]);
    return 0;
}
