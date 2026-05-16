//20260201_收银机4.0_浮点数版//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	double price = 0;
	double total = 0;  

	printf("---欢迎使用张洁超市（4.0浮点数版）---\n");

	while (1)
	{
		printf("请输入商品价格（输入-1结束扫码）：");
		scanf("%lf", &price);

		if (price == -1)
		{
			break;
		}

		total = total + price;
		printf("当前累计金额：%.2f 元\n", total);
	}

	printf("\n==================================\n");
	printf("所有商品总计：%.2f 元\n", total);

	double money = 0;
	printf("请输入您支付的金额：");
	scanf("%lf", &money);

	if (money >= total)
	{
		printf("交易成功！找给您：%.2f 元。欢迎下次光临，张洁！\n", money - total);
	}
	else
	{
		printf("交易失败！钱不够，还差：%.2f 元。请把商品放回去点...\n", total - money);
	}

	return  0;
}
