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
    printf("�п�J�}�C�j�p�G");
    scanf("%d", &arraySize);

    int* array = (int*)malloc(arraySize * sizeof(int));

    printf("�п�J%d�Ӿ�ơA�H�Ů���j�G", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    qsort(array, arraySize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    printf("�Ƨǫ᪺�}�C�G\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int key;
    printf("�п�J�n�j�M����ơG");
    scanf("%d", &key);

    int result = binarySearch(array, 0, arraySize - 1, key);

    if (result != -1) {
        printf("��� %d �b�}�C�������ެ� %d\n", key, result);
    } else {
        printf("�������� %d\n", key);
    }

    free(array);

    return 0;
}

