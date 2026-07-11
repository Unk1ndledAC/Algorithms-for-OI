#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

char* add(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    int carry = 0;
    char result[MAX_N] = {0};

    for (int i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[maxLen - 1 - i] = sum % 10 + '0';
    }

    if (carry > 0) {
        char carryChar[2] = {carry + '0', '\0'};
        strcat(carryChar, result);
        strcpy(result, carryChar);
    }

    return strdup(result);
}

int main() {
    char num1[] = "123456789";
    char num2[] = "987654321";
    char* result = add(num1, num2);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}
