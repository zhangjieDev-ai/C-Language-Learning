// 14.0 StructArrayPointer_结构体数组与指针_批量行情更新rehash
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct {
    char code[15];
    char name[50];
    double current_price;
    int quantity;
} Stock;

// 【新武器 1：接收结构体指针来处理数组】
void UpdateBatchPrices(Stock* portfolio, int count, double* new_prices) {
    for (int i = 0; i < count; i++) {
        // 【新武器 2：指针偏移与箭头运算符的终极结合】
        (portfolio + i)->current_price = *(new_prices + i);
    }
}

int main() {
    printf("--- 张洁的量化交易系统 (16.0 结构体数组指针版) ---\n\n");

    // 定义一个包含两只股票的结构体数组
    Stock my_portfolio[2] = {
        {"SH600519", "贵州茅台", 1600.50, 100},
        {"SZ000858", "五粮液", 150.00, 200}
    };

    // 模拟从交易所接收到的最新一笔批量行情数据
    double latest_prices[2] = { 1680.00, 155.50 };

    // 【新武器 3：数组名即指针】
    UpdateBatchPrices(my_portfolio, 2, latest_prices);

    printf("[更新后] %s 最新价: %.2f 元\n", my_portfolio[0].name, my_portfolio[0].current_price);
    printf("[更新后] %s 最新价: %.2f 元\n", my_portfolio[1].name, my_portfolio[1].current_price);

    return 0;
}