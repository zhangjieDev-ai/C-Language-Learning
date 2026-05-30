// 9.0 Pointer_Array_Batch_指针与数组梦幻联动
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 【进阶高管：批量打折专员】
// 注意：这里接收的 p_prices 是一个指针，它接收的是购物车的“首地址”
void apply_batch_discount(double *p_prices, int count)
{
    printf("\n[批量专员] 叮！拿到购物车第一件商品的门牌号，开始全场9折大扫荡！\n");

    for (int i = 0; i < count; i++)
    {
        // 顺着首地址，挨个往后找，修改真实内存里的数据
        // 注意：p_prices[i] 在计算机眼里，其实就是 *(p_prices + i)
        p_prices[i] = p_prices[i] * 0.9;
    }
}

int main()
{
    // 顾客的购物车，里面装了 5 件商品的价格
    double cart[5] = { 100.0, 50.0, 20.0, 200.0, 10.0 };
    // 计算购物车里有多少件商品 (总字节数 / 单个元素的字节数)
    int count = sizeof(cart) / sizeof(cart[0]);

    printf("--- 欢迎使用张洁超市 (9.0 数组指针联动版) ---\n");

    printf("打折前，购物车里商品的价格分别是：\n");
    for (int i = 0; i < count; i++)
    {
        printf("%.2f  ", cart[i]);
    }
    printf("\n");

    // 【超级高能预警：数组名的真面目】
    // 发现了吗？！这里传给函数的时候，我们竟然没写 &cart ！
    // 因为在 C 语言里，【数组名本身，就是数组第 0 个元素的物理地址】！
    // cart 就等价于 &cart[0]，所以它天然就是一把钥匙，不需要再加 & 取地址了！
    apply_batch_discount(cart, count);

    printf("\n我们在 main 函数里直接打印，看看购物车里的商品有没有被批量改变：\n");
    for (int i = 0; i < count; i++)
    {
        printf("%.2f  ", cart[i]);
    }
    printf("\n");

    return 0;
}