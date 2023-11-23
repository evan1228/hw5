#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int binarySearch(const int array[], int start, int end, int key) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (array[mid] == key) {
            return mid;
        }

        if (key < array[mid]) {
            return binarySearch(array, start, mid - 1, key);
        }

        return binarySearch(array, mid + 1, end, key);
    }

    return -1;
}

int main() {
    srand((unsigned int)time(NULL));

    int arraySize;
    printf("請輸入陣列大小：");
    scanf("%d", &arraySize);

    int* array = (int*)malloc(arraySize * sizeof(int));

    printf("請輸入%d個整數，以空格分隔：", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    qsort(array, arraySize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    printf("排序後的陣列：\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int key;
    printf("請輸入要搜尋的整數：");
    scanf("%d", &key);

    int result = binarySearch(array, 0, arraySize - 1, key);

    if (result != -1) {
        printf("鍵值 %d 在陣列中的索引為 %d\n", key, result);
    } else {
        printf("未找到鍵值 %d\n", key);
    }

    free(array);

    return 0;
}

