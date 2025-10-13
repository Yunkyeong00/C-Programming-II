/*
학번:202511238
이름:조윤경
프로그램 명: 
날짜:

*/

#include <stdio.h>

int main()
{
	test1();
}

int test1()
{
	int x = 10;
	test2(x);
	printf("test2 호출 후 x =%d\n", x);


	test3(&x);
	printf("test3호출 후 x =%d\n", x);

	return 0;
}

void test2(int x)
{
	x = 20;
}

void test3(int* p)
{
	*p = 20;
}