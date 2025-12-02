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
        }


        for (j = 0; j < num; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}
