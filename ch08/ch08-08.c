/*
�й�:202511238
�̸�:������
���α׷� ��:
��¥:

*/

#include <stdio.h>

void arr_plus();

int main()
{
	arr_plus();

	return 0;
}

void arr_plus()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = &arr[0];

	int i;

	for (i = 0; i < 5; i++, p++)
	{
		printf("p=%p, ", p);
		printf("*p=%d\n", *p);
	}
}
