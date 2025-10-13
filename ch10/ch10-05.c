/*
학번:202511238
이름:조윤경
프로그램 명:구조체 변수의 비교
날짜:
*/

#include <stdio.h>
#include <string.h>

void StructArr();


typedef struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
}CONTACT;

int main(void)
{
	StructArr();

	return 0;

 }

void StructArr()
{
	CONTACT arr[] =
	{
		{"김석진","01011112222",0},
		{"전정국","01012345678",1},
		{"박지민","01077778888",2}
	};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;

	printf("이름   전화번호   벨\n");
	for (i = 0; i < size; i++)
	{
		printf("%6s %11s %d\n", arr[i].name, arr[i].phone, arr[i].ringtone);
	}
}