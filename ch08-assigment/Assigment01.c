/*
�й�:202511238
�̸�:������
���α׷� ��: ũ�Ⱑ 3�� double�� �迭�� ��� ������ �ּҸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ּ� ���ϱ� �����ڸ� ������� ���ÿ�.
��¥:

*/

#include <stdio.h>

int main()
{
	pointer_arr();

	return 0;
}

int pointer_arr()
{
	double arr[3];
	double *p = arr;
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("x[%d]�� �ּ�:%X\n",i,arr+i);
	}
}