/*
�й�:202511238
�̸�:������
���α׷� ��: ���������� ���� �׿� �׻� ������ ��(����)�� ���Ͽ� ������ �����̴�. 
		       ũ�Ⱑ 10�� ������ �迭�� ���Ͽ� ���������� ���� ä����� �Ѵ�. ù ��° ���� ����
		       ����(common difference)�� �Է¹޾Ƽ� �迭�� ä��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
��¥:2025-09-21

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int a, int b);
void input();

int main()
{
	input();

	return 0;
}

void input()
{
	int first;
	int gongcha;

	printf("ù ��° ��? ");
	scanf("%d", &first);

	printf("����? ");
	scanf("%d", &gongcha);

	print(first, gongcha);
}

void print(int a, int b)
{
	int i;
	int arr[10];

	for (i = 0; i < 10; i++)
	{
		arr[i] = a + i * b;
	}

	printf("��������: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

