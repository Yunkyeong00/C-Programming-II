/*
�й�:202511238
�̸�:������
���α׷� ��:
��¥:

*/

#include <stdio.h>

void pointer_swap();
void swap(int* x, int* y);



int main()
{
	pointer_swap();

	return 0;
}

void pointer_swap()
{
	int a = 3,b = 7;

	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d", a, b);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}