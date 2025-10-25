/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input();
void get_rect_info(int width,int length,int *area, int * circumference);

int main()
{
	input();

	return 0;
}

int input()
{
	int width, length;
	int area, circumference;

	printf("가로? ");
	scanf("%d", &width);

	printf("세로? ");
	scanf("%d", &length);

	get_rect_info(width, length, &area, &circumference);

	printf("넓이: %d, 둘레:%d", area, circumference);
	

}

void get_rect_info(int x,int y,int *area,int * circumference)
{

	*area = x * y;
	*circumference = 2 * (x+y);


}