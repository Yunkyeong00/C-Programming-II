#include <stdio.h>
#include <string.h>
#include <ctype.h>

void input();
int strcmp_ic(char str1[], char str2[]);

int main()
{
	input();

	return 0;

}

void input()
{
	char str1[100], str2[100];
	printf("ù ��° ���ڿ� ? ");
	gets_s(str1, sizeof(str1));
	printf("�� ��° ���ڿ� ? ");
	gets_s(str2, sizeof(str2));

	int result=strcmp_ic(str1, str2);

	if(result==0)
		printf("%s�� %s�� �����ϴ�.", str1, str2);
	else
		printf("%s�� %s�� ���� �ʽ��ϴ�.", str1, str2);



}

int strcmp_ic(char str1[], char str2[])
{
	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (tolower(str1[i]) != tolower(str2[i]))
		{
			break;
		}
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 0;
	}
	else if(tolower(str1[i]) > tolower(str2[i]))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}