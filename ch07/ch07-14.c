/*
�й�:202511238
�̸�:������
���α׷� ��:print_array �Լ��� ���� �� ȣ��
��¥:2025-09-22
*/


#include <stdio.h>
#define MAX 10

void print_array(int arr[], int size);
int arr(void);

int main(void)
{
	arr();

	return 0;
}

int arr(void)
{
	int scores[] = { 99, 98, 67, 72, 90, 82, 3 };
	int size = sizeof(scores) / sizeof(scores[0]);
	int arr[MAX] = { 0 };
	print_array(scores, size); print_array(arr, MAX);

}

void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}