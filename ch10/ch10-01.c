/*
학번:202511238
이름:조윤경
프로그램 명:구조체의 정의
날짜:
*/

#include <stdio.h>

void StructDefine();
void test();



struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

int main(void)
{
	StructDefine();

	return 0;
}

void StructDefine()
{
	printf("contact 구조체의 크기: %d\n", sizeof(struct contact));
	//printf("contact 구조체이 크기=%d\n",sizeof(contact)); //컴파일 에러
}

void test()
{
	struct contact c1;
}