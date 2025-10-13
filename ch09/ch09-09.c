/*
학번:202511238
이름:조윤경
프로그램 명:문자열의 연결
날짜:

*/

#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void pointer_arr();


int main()
{
	pointer_arr();

	return 0;
}

void pointer_arr()
{
	char str[64] = "";
	char* p = str;

	strcpy(p, "test string");

	if (islower(p[0]))
		p[0] = toupper(p[0]);

	p = strchr(p,' ');

	if (islower(p[1]))
		p[1] = toupper(p[1]);
	puts(str);

}
