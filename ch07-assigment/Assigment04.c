/*
   �й�:202511238
   �̸�:������
   ���α׷� ��:���������� ���� �׿� �׻� ������ ��(����)�� ���Ͽ� ������ �����̴�.
		       ũ�Ⱑ 10�� ������ �迭�� ���Ͽ� ���������� ���� ä����� �Ѵ�. ù ��° ���� ����
		       ����(common difference)�� �Է¹޾Ƽ� �迭�� ä��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
   ��¥:2025-09-22
   */

#include <stdio.h>

int BigIndexFound(int data[], int size);
int SmallIndexFound(int data[], int size);
void arr_print();

int main()
{
	arr_print();

	return 0;
}


//�Լ� �̸�:arr_print
//���:�迭�� ����ϰ�, �ּڰ��� �ִ��� �ε����� ���� ����Ѵ�
void arr_print(void)
{
	int data[] = { 23,45,62,12,99,83,23,50,72,37 };
	int index, i;

	printf("�迭: ");

	for (i = 0; i < 10; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	int big_index = BigIndexFound(data, 10);
	printf("�ִ�: �ε���=%d, ��=%d\n", big_index, data[big_index]);


	int small_index = SmallIndexFound(data, 10);
	printf("�ִ�: �ε���=%d, ��=%d", small_index, data[small_index]);

}

//�Լ� �̸�:BigIndexFound
//���: �ִ��� �ε����� ã�� ��ȯ�Ѵ�.
int BigIndexFound(int data[], int size)
{
	int big_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (data[i] > data[big_index])
		{
			big_index = i;

		}
	}

	return big_index;
}

//�Լ� �̸�:SmallIndexFound
//���: �迭���� �ּڰ��� �ε����� ã�� ��ȯ�Ѵ�
int SmallIndexFound(int data[10], int size)
{
	int small_index = 0;

	for (int i = 0; i < 10; i++)
	{
		if (data[i] < data[small_index])
		{
			small_index = i;

		}
		return small_index;
	}
}