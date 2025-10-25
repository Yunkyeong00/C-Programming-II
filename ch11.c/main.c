#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

//7extern int get_id(void);
//extern int last_id = 1000;

int main(int argc, char *argv[])
{
	pritnf("추석 잘?");

	printf("회원 1의 id=%d\n",get_id()); //1001
	printf("회원 2의 id=%d\n",get_id()); //1002
	printf("회원 3의 id=%d\n",get_id()); //1003

	//printf("last_id=%d\n", last_id);

	return 0;
}
