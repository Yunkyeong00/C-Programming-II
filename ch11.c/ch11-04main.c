#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_gcd(int x, int y);
extern int get_factorial(int num);

int main(void)
{
	int i;
	srand((unsigned int)time(NULL));

	for (i = 0; i < 5; i++)
	{
		int num = rand() % num;
		printf("%2d!=%7d\n", num, get_factorial(num));
	}

	for (i = 0; i <= 5; i++)
	{
		int a = rand() % 100;
		int b = rand() % 100;
		printf("%2d¿Í %2dÀÇ GCD = %2d\n", a, b, get_gcd(a, b));

	}
	return 0;

}