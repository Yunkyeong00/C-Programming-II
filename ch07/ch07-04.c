/*
�й�:202511238
�̸�:������
���α׷� ��:�迭�� ũ�⺸�� �ʱⰪ�� ���� �����ϴ� ���
��¥:2025-09-22
*/

#include <stdio.h>

int main()
{
	arr();

	return 0;

}

int arr()
{
	int amount[5] = { 1,1,5 };
	int price[5] = { 0 };
	int i;

	printf("amount= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", amount[i]);
	}
	printf("\n");

	printf("price= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", price[i]);
	}
	printf("\n");

	return 0;

}