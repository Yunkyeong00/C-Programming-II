/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

*/

#include <stdio.h>

int main()
{
	pointer_arr();

	return 0;
}

int pointer_arr()
{
	double arr[3];
	double *p = arr;
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("x[%d]의 주소:%X\n",i,arr+i);
	}
}