/*
�й�:202511238
�̸�:������
���α׷� ��:
��¥:

*/

#include <stdio.h>

void get_sum_product(int x, int y,int *sum, int *product);
int first();


int main()
{

	first();

	return 0;
}

int first()
{
	int result1, result2;

	get_sum_product(10, 20, &result1, &result2);
	printf("sum=%d,  product = %d", result1, result2);
}

void get_sum_product(int x, int y, int *sum,int *product)
{
	*sum = x + y;
	*product = x * y;
}