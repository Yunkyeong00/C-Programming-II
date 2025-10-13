#include <stdio.h>
#include <math.h>

typedef struct point
{
	int x, y;
}POINT;

typedef struct line
{
	POINT start, end;
}LINE;

double get_length(const LINE* ln);
void LineStruct();

int main()
{
	LineStruct();

	return 0;

}

void LineStruct()
{
	LINE ln1 = { {10,20},{30,40} };

	printf("������ ������: (%d, %d)\n", ln1.start.x, ln1.start.y);
	printf("������ ����: (%d %d\n", ln1.end.x, ln1.end.y);

	printf("������ ����:%f\n", get_length(&ln1));
}

double get_length(const LINE* ln)
{
	int dx = ln->end.x - ln->start.x;
	int dy = ln->end.y - ln->start.y;
	return sqrt(dx * dx + dy * dy);
}