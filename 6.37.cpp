#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���j�G���j�M���
int binarySearch(const int array[], int start, int end, int key) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        // �p�G���F��ȡA��^����
        if (array[mid] == key) {
            return mid;
        }

        // �p�G��Ȥ񤤶������p�A�h�b���b�����j�M
        if (key < array[mid]) {
            return binarySearch(array, start, mid - 1, key);
        }

        // �p�G��Ȥ񤤶������j�A�h�b�k�b�����j�M
        return binarySearch(array, mid + 1, end, key);
    }

    // �p�G�����A��^-1
    return -1;
}

int main() {
    srand((unsigned int)time(NULL));

    // ���ϥΪ̿�J�}�C�j�p
    int arraySize;
    printf("�п�J�}�C�j�p�G");
    scanf("%d", &arraySize);

    // �ʺA�t�m�O����H�x�s�}�C
    int* array = (int*)malloc(arraySize * sizeof(int));

    // ���ϥΪ̿�J�}�C����
    printf("�п�J%d�Ӿ�ơA�H�Ů���j�G", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    // �Ƨǰ}�C�]�ϥΧֳt�Ƨǡ^
    qsort(array, arraySize, sizeof(int), [](const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    });

    // �C�L�Ƨǫ᪺�}�C
    printf("�Ƨǫ᪺�}�C�G\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // �n�j�M�����
    int key;
    printf("�п�J�n�j�M����ơG");
    scanf("%d", &key);

    // �I�s���j�G���j�M���
    int result = binarySearch(array, 0, arraySize - 1, key);

    // �P�_���G�æL�X�����T��
    if (result != -1) {
        printf("��� %d �b�}�C�������ެ� %d\n", key, result);
    } else {
        printf("�������� %d\n", key);
    }

    // ����ʺA�t�m���O����
    free(array);

    return 0;
}

