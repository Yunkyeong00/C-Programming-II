/*
�й�:202511238
�̸�:������
���α׷� ��:����ü ������ ��
��¥:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void StructPointer();

#define STR_SIZE 20

typedef struct contact
{
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;
}CONTACT;

int main(void)
{
	StructPointer();

	return 0;

}

void StructPointer()
{
	CONTACT ct = { "�輮��","01011112222",0 };
	CONTACT* p = &ct;
	p->ringtone = 5;
	strcpy(p->phone, "01011112223");
	printf("�̸�:%s\n", p->name);
	printf("��ȭ��ȣ:%s\n", p->phone);
	printf("���Ҹ�:%d\n", p->ringtone);
}