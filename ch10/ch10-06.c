/*
�й�:202511238
�̸�:������
���α׷� ��:����ü ������ ��
��¥:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STR_SIZE 20

void SrtuctArrSearch();


typedef struct contact
{
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;
}CONTACT;


int main(void)
{
	SrtuctArrSearch();

	return 0;
}

void SrtuctArrSearch()
{
	CONTACT arr[] =
	{
		{"�輮��","01011112222",0},
		{"������","01012345678",1},
		{"������","01077778888",2},
		{"�賲��","01055556666",9},
		{"������","01011223344",5},
		{"��ȣ��","01055556666",7},
		{"������","01048648644",3}
	};

	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	char name[STR_SIZE];
	int index;

	printf("�̸�? ");
	scanf("%s", name);

	index = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, name) == 0)
		{
			index = i;
			break;
		}
	}
	if (index >= 0)
	{
		printf("%s�� ��ȭ��ȣ:%s\n", arr[index].name, arr[index].phone);
	}
	else
	{
		printf("����ó�� ã�� �� �����ϴ�.\n");
	}
}
