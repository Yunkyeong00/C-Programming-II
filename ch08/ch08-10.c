/*
학번:202511238
이름:조윤경
프로그램 명:
날짜:

*/

#include <stdio.h>

void difference_pointer();

int main()
{
	difference_pointer();

	return 0;
}

void difference_pointer()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5];
	int* p = x;
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	p = y;
	for (i = 0; i < 5; i++)
	{
		p[i] = x[i];
	}


	for (i = 0; i < 5; i++, p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
	return 0;


}