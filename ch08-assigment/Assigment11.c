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