/*
학번:202511238
이름:조윤경
프로그램 명:static 지역 변수
날짜:

*/

#include <stdio.h>

void test_static(void)
{
	int local = 0;
	static int s_local = 0;

	printf("local=%d, ", local++);
	printf("s_local= %d\n", s_local++);
}

int main(void)
{
	int i = 0;
	for (i = 0; i < 5; i++)
		test_static();

	return 0;
}