#include <stdio.h>

// 计算最大公约数
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// 计算最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b; // 公式：a * b / 最大公约数
}

int main() {
    int num1 = 12;
    int num2 = 18;
    printf("最小公倍数: %d\n", lcm(num1, num2));
    return 0;
}
