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

void StructPointerUse();


typedef struct contact
{
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;

}CONTACT;

int main(void)
{
	StructPointerUse();

	return 0;
}

void StructPointerUse()
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
	CONTACT* recent = NULL;

	while (1)
	{
		printf("�̸�(. �Է� �� ����)? ");
		scanf("%s", name);
		if (strcmp(name,".") == 0)  //name�� "."�̸� while�� Ż��
			break;

		index = -1; //��ã�� ���·� ����
		for (i = 0; i < size; i++)
		{
			if (strcmp(arr[i].name, name) == 0)
			{
				index = i;
				break;  //for�� ��������
			}
		}
		if (index >= 0)
		{
			printf("%s�� ��ȭ��ȣ %s�� ��ȭ�� �̴ϴ�....\n", arr[index].name, arr[index].phone);
			recent = &arr[index];
		}
		else
		{
			printf("����ó�� ã�� �� �����ϴ�.\n");
		}
	}
	if (recent)
		printf("�ֱ� ��ȭ: %s %s\n", recent->name, recent->phone);
}