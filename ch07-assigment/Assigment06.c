/*
   학번:202511238
   이름:조윤경
   프로그램 명:
   날짜:2025-09-22
   */

#include <stdio.h>

int main()
{
	print_arr();

	return 0;
}

int print_arr()
{
	double arr[] = { 1.2,3.1,4.3,4.5,6.7,2.3,8.7,9.5,2.3,5.8 };

	printf("배열: ");
	origin_arr(arr, 10);
	printf("\n");
	printf("역순: ");
	reverse_arr(arr, 10);


}

int origin_arr(double arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%.1lf ", arr[i]);
}

int reverse_arr(double arr[], int size)
{
	int i;
	for (i = size - 1; i >= 0; i--)
	{
		printf("%.1lf ", arr[i]);
	}
}

