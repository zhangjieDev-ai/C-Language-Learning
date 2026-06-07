// 15_0 StructNestedPointer_plus嵌套与指针连招版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 1. 策略图纸（子）
typedef struct {
    int buy_trigger_volume;
    double stop_loss_rate;
} Strategy;

// 2. 股票图纸（主）
typedef struct {
    char code[15];
    char name[50];
    double current_price;
    Strategy my_strategy;    // 嵌套了策略实体
} Stock;

// 【新武器：接收主结构体指针，修改最深处的嵌套数据】
void UpdateStopLoss(Stock* p, double new_rate) {
    // 【本节课唯一核心绝对高能点：箭头与点号的混合双打】
    p->my_strategy.stop_loss_rate = new_rate;
}

int main() {
    printf("--- 张洁的量化交易系统 (16.0 嵌套指针连招版) ---\n\n");

    // 造出一个真实的股票实体
    Stock target_stock = { "SH600519", "贵州茅台", 1600.50, {50000, 0.05} };

    printf("[调整前] %s 的止损线: %.2f\n", target_stock.name, target_stock.my_strategy.stop_loss_rate);

    // 把大铁盒的门牌号（地址）传进函数
    UpdateStopLoss(&target_stock, 0.08);

    printf("[紧急调整后] %s 的止损线: %.2f\n", target_stock.name, target_stock.my_strategy.stop_loss_rate);

    return 0;
}