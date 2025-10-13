/*
학번:202511238
이름:조윤경
프로그램 명:
날짜:

*/
#include <stdio.h>

void pointer_use();


int main()
{
	pointer_use();

	return 0;
}

void pointer_use()
{
	int a, b, c, d, e;
	int *arr[5] = { &a, &b, &c, &d, &e };
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		*arr[i] = i;
		printf("%d ", *arr[i]);
	}
	printf("\n");

	return 0;
}