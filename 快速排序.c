#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分割函数，将数组分为两部分，并返回分割点的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选取最后一个元素作为基准值
    int i = low - 1; // i 表示小于基准值的区域边界
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 快速排序递归函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // 找到分割点的索引
        quickSort(arr, low, pivotIndex - 1); // 对左子数组进行快速排序
        quickSort(arr, pivotIndex + 1, high); // 对右子数组进行快速排序
    }
}

// 打印数组元素
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 7, 2, 4, 1, 6, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("排序后的数组：");
    printArray(arr, size);

    return 0;
}
