/*
학번:202511238
이름:조윤경
프로그램 명:
날짜:

*/

#include <stdio.h>

void arr_plus();

int main()
{
	arr_plus();

	return 0;
}

void arr_plus()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = &arr[0];

	int i;

	for (i = 0; i < 5; i++, p++)
	{
		printf("p=%p, ", p);
		printf("*p=%d\n", *p);
	}
}
