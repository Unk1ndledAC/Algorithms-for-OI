#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

char* subtract(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    int borrow = 0;
    char result[MAX_N] = {0};

    for (int i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[maxLen - 1 - i] = diff + '0';
    }

    int i = 0;
    while (result[i] == '0' && i < maxLen - 1) {
        i++;
    }

    char* finalResult = strdup(result + i);
    return finalResult;
}

int main() {
    char num1[] = "987654321";
    char num2[] = "123456789";
    char* result = subtract(num1, num2);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}
