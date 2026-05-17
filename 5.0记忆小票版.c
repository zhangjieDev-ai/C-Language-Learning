//20260201_记忆小票版5.0//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    // 【新武器】数组：开辟 100 个连续的小格子来存价格
    double price_list[100] = { 0 };
    double price = 0;
    double total = 0;
    int count = 0; // 【新盒子】用来记录一共买了多少件商品

    printf("--- 欢迎使用张洁超市 (5.0 记忆小票版) ---\n");

    while (1)
    {
        printf("请输入第 %d 件商品价格 (输入-1结束): ", count + 1);
        scanf("%lf", &price); // 记住是小写字母 l，不是数字 1 哦！

        if (price == -1)
        {
            break;
        }

        // 【核心变动】把价格存入数组的第 count 个格子
        price_list[count] = price;
        total = total + price;
        count++; // 商品件数加 1
    }

    // 【华彩片段】打印超市小票
    printf("\n---------- 张洁超市购物清单 ----------\n");
    for (int i = 0; i < count; i++)
    {
        // 逐行把数组里的价格拿出来展示
        printf("商品 %d:  %.2f 元\n", i + 1, price_list[i]);
    }
    printf("------------------------------------\n");
    printf("合计金额：%.2f 元\n", total);

    double money = 0;
    printf("\n请输入支付金额：");
    scanf("%lf", &money);

    if (money >= total) {
        printf("交易成功！找零：%.2f 元。感谢支持！\n", money - total);
    }
    else {
        printf("钱不够！还差：%.2f 元。\n", total - money);
    }

    return 0;
}