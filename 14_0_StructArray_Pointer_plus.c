// 16.1 StructArrayPointer_plus结构体数组与指针_极限性能优化版
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct {
    char code[15];
    char name[50];
    double current_price;
    int quantity;
    // 为了演示你的第二个问题，新增两个真实交易字段
    int volume;         // 当日成交量
    double turnover;    // 当日成交额
} Stock;

// 模拟从交易所传来的、包含了多种数据的“大号数据包”
// 为了简化演示，我们假设传进来三个数组，分别对应价格、成交量、成交额
void UpdateBatchMarketData(Stock* portfolio, int count, double* new_prices, int* new_volumes, double* new_turnovers) {
    for (int i = 0; i < count; i++) {

        // 【回答你的第一个问题：在这个完整的函数里，单独定义新指针】
        // 这一步是性能的核心：只做 1 次地址加法，把当前这只股票的门牌号死死攥在手里！
        Stock* current_stock = portfolio + i;

        // 【回答你的第二个问题：为什么在真实系统里要这么写】
        // 接下来要更新整整 3 个字段！
        // 因为门牌号 current_stock 已经算好了，下面全是直接“推门进房间”，没有任何多余的数学计算
        current_stock->current_price = *(new_prices + i);
        current_stock->volume = *(new_volumes + i);
        current_stock->turnover = *(new_turnovers + i);

        /* 【反面教材：如果用 [] 实体语法糖，底层有多惨烈】
        portfolio[i].current_price = *(new_prices + i); // CPU: 算一次 portfolio + i
        portfolio[i].volume        = *(new_volumes + i); // CPU: 又算一次 portfolio + i
        portfolio[i].turnover      = *(new_turnovers + i); // CPU: 还要算一次 portfolio + i
        */
    }
}

int main() {
    printf("--- 张洁的量化交易系统 (16.1 极致性能指针版) ---\n\n");

    // 定义两只股票，初始成交量和成交额都是 0
    Stock my_portfolio[2] = {
        {"SH600519", "贵州茅台", 1600.50, 100, 0, 0.0},
        {"SZ000858", "五粮液", 150.00, 200, 0, 0.0}
    };

    // 模拟交易所同时推过来的三组最新数据
    double latest_prices[2] = { 1680.00, 155.50 };
    int    latest_volumes[2] = { 50000, 120000 };
    double latest_turnovers[2] = { 84000000.0, 18660000.0 };

    // 调用性能优化版的更新函数
    UpdateBatchMarketData(my_portfolio, 2, latest_prices, latest_volumes, latest_turnovers);

    // 打印验证
    printf("[更新后] %s \t最新价: %.2f 元 \t成交量: %d 手 \t成交额: %.2f 元\n",
        my_portfolio[0].name, my_portfolio[0].current_price, my_portfolio[0].volume, my_portfolio[0].turnover);

    printf("[更新后] %s \t最新价: %.2f 元 \t成交量: %d 手 \t成交额: %.2f 元\n",
        my_portfolio[1].name, my_portfolio[1].current_price, my_portfolio[1].volume, my_portfolio[1].turnover);

    return 0;
}