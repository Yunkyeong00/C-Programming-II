/*
   학번:202511238
   이름:조윤경
   프로그램 명:등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
		       크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다. 첫 번째 항의 값과
		       공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오
   날짜:2025-09-22
   */

#include <stdio.h>

int BigIndexFound(int data[], int size);
int SmallIndexFound(int data[], int size);
void arr_print();

int main()
{
	arr_print();

	return 0;
}


//함수 이름:arr_print
//기능:배열을 출력하고, 최솟값과 최댓값의 인덱스와 값을 출력한다
void arr_print(void)
{
	int data[] = { 23,45,62,12,99,83,23,50,72,37 };
	int index, i;

	printf("배열: ");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	int big_index = BigIndexFound(data, 10);
	printf("최댓값: 인덱스=%d, 값=%d\n", big_index, data[big_index]);


	int small_index = SmallIndexFound(data, 10);
	printf("최댓값: 인덱스=%d, 값=%d", small_index, data[small_index]);

}

//함수 이름:BigIndexFound
//기능: 최댓값의 인덱스를 찾아 반환한다.
int BigIndexFound(int data[], int size)
{
	int big_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (data[i] > data[big_index])
		{
			big_index = i;

		}
	}

	return big_index;
}

//함수 이름:SmallIndexFound
//기능: 배열에서 최솟값의 인덱스를 찾아 반환한다
int SmallIndexFound(int data[10], int size)
{
	int small_index = 0;

	for (int i = 0; i < 10; i++)
	{
		if (data[i] < data[small_index])
		{
			small_index = i;

		}
		return small_index;
	}
}