#include <stdio.h>
#include <stdlib.h>

// 贪心算法示例：找零钱问题
void greedyCoinChange(int amount, int *coins, int numCoins) {
    printf("使用贪心算法找零：%d = ", amount);
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            printf("%d ", coins[i]);
            amount -= coins[i];
        }
    }
    printf("\n");
}

// 主函数
int main() {
    // 示例：找零问题
    int amount = 39;
    int coins[] = {25, 10, 5, 1};
    int numCoins = 4;

    greedyCoinChange(amount, coins, numCoins);

    return 0;
}
