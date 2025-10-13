/*
학번:202511238
이름:조윤경
프로그램 명: 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오. 단, 주소 구하기 연산자를 사용하지 마시오.
날짜:

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
	printf("문자열? ");
	puts(str);


	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
			count++;
	}

	printf("공백 문자의 개수: %d", count);

}


