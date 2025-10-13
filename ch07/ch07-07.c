/*
학번:202511238
이름:조윤경
프로그램 명:배열의 복사
날짜:2025-09-22
*/

#include <stdio.h>

int main()
{
	arr_copy();

	return 0;

}

int arr_copy()
{
	int x[5] = { 10,20,30,40,50 };
	int y[5] = { 0 };

	int i;

	//y=x;  //배열을 다른 배열에 대입하면 컴파일 에러
	for (i = 0; i < 5; i++)
	{
		y[i] = x[i];
	}

	printf("y= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", y[i]);
	}
	printf("\n");

	reuturn 0;
}
