//2.0收银台带退出//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int money = 0;
	int price = 0;

	while (1)
	{

        printf("\n==========================\n");
		printf("请输入你带了多少钱（输入-1退出）：");
		scanf("%d", &money);

		if (money == -1)
		{
			printf("程序正在退出，欢迎下次使用！\n");
			break;
		}

	    printf("请输入商品的价格：");
		scanf("%d", &price);

		if (money >= price)
		{
			int change = money - price;
			printf("交易成功！找给你：%d 元\n", change);
		}
		else
		{
			printf("交易失败！你的钱不够，你还差：%d 元\n", price - money);
		}

	}
	printf("我已经退出循环啦！\n");
    return 0;
} 