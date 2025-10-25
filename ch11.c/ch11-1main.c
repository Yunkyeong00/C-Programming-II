#include <stdio.h>

void test_global(void);

extern int global;

int main(void)
{
	test_global();
	printf("global=%d\n", global);

	return 0;
}