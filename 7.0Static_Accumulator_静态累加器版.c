//7.0Static_Accumulator_静态累加器，累计销售额版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 【新员工：财务会计】
// 这个函数专门负责统计“自开业以来”的总营业额
void update_sales(double current_bill)
{
    // 注意看这里！加了 static
    // 它是“石碑变量”，只在第一次运行时初始化为 0
    // 之后每次调用这个函数，它都会记得上次的值
    static double total_revenue = 0;

    total_revenue = total_revenue + current_bill;

    printf("\n[后台统计] 当前这单：%.2f 元", current_bill);
    printf("\n[后台统计] 今日累计总营业额已达：%.2f 元\n", total_revenue);
}

// 【打印员】：保持不变，负责貌美如花的清单
void print_receipt(double prices[], int n, double total_sum)
{
    printf("\n---------- 张洁超市 (7.0 累计版) ----------\n");
    for (int i = 0; i < n; i++)
    {
        printf("商品 %d:  %.2f 元\n", i + 1, prices[i]);
    }
    printf("------------------------------------------\n");
    printf("本单合计：%.2f 元\n", total_sum);
}

int main()
{
    // 为了让你看到 static 的威力，我们用一个循环模拟“多位客人”
    for (int customer = 1; customer <= 3; customer++)
    {
        double price_list[100] = { 0 };
        double price = 0;
        double total = 0;
        int count = 0;

        printf("\n=== 正在接待第 %d 位顾客 ===\n", customer);

        while (1)
        {
            printf("请输入价格 (输入-1结算): ");
            scanf("%lf", &price);
            if (price == -1) break;

            price_list[count] = price;
            total = total + price;
            count = count + 1;
        }

        // 调用打印函数
        print_receipt(price_list, count, total);

        // 调用财务函数：你会发现 total_revenue 在不断增加！
        update_sales(total);

        printf("\n--- 请按回车接待下一位客人 ---\n");
        getchar(); getchar(); // 简单的暂停一下
    }

    printf("\n今日营业结束，辛苦了！\n");
    return 0;
}
