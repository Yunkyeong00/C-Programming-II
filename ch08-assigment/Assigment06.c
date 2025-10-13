#include <stdio.h>

int main()
{
	first();

	return 0;
}

int first()
{
	int arr[10] = { 23,45,62,12,99,83,23,50,72,37 };

	printf("¹è¿­: ");
	for (int i=0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");

	int big_index, small_index;
	get_min_max(arr,10,&small_index,&big_index);

	printf("ÃÖ´ñ°ª:%d\n", big_index);
	printf("ÃÖ¼Ú°ª:%d", small_index);
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
