#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ��l�ƶüƺؤl�A�ϨC�����檺���G�����P
    srand((unsigned int)time(NULL));

    // �ŧi�@�Ӱ}�C�Ӧs�x�C���`�M�X�{������
    int sumCount[11] = {0}; // index 0 ���ϥΡA�q2��12�@11�ӥi�઺�M

    // �����Y��l 36,000 ��
    for (int i = 0; i < 36000; ++i) {
        // ���ͨ�����l���I�ơ]1~6�^
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;

        // �p���`�M
        int sum = die1 + die2;

        // ��s�����`�M���X�{����
        sumCount[sum - 2]++;
    }

    // �C�L�C���`�M���X�{����
    printf("�`�M\t�X�{����\n");
    for (int i = 0; i < 11; ++i) {
        printf("%d\t%d\n", i + 2, sumCount[i]);
    }

    return 0;
}
