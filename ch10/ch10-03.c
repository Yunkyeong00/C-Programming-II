/*
�й�:202511238
�̸�:������
���α׷� ��:����ü ���� ���� �ʱ�ȭ�� ����
��¥:
*/

#include <stdio.h>
#include <string.h>

void StructReset();


struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

int main(void)
{
	StructReset();

	return 0;

}

void StructReset()
{
	struct contact ct = { "�輮��","01011112222",0 };
	struct contact ct1 = { "������","01012345678",1 };
	struct contact ct2 = ct1; //����ü ������ �ʱ�ȭ�� �� �ִ�.
	printf("ct1���� �ʱ�ȭ ���� ct2 =%s,%s,%d\n", ct.name, ct2.phone, ct2.ringtone);

	ct2 = ct;
	printf("ct�� ������ ���� ct2=%s,%s,%d\n", ct2.name, ct2.phone, ct2.ringtone);

}