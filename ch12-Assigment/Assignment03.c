/*
학번:202511238
이름:조윤경
프로그램 명:텍스트 파일의 이름을 입력받아서 파일 내의 문자들에 대하여 영문자의 개수를 문자별로 세서 출력하는 프로그램을 작성하시오. 문자의 개수를 셀 때는 대소문자를 구분하지 않는다.
날짜:2025.11.08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void FilePrint();
void COUNT(FILE* fp, int count[]);
void PrintResult(int count[]);


int main()
{
	FilePrint();

	return 0;
}

void FilePrint()
{
	FILE* fp;
	char filename[100];
	int count[26] = { 0 };


	printf("파일명? ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}
	COUNT(fp, count);
	printf("\n");

	fclose(fp);
}

void COUNT(FILE* fp, int count[])
{
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
		c = tolower(c);
		if (c >= 'a' && c <= 'z')
		{
			count[c - 'a']++;
		}
	}
	PrintResult(count);

}

void PrintResult(int count[])
{
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > 0)
		{
			printf("%c:%d ", 'a' + i, count[i]);
			if (i == 12)
			{
				printf("\n");
			}
		}
	}
}
