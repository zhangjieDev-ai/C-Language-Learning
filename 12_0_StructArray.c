// 12.0 StructArray_结构体数组_打造超级货架
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

// 【新武器 1：typedef 给类型起别名】
// 每次写 struct Product 太麻烦？用 typedef 给它起个简单的名字 "Product"
// 就好像给 "超级收纳盒" 贴了个专属标签，以后直接用标签就行。
typedef struct {
    char name[50];
    double price;
    int stock;
} Product; // 从此以后，Product 就等价于之前的 struct Product

int main()
{
    printf("--- 张洁超市 (12.0 结构体数组版)：超级货架上线 ---\n\n");

    // 【新武器 2：结构体数组】
    // 就像一排带有 3 个格子的展示柜！我们一次性创建包含 3 个商品的数组。
    // 注意看它的初始化方式，外面一个大花括号代表数组，里面每个小花括号代表一个商品。
    Product shelf[3] = {
        {"国凌酱酒", 299.9, 20},
        {"VGN V98Pro3 键盘", 399.0, 5},
        {"农夫山泉 500ml", 2.0, 150}
    };

    // 【实战 1：配合 for 循环，一键遍历货架，展示所有商品】
    printf("=== 今日超市库存清单 ===\n");
    printf("编号 | %-20s | %-8s | %-6s\n", "商品名称", "单价(元)", "库存(件)");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        // 核心语法：shelf[i] 拿到第 i 个商品，然后再用 "点号(.)" 拿到它的具体属性
        // 这里的 %-20s 和 %-8.2f 中的负号表示“左对齐”，数字表示“占据的宽度”，能让排版非常整齐！
        printf(" %02d  | %-20s | %-8.2f | %-6d\n",
            i + 1, shelf[i].name, shelf[i].price, shelf[i].stock);
    }

    // 【实战 2：自动化统计超市总资产】
    double total_value = 0.0; // 准备一个变量用来累加总金额

    for (int i = 0; i < 3; i++) {
        // 把每个商品的 (单价 * 库存) 累加到 total_value 里
        total_value += shelf[i].price * shelf[i].stock;
    }

    printf("\n[系统提示] 滴！盘点完毕！当前货架商品总价值：%.2f 元\n", total_value);

    return 0;
}