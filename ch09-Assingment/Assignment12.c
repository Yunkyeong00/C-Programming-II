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
	printf("문자열? ");
	gets_s(str, sizeof(str));
	printf("이동할 글자 수? ");
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

	printf("회전된 문자열: %s\n", result);
}