/*
�й�:202511238
�̸�:������
���α׷� ��:�迭�� ����
��¥:2025-09-22
*/

#include <stdio.h>

int main()
{
	arr_copy();

	return 0;

}

int arr_copy()
{
	int x[5] = { 10,20,30,40,50 };
	int y[5] = { 0 };

	int i;

	//y=x;  //�迭�� �ٸ� �迭�� �����ϸ� ������ ����
	for (i = 0; i < 5; i++)
	{
		y[i] = x[i];
	}

	printf("y= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", y[i]);
	}
	printf("\n");

	reuturn 0;
}
