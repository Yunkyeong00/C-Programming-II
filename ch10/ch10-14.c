#include <stdio.h>

enum direction { NORTH, SOUTH, EAST, WEST };
void EnumDefine();


int main()
{
	EnumDefine();

	return 0;

}

void EnumDefine()
{
	enum direction d1 = NORTH;

	d1 = EAST;
	printf("d1=%d\n", d1);

	switch (d1)
	{
	case NORTH:
		printf("�������� �̵��մϴ�.\n");
		break;
	case SOUTH:
		printf("�������� �̵��մϴ�.\n");
		break;
	case EAST:
		printf("�������� �̵��մϴ�.\n");
		break;
	case WEST:
		printf("�������� �̵��մϴ�.\n");
		break;
	}
}