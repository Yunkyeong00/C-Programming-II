/*
�й�:202511238
�̸�:������
���α׷� ��:���ڿ��� ����
��¥:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int swap_string(char* lhs, char* rhs, int size);
void StrArray();


#define MAX 5
#define BUF_SZ 30

int main(void)
{
	StrArray();

	return 0;
}

void StrArray()
{
	char books[MAX][BUF_SZ] = 
	{
	"Wonder",
	"Me vefore you",
	"The hunger games",
	"Twilight",
	"Harry potter"
	};
	int i, j;
	int index;

	puts("<< ���� �� >>");
	for (i = 0; i < MAX; i++)
		puts(books[i]);

	for (i = 0; i < MAX-1; i++)
	{
		index = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (strcmp(books[index], books[j]) > 0)
				index = j;
		}
		if (i != index)
		{
			swap_string(books[index], books[i], BUF_SZ);
		}
	}

	puts("<< ���� �� >>");
	for (i = 0; i < MAX; i++)
		puts(books[i]);
}

int swap_string(char* lhs, char* rhs, int size)
{
	int lhs_len = strlen(lhs);
	int rhs_len = strlen(rhs);
	char temp[BUF_SZ] = "";

	if (lhs_len + 1 > size || rhs_len + 1 > size)
		return 0;

	strcpy(temp, lhs);
	strcpy(lhs, rhs);
	strcpy(rhs, temp);

	return 1;
}