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

void gap_str();
int count_space(const char* s);



int main(void)
{
	gap_str();

	return 0;
}

void gap_str()
{
	char str[64] = "this program\ttests const pointer to string\n";

	puts(str);
	printf("공백 문자의 개수: %d\n", count_space(str));

}

int count_space(const char *s)
{
	int count = 0;
	while (s[0] != '\0')
	{
		if (isspace(s[0]))
			count++;
		s++;
	}
	return count;
}
