/*
�й�:202511238
�̸�:������
���α׷� ��:
��¥:

*/

#include <stdio.h>

void study_arr();


int main()
{
	study_arr();

	return 0;
}

void study_arr()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = &arr[0];

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("p + %d = %p, ", i, p + i);
		printf("*(p + %d) = %d\n", i, *(p + i));
	}

	return 0;
}
