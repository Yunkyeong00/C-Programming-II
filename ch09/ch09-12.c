/*
학번:202511238
이름:조윤경
프로그램 명:문자열의 연결
날짜:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void twoarr();

int main(void)
{
	twoarr();

	return 0;
}

void twoarr()
{
	char books[5][30] = {
		"wonder",
		"me vefore you",
		"the hunger games",
		"twilight",
		"harry potter"
	};
	int i = 0;

	for (i = 0; i < 5; i++)
		printf("책 제목:%s\n", books[i]);

	for (i = 0; i < 5; i++)
	{
		if (islower(books[i][0]))
			books[i][0] = toupper(books[i][0]);
	}

	puts("<< 변경 후 >>");
	for (i = 0; i < 5; i++)
		printf("책 제목:%s\n", books[i]);

}