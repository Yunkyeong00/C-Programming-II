/*
�й�:202511238
�̸�:������
���α׷� ��:
��¥:

*/

#include <stdio.h>

void sort_array(int arr_r[], int size);
void array();

int main()
{
	array();

	return 0;

}

void array()
{
	int arr[10] = { 90, 6, 96, 40, 62,48,26,89,48,25 };
	printf("���� ��: ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	sort_array(arr, 10);

	return 0;
}

void sort_array(int arr_r[],int size)
{
	int index, temp;

	for (int i = 0; i < size-1; i++)
	{
		index = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr_r[index] > arr_r[j])
				index = j;
		}

		if (i != index)
		{
			temp = arr_r[i];
			arr_r[i] = arr_r[index];
			arr_r[index] = temp;
		}
	}

	printf("���� ��: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr_r[i]);
	}


}