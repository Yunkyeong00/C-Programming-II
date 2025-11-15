#include <stdio.h>

int main()
{
	int a, b;
	char op;
	
	while (1)
	{
		printf("수식? ");
		if (scanf("%d %c %d", &a, &op, &b) < 3)
		{
			printf("<정수><연산자><정수> 형태로 입력하세요\n");
			while (getchar()!='\n'){}
			continue;
		}
		if()
	}
}