
/*
�й�:202511238
�̸�:������
���α׷� ��:���� ����
��¥:2025-09-22
*/


#include <stdio.h>

#define SIZE 5

int main()
{
	selection_sort();

	return 0;
}

int selection_sort()
{
	int data[SIZE] = { 7,3,9,5,1 };
	int i, j;
	int index, temp;

	for (i = 0; i < SIZE; i++)
	{
		index = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (data[index] > data[j])
				index = j;
		}
		if (i != index)
		{
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
	printf("���� ��: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;

}
