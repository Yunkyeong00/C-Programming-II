/*
학번:202511238
이름:조윤경
프로그램 명:
날짜:

*/

#include <stdio.h>

void pointer_arr();


int main()
{
	pointer_arr();

	return 0;

}

void pointer_arr()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	int i;

	for (i = 0; i < 5; i++)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}

}