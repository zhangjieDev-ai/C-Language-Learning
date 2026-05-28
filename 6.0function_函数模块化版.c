//6.0function_函数模块化版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 【1. 打印员小房间】：这是我们自己定义的函数，放在 main 的外面
// void 的意思是：这个函数只负责干活（打印），不需要给经理回话（返回值）
void print_receipt(double prices[], int n, double total_sum)
{
    printf("\n---------- 张洁超市购物清单 ----------\n");
    for (int i = 0; i < n; i++)
    {
        printf("商品 %d:  %.2f 元\n", i + 1, prices[i]);
    }
    printf("------------------------------------\n");
    printf("合计金额：%.2f 元\n", total_sum);
}

// 【2. 经理室】：程序永远从这里开始跑
int main()
{
    double price_list[100] = { 0 };
    double price = 0;
    double total = 0;
    int count = 0;

    printf("--- 欢迎使用张洁超市 (6.0 函数模块化版) ---\n");

    while (1)
    {
        printf("请输入第 %d 件商品价格 (输入-1结束): ", count + 1);
        scanf("%lf", &price);

        if (price == -1) break;

        price_list[count] = price;
        total = total + price;
        count = count + 1; // 遵从你的习惯，写成老实人写法
    }

    // 【3. 经理下令】：这里就是调用函数
    // 经理只需要喊一声名字，并把账本（数组）、件数、总价“递给”打印员
    print_receipt(price_list, count, total);

    // 后面的找零逻辑可以暂时留在 main 
    double money = 0;
    printf("\n请输入支付金额：");
    scanf("%lf", &money);

    if (money >= total) {
        printf("交易成功！找零：%.2f 元。\n", money - total);
    }
    else {
        printf("钱不够！还差：%.2f 元。\n", total - money);
    }

    return 0;
}
