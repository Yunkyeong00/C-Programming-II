
/*
�й�:202511238
�̸�:������
���α׷� ��:2���� �迭�� �ʱ�ȭ
��¥:2025-09-22
*/


#include <stdio.h>
#define ROW 3
#define COL 2

int main()
{
	arr_reset();

	return 0;
}

int arr_reset()
{
	int data[ROW][COL] = {
		{10,20},{30,40},{50,60}
	};
	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%3d ", data[i][j]);
		printf("\n");
	}
	return 0;
}