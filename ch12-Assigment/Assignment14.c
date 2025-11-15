/*
학번:202511238
이름:조윤경
프로그램 명:13번 프로그램을 실행해서 크기가 다른 2진 파일을 2개 생성한 
            다음 두 파일을 읽어서 하나의 int배열을 생성한 다음 정렬 후에 다시 2진 파일로 저장하는 프로그램을 작성하시오
날짜:2025.11.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readFile(char* filename, int** arr, int* size);
void writeFile(char* filename, int* arr, int size);
void Array(int* arr, int size);
void STATRFILE();


int main() 
{
    STATRFILE();

    return 0;
}

void STATRFILE()
{
    char file1[100], file2[100], outfile[100];
    int* arr1, * arr2;
    int n1, n2;

    printf("첫 번째 파일명? ");
    scanf("%s", file1);

    readFile(file1, &arr1, &n1);
    printf("정수 %d개를 읽었습니다.\n", n1);

    printf("두 번째 파일명? ");
    scanf("%s", file2);

    readFile(file2, &arr2, &n2);
    printf("정수 %d개의 파일을 읽었습니다.\n", n2);

    int total = n1 + n2;
    int* merged = (int*)malloc(sizeof(int) * total);

    for (int i = 0; i < n1; i++) merged[i] = arr1[i];
    for (int i = 0; i < n2; i++) merged[n1 + i] = arr2[i];

    Array(merged, total);

    printf("저장할 파일명? ");
    scanf("%s", outfile);

    writeFile(outfile, merged, total);
    printf("정수 %d개를 저장했습니다.\n", total);

    free(arr1);
    free(arr2);
    free(merged);

  
}


void readFile(char* filename, int** arr, int* size) 
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        exit(1);
    }

    fread(size, sizeof(int), 1, fp);

    *arr = (int*)malloc(sizeof(int) * (*size));

    fread(*arr, sizeof(int), *size, fp);

    fclose(fp);
}


void writeFile(char* filename, int* arr, int size) 
{
    FILE* fp = fopen(filename, "wb");

    if (fp == NULL) 
    {
        printf("파일을 생성할 수 없습니다.\n");
        exit(1);
    }

    fwrite(&size, sizeof(int), 1, fp);
    fwrite(arr, sizeof(int), size, fp);

    fclose(fp);
}

void Array(int* arr, int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
