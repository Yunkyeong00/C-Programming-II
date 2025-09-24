/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

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