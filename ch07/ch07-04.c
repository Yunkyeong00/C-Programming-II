/*
학번:202511238
이름:조윤경
프로그램 명:배열의 크기보다 초기값을 적게 지정하는 경우
날짜:2025-09-22
*/

#include <stdio.h>

int main()
{
	arr();

	return 0;

}

int arr()
{
	int amount[5] = { 1,1,5 };
	int price[5] = { 0 };
	int i;

	printf("amount= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", amount[i]);
	}
	printf("\n");

	printf("price= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", price[i]);
	}
	printf("\n");

	return 0;

}