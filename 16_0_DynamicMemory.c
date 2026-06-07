// 16.0 DynamicMemory_动态内存分配
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// 【新武器 1：引入标准库头文件，里面包含了买卖内存的函数】
#include <stdlib.h> 
#include <string.h>

typedef struct {
    char code[15];
    double current_price;
} Stock;

int main() {
    printf("--- 张洁的量化交易系统 (16.0 动态内存版) ---\n\n");

    int stock_count = 0;
    // 模拟从交易所接口获取到今天需要交易的股票数量（这个数字运行前是未知的）
    stock_count = 3;

    // 【新武器 2：向操作系统买地（malloc）】
    // 计算需要的总面积：3 个股票盒子 * 每个盒子的大小
    // malloc 会在内存的“堆区（Heap）”划出一块地，并返回这块地的门牌号（指针）
    // (Stock*) 是一次强制转换，告诉编译器这块地是用来建 Stock 别墅的
    Stock* dynamic_portfolio = (Stock*)malloc(stock_count * sizeof(Stock));

    // 检查是否买地成功（如果内存爆了会返回 NULL）
    if (dynamic_portfolio == NULL) {
        printf("内存分配失败！\n");
        return -1;
    }

    // 地买好了，手里握着首地址指针，后面的操作和之前一模一样！
    // 装填第 0 只股票的数据（使用指针算术和箭头）
    strcpy((dynamic_portfolio + 0)->code, "SH600519");
    (dynamic_portfolio + 0)->current_price = 1600.50;

    // 装填第 1 只股票的数据（使用数组语法糖，效果一样）
    strcpy(dynamic_portfolio[1].code, "SZ000858");
    dynamic_portfolio[1].current_price = 150.00;

    printf("成功动态创建了 %d 只股票的内存空间！\n", stock_count);
    printf("股票 0: %s, 价格: %.2f\n", dynamic_portfolio[0].code, dynamic_portfolio[0].current_price);
    printf("股票 1: %s, 价格: %.2f\n", dynamic_portfolio[1].code, dynamic_portfolio[1].current_price);

    // 【新武器 3：拆迁还地（free）】
    // 动态买来的地（堆内存）没有围墙保护，函数结束也不会自动回收！
    // 必须手动把门牌号交给 free 函数，把地还给操作系统，否则会导致“内存泄漏”！
    free(dynamic_portfolio);

    // 【好习惯：消灭过期门牌号】
    dynamic_portfolio = NULL;

    return 0;
}