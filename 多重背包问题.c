#include <stdio.h>
#define MAXN 10005
int n, W;
int w[MAXN], v[MAXN], s[MAXN];
int f[MAXN];
int max(int a, int b) { return a > b ? a : b; }
int main() {
    scanf("%d %d", &n, &W);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = W; j >= w[i]; --j)
            for (int k = 1; k <= s[i] && k * w[i] <= j; ++k)
                f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
    printf("%d\n", f[W]);
    return 0;
}
