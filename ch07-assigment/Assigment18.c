/*
�й�:202511238
�̸�:������
���α׷� ��: ���п��� ������ �������հ� �ٸ��� ������ �ߺ��� ������� �ʴ´�. �ִ� 10����
             ������ ���Ҹ� ������ �� �ִ� ������ �����Ͻÿ�. ������ �Է¹޾� ������ ���ҷ�
			 �߰��ϰ�, �� ������ ������ ���ҵ��� ����Ͻÿ�.
��¥:2025-09-21

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
        printf("�迭�� �߰��� ����?");
        scanf("%d", &test); //

        for (j = 0; j < num; j++)
        {
            if (arr[j] == test) //
            {

                printf("�ش� ���Ұ� �̹� �ε��� [%d]�� �����մϴ�.\n", j);
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
