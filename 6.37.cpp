#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 遞迴二分搜尋函數
int binarySearch(const int array[], int start, int end, int key) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        // 如果找到了鍵值，返回索引
        if (array[mid] == key) {
            return mid;
        }

        // 如果鍵值比中間元素小，則在左半部分搜尋
        if (key < array[mid]) {
            return binarySearch(array, start, mid - 1, key);
        }

        // 如果鍵值比中間元素大，則在右半部分搜尋
        return binarySearch(array, mid + 1, end, key);
    }

    // 如果未找到，返回-1
    return -1;
}

int main() {
    srand((unsigned int)time(NULL));

    // 讓使用者輸入陣列大小
    int arraySize;
    printf("請輸入陣列大小：");
    scanf("%d", &arraySize);

    // 動態配置記憶體以儲存陣列
    int* array = (int*)malloc(arraySize * sizeof(int));

    // 讓使用者輸入陣列元素
    printf("請輸入%d個整數，以空格分隔：", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    // 排序陣列（使用快速排序）
    qsort(array, arraySize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    // 列印排序後的陣列
    printf("排序後的陣列：\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 要搜尋的鍵值
    int key;
    printf("請輸入要搜尋的整數：");
    scanf("%d", &key);

    // 呼叫遞迴二分搜尋函數
    int result = binarySearch(array, 0, arraySize - 1, key);

    // 判斷結果並印出相應訊息
    if (result != -1) {
        printf("鍵值 %d 在陣列中的索引為 %d\n", key, result);
    } else {
        printf("未找到鍵值 %d\n", key);
    }

    // 釋放動態配置的記憶體
    free(array);

    return 0;
}

