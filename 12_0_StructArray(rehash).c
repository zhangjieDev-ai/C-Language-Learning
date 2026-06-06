//12_0_StructArray(rehash)
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    printf("--- 高频量化交易系统测试：精度陷阱与绝对安全 ---\n\n");

    int total_trades = 1000000; // 模拟 100 万次高频套利交易
    printf("[系统提示] 计划执行 %d 次交易，每次套利 0.01 元（1分钱）。\n", total_trades);
    printf("[理论预期] 最终总收益应为：10000.00 元\n\n");

    // ==========================================
    // 【反面教材：使用 double 记录资金（精度丢失）】
    // ==========================================
    double bad_balance = 0.0;       // 账户余额（元）
    double profit_per_trade = 0.01; // 每次赚 0.01 元

    for (int i = 0; i < total_trades; i++) {
        bad_balance += profit_per_trade; // 疯狂累加 100 万次
    }


    // ==========================================
    // 【正确姿势：使用长整型 long long 记录资金（绝对精确）】
    // ==========================================
    // 行业规范：金融变量名通常带上单位后缀 _cents，明确告知这是“分”
    // 为什么用 long long？因为普通 int 最多只能存 21 亿（也就是 2100万 元），对资金池不够用！
    long long good_balance_cents = 0;       // 账户余额（分）
    long long profit_per_trade_cents = 1;   // 每次赚 1 分

    for (int i = 0; i < total_trades; i++) {
        good_balance_cents += profit_per_trade_cents; // 疯狂累加 100 万次
    }


    // ==========================================
    // 【揭晓真相：底层的财务灾难】
    // ==========================================
    printf("----------------------------------------\n");
    printf("【危险的 double 账户（元）】\n");
    printf("日常显示 (%%.2f)   : %.2f 元\n", bad_balance);
    // 使用 %.14f 扒开底层数据看真相
    printf("底层真实数据 (%%.14f): %.14f 元\n\n", bad_balance);

    printf("【安全的 long long 账户（分）】\n");
    // 展示给用户看时，除以 100.0 变成元（注意这里用的是 100.0 触发浮点除法！）
    printf("日常显示           : %.2f 元\n", good_balance_cents / 100.0);
    printf("底层真实数据 (整数): %lld 分\n", good_balance_cents);
    printf("----------------------------------------\n");

    return 0;
}