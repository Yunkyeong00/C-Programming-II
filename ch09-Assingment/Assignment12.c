#include <stdio.h>
#include <string.h>

void input();
void rotate(char str[], int n);

int main()
{
	input();


	return 0;
}

void input()
{
	char str[100];
	int n;
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));
	printf("�̵��� ���� ��? ");
	scanf("%d", &n);

	rotate(str, n);
}

void rotate(char str[], int n)
{
	int len = strlen(str);
	char result[100];
	int i, j;

	for (i = 0; i < n; i++)
	{
		result[i] = str[len - n + i];
	}

	for (j = 0; j < len - n; j++)
	{
		result[n + j] = str[j];
	}

	result[len] = '\0';

	printf("ȸ���� ���ڿ�: %s\n", result);
}