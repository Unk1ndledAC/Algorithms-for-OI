#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

int cmp(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 != len2) {
        return len1 - len2;
    } else {
        return strcmp(num1, num2);
    }
}

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

char* divide(char* num1, char* num2) {
    char result[MAX_N] = {0};
    char remainder[MAX_N] = {0};
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (cmp(num1, num2) < 0) {
        strcpy(result, "0");
        strcpy(remainder, num1);
        char* finalResult = strdup(result);
        return finalResult;
    }

    char dividend[MAX_N] = {0};
    strncpy(dividend, num1, len2);

    for (int i = 0; i < len1 - len2 + 1; i++) {
        while (cmp(dividend, num2) >= 0) {
            strcat(result, "1");
            char* temp = subtract(dividend, num2);
            strcpy(dividend, temp);
            free(temp);
        }
        if (i < len1 - len2) {
            strncat(dividend, &num1[i + len2], 1);
        }
    }

    if (strlen(result) == 0) {
        strcpy(result, "0");
    }
    strcpy(remainder, dividend);

    char* finalResult = strdup(result);
    return finalResult;
}

int main() {
    char num1[] = "123456789";
    char num2[] = "987654321";
    char* result = divide(num1, num2);
    printf("商: %s\n", result);
    free(result);
    return 0;
}
