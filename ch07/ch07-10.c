
/*
�й�:202511238
�̸�:������
���α׷� ��:Ž���� ����, ���и� Ȯ���ϴ� ���
��¥:2025-09-22
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	arr_exploration();

	return 0;

}

int arr_exploration()
{
	int data[] = { 78,34,52,15,63,15,25 };
	int size;
	int key, i;
	int found;

	size = sizeof(data) / sizeof(data[0]);

	printf("arr= ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	printf("ã�� ��(Ű)? ");
	scanf("%d", &key);

	found = 0;
	for (i = 0; i < size; i++)
	{
		if (data[i] == key)
		{
			found = 1;
			break;
		}
	}

	if (found == 1)
		printf("ã�� ������ �ε���: %d\n", i);

	else
		printf("Ž�� ����\n");

	return 0;
}
