#include <stdio.h>

typedef struct date
{
	unsigned short year : 7;
	unsigned short month : 4;
	unsigned short day : 5;
}DATE;

void bitfield();


int main(void)
{
	bitfield();

	return 0;

}

void bitfield()
{
	DATE dday;
	dday.year = 22;
	dday.month = 11;
	dday.day = 30;

	printf("DATEÀÇ Å©±â=%d\n", sizeof(DATE));
	printf("%d/%d/%d\n", dday.year, dday.month, dday.day);
}