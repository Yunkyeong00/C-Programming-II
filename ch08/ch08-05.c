/*
�й�:202511238
�̸�:������
���α׷� ��: const �������� �ǹ�
��¥:

*/

#include <stdio.h>

int main()
{
	pointer_mean();

	return 0;
}

void pointer_mean()
{
	int a = 10, b = 20;

	const int* p1 = &a;
	int* const p2 = &a;
	const int* const p3 = &a;

	printf("*p1=%d\n", *p1);
	p1 = &b;
	printf("*p=%d\n", *p1);//�ּ�, �� ���� ����

	*p2 = 100;
	printf("p2=%d\n", *p2);//�ּ� x //�� O


	printf("*p3=%d\n", *p3);//�ּ� ���� �ȵ�, ���� ���� �ȵ�

}