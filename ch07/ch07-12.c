
/*
�й�:202511238
�̸�:������
���α׷� ��:2���� �迭�� ���� �� ���
��¥:2025-09-22
*/


#include <stdio.h>

#define ROW 3
#define COL 2

int main(void)
{
	arr();

	return 0;
}

int arr()
{
	int data[ROW][COL];
	int i, j, k;

	for (i = 0, k = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			data[i][j] = ++k;
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%2d", data[i][j]);
		printf("\n");
	}

	printf("sizeof(data) = %d\n", sizeof(data));
	printf("sizeof(data[0]) = %d\n", sizeof(data[0]));
	printf("sizeof(data[0][0]) = %d\n", sizeof(data[0][0]));
	return 0;
}
