/*
�й�:202511238
�̸�:������
���α׷� ��: 
��¥:

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
	printf("test2 ȣ�� �� x =%d\n", x);


	test3(&x);
	printf("test3ȣ�� �� x =%d\n", x);

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