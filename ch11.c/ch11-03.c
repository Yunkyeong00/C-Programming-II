/*
학번:202511238
이름:조윤경
프로그램 명: 누산기 기능을 제공하는 accumulator 함수의 정의 및 호출
날짜:

*/

#include <stdio.h>

void accumulator(char op, int operand);

int main()
{
	while (1)
	{
		char op;
		int num;
		printf("연산자와 정수를 입력하세요.(0 입력시 종료): ");
		scanf("%c %d", &op, &num);
		if (op == '.' && num == 0)
			break;
		accumulator(op, num);
	}
	return 0;
}

void accumulator(char op, int operand)
{
	static int result = 0;
	switch (op)
	{
	case'+':
		result += operand;
		break;
	case'-':
		result -= operand;
		break;
	case'*':
		result *= operand;
		break;
	case'/':
		result /= operand;
		break;
	default:
		return ;
	}
	printf("%c %d = %d\n", op, operand, result);
}