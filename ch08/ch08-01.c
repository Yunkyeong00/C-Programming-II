/*
�й�:202511238
�̸�:������
���α׷� ��: ũ�Ⱑ 3�� double�� �迭�� ��� ������ �ּҸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ּ� ���ϱ� �����ڸ� ������� ���ÿ�.
��¥:

*/

#include <stdio.h>

int main()
{
	pointer_bite();

	return 0;
}

void pointer_bite()
{
	int* pi;
	double* pd;
	char* pc;

	printf("sizeof(pi)=%zd\n", sizeof(pi));
	printf("sizeof(pi)=%zd\n", sizeof(pd));
	printf("sizeof(pi)=%zd\n", sizeof(pc));

	printf("sizeof(int*)=%zd\n", sizeof(int*));
	printf("sizeof(double*)=%zd\n", sizeof(double*));
	printf("sizeof(char*)=%zd\n", sizeof(char*));


}