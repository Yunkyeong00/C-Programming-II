/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

*/

#include <stdio.h>

void ArrPrint();

int main()
{
	ArrPrint();

	return 0;
}

void ArrPrint()
{
	double arr[10] = { 0.10 ,2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
	double *p = arr;
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%.2lf ", arr[i]);
	}

}