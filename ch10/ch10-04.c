/*
학번:202511238
이름:조윤경
프로그램 명:구조체 변수의 비교
날짜:
*/
#include <stdio.h>
#include <string.h>

void StructCompare();


struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

int main()
{
	StructCompare();

	return 0;
}

void StructCompare()
{
	struct contact ct1 = { "전정국","01012345678",1 };
	struct contact ct2 = ct1;

	if (strcmp(ct1.name, ct2.name) == 0 && strcmp(ct1.phone, ct2.phone) == 0 && ct1.ringtone == ct2.ringtone)
		printf("ct1과 ct2의 값이 같습니다.\n");
	else
		printf("ct1과 ct2의 값이 같지 않습니다.\n");

}