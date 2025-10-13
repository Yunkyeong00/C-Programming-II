/*
학번:202511238
이름:조윤경
프로그램 명: 수학에서 집합은 다중집합과 다르게 원소의 중복을 허용하지 않는다. 최대 10개의
             정수형 원소를 저장할 수 있는 집합을 구현하시오. 정수를 입력받아 집합의 원소로
			 추가하고, 그 때마다 집합의 원소들을 출력하시오.
날짜:2025-09-21

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int icandoit();

int main()
{
    icandoit();

    return 0;
}

int icandoit()
{
    int arr[10];
    int test = 0;// 
    int num = 0; //
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf("배열에 추가할 원소?");
        scanf("%d", &test); //

        for (j = 0; j < num; j++)
        {
            if (arr[j] == test) //
            {

                printf("해당 원소가 이미 인덱스 [%d]에 존재합니다.\n", j);
                break;
            }
        }
        if (j == num) {
            arr[num] = test;
            num++;
        }//


        for (j = 0; j < num; j++)//
            printf("%d ", arr[j]);
        printf("\n");
    }
}
