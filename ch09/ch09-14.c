/*
�й�:202511238
�̸�:������
���α׷� ��:���ڿ��� ����
��¥:

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void PointerArrEx();

int main()
{
	PointerArrEx();

	return 0;
}

void PointerArrEx()
{
	const char* str_menu[] = {
		"������",
		"�� ������Ʈ",
		"������Ʈ ����",
		"�ַ�� ����",
		"����� ����"
	};

	int sz_menu = sizeof(str_menu) / sizeof(str_menu[0]);
	int menu;

	while (1)
	{
		int i;
		for (i = 0; i < sz_menu; i++)
			printf("%d.%s\n", i, str_menu[i]);

		printf("�޴� ����? ");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		else if (menu > 0 && menu < sz_menu)
			printf("�߸� �����߽��ϴ�.\n\n");
	}

}
