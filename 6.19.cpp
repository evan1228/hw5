#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 初始化亂數種子，使每次執行的結果都不同
    srand((unsigned int)time(NULL));

    // 宣告一個陣列來存儲每個總和出現的次數
    int sumCount[11] = {0}; // index 0 不使用，從2到12共11個可能的和

    // 模擬擲骰子 36,000 次
    for (int i = 0; i < 36000; ++i) {
        // 產生兩顆骰子的點數（1~6）
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;

        // 計算總和
        int sum = die1 + die2;

        // 更新相應總和的出現次數
        sumCount[sum - 2]++;
    }

    // 列印每個總和的出現次數
    printf("總和\t出現次數\n");
    for (int i = 0; i < 11; ++i) {
        printf("%d\t%d\n", i + 2, sumCount[i]);
    }

    return 0;
}
