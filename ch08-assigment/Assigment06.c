/*
�й�:202511238
�̸�:������
���α׷� ��: ũ�Ⱑ 3�� double�� �迭�� ��� ������ �ּҸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ּ� ���ϱ� �����ڸ� ������� ���ÿ�.
��¥:

*/

#include <stdio.h>

int main()
{
	first();

	return 0;
}

int first()
{
	int arr[10] = { 23,45,62,12,99,83,23,50,72,37 };

	printf("�迭: ");
	for (int i=0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");

	int big_index, small_index;
	get_min_max(arr,10,&small_index,&big_index);

	printf("�ִ�:%d\n", big_index);
	printf("�ּڰ�:%d", small_index);
}

int get_min_max(int arr[], int size, int*b_index,int*s_index)
{
	*b_index = 0;
	*s_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[*b_index])
		{
			*b_index = i;

		}

		if (arr[i] < arr[*s_index])
		{
			*s_index = i;

		}
	}


	return s_index, b_index;
}
