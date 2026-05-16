//20260201_购物车模式3.0//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int price = 0;
	int total = 0;  

	printf("---欢迎使用张洁超市（购物车模式）---\n");

	while (1)
	{
		printf("请输入商品价格（输入-1结束扫码）：");
		scanf("%d", &price);

		if (price == -1)
		{
			break;
		}
		total = total + price;
		printf("当前累计金额：%d 元\n", total);
	}

	printf("\n==================================\n");
	printf("所有商品总计：%d 元\n", total);

	int money = 0;
	printf("请输入您支付的金额：");
	scanf("%d", &money);

	if (money >= total)
	{
		printf("交易成功！找给您：%d 元。欢迎下次光临，张洁！\n", money - total);
	}
	else
	{
		printf("交易失败！钱不够，还差： % d元。请把商品放回去点...\n", total - money);
	}

	return  0;
}