/*
학번:202511238
이름:조윤경
프로그램 명: 
날짜:
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

	printf("첫 번째 항? ");
	scanf("%d", &hang);

	printf("공차? ");
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

	printf("등차수열: ");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
}


