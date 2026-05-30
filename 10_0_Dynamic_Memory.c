// 10.0 Dynamic_Memory_动态内存_伸缩购物车
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> // 【高能预警】使用 malloc 和 free 必须包含这个头文件！

int main()
{
    int count = 0;

    printf("--- 欢迎再次来到张洁超市 (10.0 动态购物车版) ---\n");
    printf("请问您今天打算购买几件商品？请输入数量：");
    scanf("%d", &count);

    // 【进阶魔法：向系统借内存】
    // malloc(需要借的字节数)
    // 我们需要 count 个 double 的空间，所以是 count * sizeof(double)
    // malloc 返回的是这块新内存的首地址，我们用指针 cart 接收它！
    double* cart = (double*)malloc(count * sizeof(double));

    // 借钱不一定成功，借内存也一样。必须检查系统有没有把内存借给我们
    if (cart == NULL)
    {
        printf("超市购物车库存不足（内存分配失败）！\n");
        return 1; // 异常退出
    }

    printf("\n叮！成功为您发放容量为 %d 的专属购物车！\n", count);

    // 愉快地往动态购物车里装商品
    for (int i = 0; i < count; i++)
    {
        // 这里的用法和 9.0 完全一样！指针当数组用！
        cart[i] = (i + 1) * 10.5; // 随便造点价格数据
    }

    printf("\n您购物车里的商品价格分别是：\n");
    for (int i = 0; i < count; i++)
    {
        printf("%.2f  ", cart[i]);
    }
    printf("\n");

    // 【终极铁律：有借有还，再借不难】
    // 堆区借来的内存系统不会自动回收，用完必须手动还给系统，否则会导致“内存泄漏”！
    free(cart);

    // 【好习惯：斩草除根】
    // 内存还回去了，但 cart 指针还记着那个地址（野指针）。
    // 为了防止以后误操作，手动把它设为 NULL（空指针）。
    cart = NULL;

    printf("\n结账完毕，购物车已归还。期待您的下次光临！\n");

    return 0;
}