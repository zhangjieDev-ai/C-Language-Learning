// 11.0 Struct_结构体_打造真实商品档案
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h> // 【新武器】处理字符串需要用到它

// 【核心魔法：自定义数据类型】
// 结构体 (struct) 就像一个超级收纳盒，能把不同类型的数据打包在一起，变成一个整体。
struct Product {
    char name[50];      // 商品名称 (字符串/字符数组)
    double price;       // 商品单价 (浮点数)
    int stock;          // 库存数量 (整数)
}; // 【高能预警】定义结构体的花括号后面，必须要有分号结束！

int main()
{
    printf("--- 欢迎来到系统全面升级的 张洁超市 (11.0 结构体版) ---\n\n");

    // 【实战 1：上架第一件商品并直接初始化】
    // 就像 int a = 10; 一样，我们现在声明一个 struct Product 类型的变量，并按顺序给它赋值。
    struct Product item1 = { "国凌酱酒", 299.9, 20 };

    // 【实战 2：先声明，后赋值】
    struct Product item2;

    // 注意：C语言中，数组一旦建立，不能直接用 = 给整个字符数组赋值。
    // 我们需要使用 strcpy (String Copy) 把字符串"复制"进 name 里面。
    strcpy(item2.name, "VGN V98Pro3 键盘");
    item2.price = 399.0;
    item2.stock = 5;

    // 【进阶操作：读取结构体里的数据】
    // 使用 "点号 (.)" 操作符，就像是打开收纳盒，精准拿取里面的某一样东西！
    printf("=== 今日传统佳礼推荐 ===\n");
    printf("商品名：%s\n", item1.name);
    printf("单  价：%.2f 元\n", item1.price);
    printf("库  存：%d 件\n\n", item1.stock);

    printf("=== 极客数码优选 ===\n");
    printf("商品名：%s\n", item2.name);
    printf("单  价：%.2f 元\n", item2.price);
    printf("库  存：%d 件\n", item2.stock);

    // 【动态交互：模拟顾客购买】
    // 假设有顾客买走了 2 件商品，我们直接修改结构体里的 stock 变量
    item1.stock = item1.stock - 2; // 也可以简写为 item1.stock -= 2;

    printf("\n[系统提示] 滴！售出 2 瓶 %s，当前剩余库存：%d 件\n", item1.name, item1.stock);
    printf("[系统提示] 收银系统入账：%.2f 元\n", item1.price * 2);

    return 0;
}