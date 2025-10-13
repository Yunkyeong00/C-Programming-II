/*
학번:202511238
이름:조윤경
프로그램 명:문자열의 연결
날짜:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	str_tok();

	return 0;
}

void str_tok()
{
	char phone[] = "02-123-4567";
	char* p = NULL;

	p = strtok(phone, "-");
	printf("area code: %s\n", p);

	p = strtok(NULL, "-");
	printf("prefix:%s\n", p);

	p = strtok(NULL, "-");
	printf("line number: %s\n", p);

}
