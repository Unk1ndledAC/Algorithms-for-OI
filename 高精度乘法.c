#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 + len2 - 1;
    int carry = 0;
    char result[MAX_N] = {0};

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int digit1 = num1[len1 - 1 - i] - '0';
            int digit2 = num2[len2 - 1 - j] - '0';
            int product = digit1 * digit2 + carry + result[maxLen - i - j] - '0';
            carry = product / 10;
            result[maxLen - i - j] = product % 10 + '0';
        }
        if (carry > 0) {
            result[maxLen - i - len2] += carry;
            carry = 0;
        }
    }

    int i = 0;
    while (result[i] == '0' && i < maxLen) {
        i++;
    }

    char* finalResult = strdup(result + i);
    return finalResult;
}

int main() {
    char num1[] = "123456789";
    char num2[] = "987654321";
    char* result = multiply(num1, num2);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}
