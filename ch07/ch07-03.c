/*
�й�:202511238
�̸�:������
���α׷� ��:���� �⺻���� �迭�� �ʱ�ȭ
��¥:2025-09-22
*/


#include <stdio.h>

int main()
{
	arr_reset();

	return 0;

}

int arr_reset()
{
	int arr[5] = { 1,2,3,4,5 };
	int i;

	printf("arr= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
} 
