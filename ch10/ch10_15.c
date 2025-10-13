#include <stdio.h>

union test
{
	int i;
	char c;
	short s;
};

void UnionDefine();

int main(void)
{
	UnionDefine();

	return 0;
}

void UnionDefine()
{
	union test t1 = { 0x12345678 };

	printf("sizeof(union test)=%d\n", sizeof(union test));

	printf("t1.i狼 林家=%p\n", &t1.i);
	printf("t1.c狼 林家=%p\n", &t1.c);
	printf("t1.s狼 林家=%p\n", &t1.s);

	printf("t1.i狼 林家=%x\n", t1.i);
	printf("t1.c狼 林家=%x\n", t1.c);
	printf("t1.s狼 林家=%x\n", t1.s);


}