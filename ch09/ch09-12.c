/*
�й�:202511238
�̸�:������
���α׷� ��:���ڿ��� ����
��¥:

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
		printf("å ����:%s\n", books[i]);

	for (i = 0; i < 5; i++)
	{
		if (islower(books[i][0]))
			books[i][0] = toupper(books[i][0]);
	}

	puts("<< ���� �� >>");
	for (i = 0; i < 5; i++)
		printf("å ����:%s\n", books[i]);

}