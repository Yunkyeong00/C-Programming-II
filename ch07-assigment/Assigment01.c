/*
학번:202511238
이름:조윤경
프로그램 명: 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다. 
		       크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다. 첫 번째 항의 값과
		       공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오
날짜:2025-09-21

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int a, int b);
void input();

int main()
{
	input();

	return 0;
}

void input()
{
	int first;
	int gongcha;

	printf("첫 번째 항? ");
	scanf("%d", &first);

	printf("공차? ");
	scanf("%d", &gongcha);

	print(first, gongcha);
}

void print(int a, int b)
{
	int i;
	int arr[10];

	for (i = 0; i < 10; i++)
	{
		arr[i] = a + i * b;
	}

	printf("등차수열: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

