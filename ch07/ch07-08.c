/*
�й�:202511238
�̸�:������
���α׷� ��:�迭�� ��
��¥:2025-09-22
*/

#include <stdio.h>

int main()
{
	arr_comprison();

	return 0;

}

int arr_comprison()
{
	int x[5] = { 10,20,30,40,50 };
	int y[5] = { 10,20,30,40,50 };

	int i = 0;
	int is_equal;

	if (x == y)
		printf("�� �迭�� �ּҰ� �����ϴ�.\n");

	is_equal = 1;
	for (i = 0; i < 5; i++)
	{
		if (x[i] != y[i])
		{
			is_equal = 0;
			break;
		}
	}
	if (is_qual == 1)
	{
		printf("�� �迭�� ������ �����ϴ�.\n");
	}

	return 0;
}
