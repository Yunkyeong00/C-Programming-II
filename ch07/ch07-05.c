/*
�й�:202511238
�̸�:������
���α׷� ��:�迭�� ���� ���
��¥:2025-09-22
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARR_SIZE 5

int main()
{
	arr_use();

	return 0;
}

int arr_use()
{
	int arr[ARR_SIZE] = { 0 };
	int i;

	arr[0] = 5;
	arr[1] = arr[0] + 10;
	arr[2] = add(arr[0], arr[0]);
	printf("������ 2�� �Է��ϼ���: ");
	scanf("%d %d", &arr[3], &arr[4]);

	for (i = 0; i < ARR_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;

}

int add(int a, int b)
{
	return a + b;
}