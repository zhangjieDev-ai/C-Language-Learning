// 8.0 Pointer_VIP_Discount_指针终极版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 【新晋高管：VIP核算员】
// 注意这个星号 * ！！！它代表接收的不是一个普通的数字，而是一把“内存大门钥匙（物理地址）”
void apply_vip_discount(double *p_total)
{
    // 顺着钥匙（p_total）打开门，把主控板里的真实数据拿出来，乘 0.9，再塞回去
    *p_total = *p_total * 0.9;

    printf("\n[VIP专员] 叮！已成功入侵主控板，修改为9折！\n");
}

int main()
{
    double total = 0;

    printf("--- 欢迎使用张洁超市 (8.0 指针终极版) ---\n");
    printf("请输入顾客的初始总价: ");

    // 你马上就会彻底明白，为什么 scanf 里一直都有个 & 符号！
    scanf("%lf", &total);

    printf("\n打折前，主控板收银机里的总价是：%.2f 元\n", total);

    // 【高能预警：传递物理地址】
    // 注意这个 & 符号！主控板不是把 total 的钱数扔过去，而是把 total 盒子的“物理门牌号”递过去！
    apply_vip_discount(&total);

    // 我们在 main 函数里直接打印，看看 total 有没有被外面的函数强行改变！
    printf("打折后，主控板收银机里的总价变为了：%.2f 元\n", total);

    return 0;
}