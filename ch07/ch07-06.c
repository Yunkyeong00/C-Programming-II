/*
학번:202511238
이름:조윤경
프로그램 명:잘못된 인덱스를 사용하는 경우
날짜:2025-09-22
*/


#include <stdio.h>

int main()
{
	wrong_index();

	return 0;

}

int wrong_index()
{
	int arr[5] = { 10,20,30,40,50 };
	int i;

	printf("arr= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("arr[5]=%d\n", arr[5]);
	arr[5] = 100;

	return 0;
}
