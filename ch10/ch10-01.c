/*
�й�:202511238
�̸�:������
���α׷� ��:����ü�� ����
��¥:
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
	printf("contact ����ü�� ũ��: %d\n", sizeof(struct contact));
	//printf("contact ����ü�� ũ��=%d\n",sizeof(contact)); //������ ����
}

void test()
{
	struct contact c1;
}