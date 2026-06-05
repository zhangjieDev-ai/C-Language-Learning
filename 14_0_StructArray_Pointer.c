//14.0 StructArray_Pointer_数组与指针的终极结合
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct {
    char code[15];
    double price;
} Stock;

// 【新武器：接收数组的指针】
// 这里的 Stock *arr，接收的是整个集装箱的起始地址
void market_crash_simulation(Stock* arr, int size) {
    printf("\n[警报] 突发利空，全线跌停 (打9折)！\n");
    for (int i = 0; i < size; i++) {
        // 【核心重点】
        // 当我们用数组下标 arr[i] 访问时，它又变回了“本体”
        // 所以这里依然用点号(.)，而不是箭头(->)
        arr[i].price = arr[i].price * 0.9;
    }
}

int main() {
    // 我们的结构体数组（集装箱）
    Stock portfolio[2] = {
        {"贵州茅台", 1600.0},
        {"特斯拉", 180.0}
    };

    // 打印跌停前
    printf("【暴跌前】 %s: %.2f | %s: %.2f\n", portfolio[0].code, portfolio[0].price, portfolio[1].code, portfolio[1].price);

    // 【实战：把数组传递给函数】
    // 在 C 语言中，数组的名字（portfolio）天生就是一个指针！它代表数组第 0 个元素的地址。
    // 所以这里连取地址符 '&' 都不用加，直接把 portfolio 扔进去即可。
    market_crash_simulation(portfolio, 2);

    // 打印跌停后，验证本体是否被修改
    printf("【暴跌后】 %s: %.2f | %s: %.2f\n", portfolio[0].code, portfolio[0].price, portfolio[1].code, portfolio[1].price);

    return 0;
}