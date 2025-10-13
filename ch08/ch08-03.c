/*
학번:202511238
이름:조윤경
프로그램 명:

*/

#include <stdio.h>

int main()
{
	pointer_use();

	return 0;
}

int pointer_use()
{
	int x = 10;
	int* p = &x;

	printf("x=%d\n", x);
	printf("&x=%p\n", &x);

	printf(" p = %p\n", p);
	printf("*p=%d\n", *p);
	printf("&p=%p\n", &p);

	*p = 20;
	printf("*p=%d\n", *p);

	return 0;
}
