#include <stdio.h>
#include <stdbool.h>

const int N = 1000005;
bool isPrime[N];
int primes[N], m;

void getPrimes() {
    for (int i = 2; i < N; i++) {
        isPrime[i] = true;
    }
    m = 0;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes[m++] = i;
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    getPrimes();
    // 现在 primes 数组中存储了所有小于 N 的素数
    // m 表示素数的个数
    return 0;
}
