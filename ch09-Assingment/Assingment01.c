/*
�й�:202511238
�̸�:������
���α׷� ��: ũ�Ⱑ 3�� double�� �迭�� ��� ������ �ּҸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �ּ� ���ϱ� �����ڸ� ������� ���ÿ�.
��¥:

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int StrCalculate(char* s);
void StrCount();

int main()
{
	StrCount();

	return 0;

}

void StrCount()
{
	char str[70];
	gets_s(str, sizeof(str));
	printf("���ڿ�? ");
	puts(str);


	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
			count++;
	}

	printf("���� ������ ����: %d", count);

}


