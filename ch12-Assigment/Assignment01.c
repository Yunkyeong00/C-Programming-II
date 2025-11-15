/*
학번:202511238
이름:조윤경
프로그램 명:텍스트 파일의 이름을 입력받아서 파일의 내용을 라인 번호와 함께 출력하는 프로그램을 작성하시오

날짜:2025.11.08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FilePrint();


int main()
{
	FilePrint();

	return 0;
}

int FilePrint()
{
	FILE* fp;
	char filename[100];
	char line[300];

	printf("파일명? ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	for (int num = 1; fgets(line, sizeof(line), fp) != NULL; num++)
	{
		printf("%d: %s", num, line);
	}

	fclose(fp);
	return 0;
}
