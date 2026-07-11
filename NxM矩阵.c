#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// 定义矩阵结构
typedef struct {
    int rows;
    int cols;
    int data[MAX_ROWS][MAX_COLS];
} Matrix;

// 初始化矩阵
void initMatrix(Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
}

// 设置矩阵元素的值
void setElement(Matrix *mat, int row, int col, int value) {
    if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        mat->data[row][col] = value;
    } else {
        printf("Invalid row or column index\n");
    }
}

// 获取矩阵元素的值
int getElement(Matrix *mat, int row, int col) {
    if (row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        return mat->data[row][col];
    } else {
        printf("Invalid row or column index\n");
        return -1; // 返回一个默认值表示错误
    }
}

// 打印矩阵
void printMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// 矩阵加法
Matrix addMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix result;
    initMatrix(&result, mat1->rows, mat1->cols);

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result.data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return result;
}

// 矩阵减法
Matrix subtractMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix result;
    initMatrix(&result, mat1->rows, mat1->cols);

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result.data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }

    return result;
}

// 矩阵乘法
Matrix multiplyMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix result;
    initMatrix(&result, mat1->rows, mat2->cols);

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

// 矩阵除法（逐元素除法）
Matrix divideMatrix(Matrix *mat1, Matrix *mat2) {
    Matrix result;
    initMatrix(&result, mat1->rows, mat1->cols);

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            if (mat2->data[i][j] != 0) {
                result.data[i][j] = mat1->data[i][j] / mat2->data[i][j];
            } else {
                printf("Error: Divide by zero\n");
                return result;
            }
        }
    }

    return result;
}

int main() {
    Matrix mat1, mat2;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    initMatrix(&mat1, rows, cols);
    initMatrix(&mat2, rows, cols);

    // 设置矩阵元素的值
    printf("\nEnter the values for matrix 1:\n");
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            int value;
            printf("Enter the value for element at position (%d, %d): ", i, j);
            scanf("%d", &value);
            setElement(&mat1, i, j, value);
        }
    }

    printf("\nEnter the values for matrix 2:\n");
    for (int i = 0; i < mat2.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            int value;
            printf("Enter the value for element at position (%d, %d): ", i, j);
            scanf("%d", &value);
            setElement(&mat2, i, j, value);
        }
    }

    // 打印矩阵
    printf("\nMatrix 1:\n");
    printMatrix(&mat1);

    printf("\nMatrix 2:\n");
    printMatrix(&mat2);

    // 矩阵加法
    Matrix sum = addMatrix(&mat1, &mat2);
    printf("\nMatrix Sum:\n");
    printMatrix(&sum);

    // 矩阵减法
    Matrix diff = subtractMatrix(&mat1, &mat2);
    printf("\nMatrix Difference:\n");
    printMatrix(&diff);

    // 矩阵乘法
    Matrix product = multiplyMatrix(&mat1, &mat2);
    printf("\nMatrix Product:\n");
    printMatrix(&product);

    // 矩阵除法
    Matrix quotient = divideMatrix(&mat1, &mat2);
    printf("\nMatrix Quotient:\n");
    printMatrix(&quotient);

    return 0;
}
