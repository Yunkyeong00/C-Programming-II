/*
�й�:202511238
�̸�:������
���α׷� ��: 
��¥:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ArrPrint();


int main()
{
	ArrPrint();

	return 0;
}

void ArrPrint()
{
	int hang, common_difference;

	printf("ù ��° ��? ");
	scanf("%d", &hang);

	printf("����? ");
	scanf("%d", &common_difference);

	arith_seq(hang,common_difference);

}

int arith_seq(int hang,int common_difference)
{
	int i;
	int arr[10];

	for (i = 0; i < 10; i++)
	{
		arr[i] = hang + i * common_difference;
	}

	printf("��������: ");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
}


