// 15.0 StructNested_结构体嵌套_策略绑定
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

// 【新武器 1：定义一个“策略”结构体（即将作为子结构体）】
typedef struct {
    int buy_trigger_volume;  // 买入触发成交量（手）
    double stop_loss_rate;   // 止损比例（比如 0.05 代表跌 5% 就割肉）
} Strategy;

// 这是我们的主结构体
typedef struct {
    char code[15];
    char name[50];
    double current_price;
    // 【新武器 2：在主结构体的肚子里，声明子结构体变量】
    Strategy my_strategy;
} Stock;

int main() {
    printf("--- 张洁的量化交易系统 (17.0 结构体嵌套版) ---\n\n");

    // 【新武器 3：嵌套结构体的初始化】
    Stock target_stock = { "SH600519", "贵州茅台", 1600.50, {50000, 0.05} };

    // 【新武器 4：连续使用点号(.)访问最深处的嵌套成员】
    printf("股票: %s \n止损触发比例: %.2f\n", target_stock.name, target_stock.my_strategy.stop_loss_rate);

    return 0;
}