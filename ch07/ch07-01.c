/*
�й�:
�̸�:
���α׷� ��:�迭�� ����Ʈ ũ��� ũ�� ���ϱ�
��¥:
*/

#include <stdio.h>

int main(void)
{
	arr_bite();

	return 0;
}

int arr_bite(void)
{
	int arr[5];
	int byte_size = 0;
	int size = 0;
	int i;

	byte_size = sizeof(arr);
	printf("�迭�� ����Ʈ ũ��:%d", bite_size);

	size = sizeof(arr) / sizeof(arr[0]);
	printf("�迭�� ũ��:%d\n", size);

	for (i = 0; i < size; i++)
		arr[i] = 0;

	return 0;

}

