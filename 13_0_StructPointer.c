// 13.0 StructPointer_结构体指针_隔空操作的超级遥控器
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    double price;
    int stock;
} Product;

// 【新武器 1：结构体作为函数参数（传指针）】
// 注意这里的 Product *p。星号(*)代表这是一个“遥控器（指针）”，而不是商品本体。
void apply_discount(Product* p) {

    // 【新武器 2：箭头运算符 -> 】
    // 当我们手握“指针”时，不能用点号(.)来获取属性，必须用箭头(->)！
    // p->price 的意思是：顺着 p 记录的地址找到商品本体，然后修改它的 price。
    p->price = p->price * 0.8; // 给本体打 8 折

    printf("[系统提示] 滴！遥控修改成功！【%s】已调价至: %.2f 元\n", p->name, p->price);
}

int main() {
    printf("--- 张洁超市 (13.0 结构体指针版)：超级遥控器上线 ---\n\n");

    // 进货两件重量级商品
    Product item1 = { "GPW2 鼠标", 899.0, 10 };
    Product item2 = { "对节白蜡盆景", 1500.0, 2 };

    printf("【调价前】\n");
    printf("1. %-20s | 价格: %.2f\n", item1.name, item1.price);
    printf("2. %-20s | 价格: %.2f\n\n", item2.name, item2.price);

    // 【实战：使用遥控器（指针）修改本体数据】
    // 调用函数时，必须在变量名前面加上取地址符 '&'
    // 这相当于把 item1 和 item2 在内存里的“GPS 坐标”发给了 apply_discount 函数
    apply_discount(&item1);
    apply_discount(&item2);

    printf("\n【调价后】\n");
    // 这里验证一下，看看 main 函数里的本体是不是真的被修改了
    printf("1. %-20s | 最新价格: %.2f\n", item1.name, item1.price);
    printf("2. %-20s | 最新价格: %.2f\n", item2.name, item2.price);

    return 0;
}