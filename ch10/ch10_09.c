/*
학번:202511238
이름:조윤경
프로그램 명:구조체의 정의
날짜:
*/

#include <stdio.h>


typedef struct point
{
	int x, y;
}POINT;

void struct_send();
void print_point(POINT pt);

void print_point(POINT pt);

int main(void)
{
	struct_send();

	return 0;
}

void struct_send()
{
	POINT arr[] =
	{
		{0,0},{10,10},{20,20},{30,30},{40,40},
	};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i;

	for (i = 0; i < sz; i++)
	{
		print_point(arr[i]);
		printf(" ");
	}
	printf("\n");
}

void print_point(POINT pt)
{
	printf("(%d, %d)", pt.x, pt.y);
}