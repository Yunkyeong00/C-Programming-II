/* ���ϸ�: CH07_8.c

   * ����: ��ǰ ������ ����� ������ �迭�� ���Ͽ� ������(%)�� �Է¹޾� ���ε� ������ ����ؼ� ����ϴ�
   *       ���α׷��� �ۼ��Ͻÿ�, ��ǰ ������ ����� �迭�� ũ��� 5�̰�, ��ǰ ������ �Է¹޾Ƽ� ����Ѵ�
   *       ���ε� ������ ������ �迭�� �����Ѵ�

   * �ۼ���: ������

   * ��¥: 2025.9.21

   * ����: v1.0

   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int price_print(int price[], int result_price[5]);
int calculate_discount(int price[], int discount);
int input_PriceDiscount();


int main()
{
	input_PriceDiscount();

	return 0;
}

int input_PriceDiscount()
{
	int i;
	int price[5];
	int discount;

	printf("��ǰ�� 5���� �Է��ϼ���: ");

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &price[i]);
	}

	printf("������(%)? ");
	scanf("%d", &discount);

	calculate_discount(price, discount);

}

int calculate_discount(int price[], int discount)
{
	int result_price[5];

	for (int i = 0; i < 5; i++)
	{
		result_price[i] = (price[i] - (price[i] * discount / 100));
	}

	price_print(price,result_price);
}

int price_print(int price[], int result_price[5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("����: %6d --> ���ΰ�: %6d\n", price[i], result_price[i]);
	}
}