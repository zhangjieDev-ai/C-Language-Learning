//17.0_File_超市账本硬盘永生版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double price = 0;
    double total = 0;
    int count = 0;

    printf("--- 欢迎使用张洁超市 (硬核存盘版) ---\n");

    // ==========================================
    // 动作 1：打开硬盘的大门！
    // 我们用 "a"（追加模式），这样每一笔新客人的账单都会记录在下面，不会覆盖以前的
    // ==========================================
    FILE* bill_file = fopen("supermarket_bills.txt", "a");

    // 顶级防爆检查：如果硬盘满了或者权限不够，fopen 会返回 NULL
    if (bill_file == NULL)
    {
        printf("致命错误：无法在硬盘上创建或打开账本文件！\n");
        return -1;
    }

    // 像往常一样做生意
    while (1)
    {
        printf("请输入第 %d 件商品价格（输入-1结束）：", count + 1);
        scanf("%lf", &price);

        if (price == -1) break;

        total = total + price;
        count++;
    }

    // ==========================================
    // 动作 2：向硬盘里写入数据！
    // ==========================================
    // 注意看！这里全是 fprintf，数据顺着 bill_file 管道直接流进硬盘！
    fprintf(bill_file, "\n========== 交易凭证 ==========\n");
    fprintf(bill_file, "本次共购买商品: %d 件\n", count);
    fprintf(bill_file, "总计消费金额: %.2f 元\n", total);
    fprintf(bill_file, "==============================\n");

    printf("\n结账完成！交易记录已永久保存至硬盘超市账本中！\n");

    // ==========================================
    // 动作 3：拔掉管道，关闭硬盘文件大门！
    // 这一步如果不写，你刚才写的内容可能全都在缓冲区里，一关程序就没了！
    // ==========================================
    fclose(bill_file);

    return 0;
}