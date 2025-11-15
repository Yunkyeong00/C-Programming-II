/*
학번:202511238
이름:조윤경
프로그램 명:정수의 개수 N을 입력받아 int가 N개 들어갈 수 있는 동적 메모리를 할당받는다. 
             이 배열에 임의의 정수를 N개 생성해서 채운 다음 텍스트 파이로가 2진 파일로 각각 저장하는 프로그램을 작성하시오. 2진 파일로 저장할 때는 N개을 먼저 저장하고, 배열의 내용을 저장하시오. 저장된 파일을 문서 편집기에서 열어서 내용을 확인해보고 파일의 크기도 비교해본다.

날짜:2025.11.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>     

void MakeFile();


int main() 
{
    MakeFile();

    return 0;

}

void MakeFile()
{
    int N;
    int* arr;
    char name[100];
    char txtname[110];
    char datname[110];

    printf("정수의 개수? ");
    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int) * N);

    if (arr == NULL)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("파일명? ");
    scanf("%s", name);

    sprintf(txtname, "%s.txt", name);
    sprintf(datname, "%s.dat", name);

    FILE* ftxt = fopen(txtname, "w");
    if (ftxt == NULL)
    {
        printf("텍스트 파일을 만들 수 없습니다.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        fprintf(ftxt, "%d\n", arr[i]);
    }
    fclose(ftxt);

    FILE* fdat = fopen(datname, "wb");
    if (fdat == NULL)
    {
        printf("이진 파일을 만들 수 없습니다.\n");
        free(arr);
        return 1;
    }

    fwrite(&N, sizeof(int), 1, fdat);

    fwrite(arr, sizeof(int), N, fdat);

    fclose(fdat);

    free(arr);

    printf("%s와 %s를 생성했습니다.\n", txtname, datname);
}
