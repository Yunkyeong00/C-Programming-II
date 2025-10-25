/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

*/

#include <stdio.h>

int main()
{
	first();

	return 0;
}

int first()
{
	int arr[10] = { 23,45,62,12,99,83,23,50,72,37 };

	printf("배열: ");
	for (int i=0; i < 10; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");

	int big_index, small_index;
	get_min_max(arr,10,&small_index,&big_index);

	printf("최댓값:%d\n", big_index);
	printf("최솟값:%d", small_index);
}

int get_min_max(int arr[], int size, int*b_index,int*s_index)
{
	*b_index = 0;
	*s_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[*b_index])
		{
			*b_index = i;

		}

		if (arr[i] < arr[*s_index])
		{
			*s_index = i;

		}
	}


	return s_index, b_index;
}
