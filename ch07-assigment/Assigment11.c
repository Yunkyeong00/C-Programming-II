


#include <stdio.h>
#define ROW 5
#define COL 4

int score_arr();


int main()
{
	score_arr();

	return 0;
}

int score_arr()
{
	int score[ROW][COL] = {
		{28,28,26,9},
		{30,27,30,10},
		{25,26,24,8},
		{18,22,24,5},
		{24,30,30,10}
	};

	int i, j;
	int sum[ROW];

	for (i = 0; i < ROW; i++)
	{
		sum[i] = 0;
		for (j = 0; j < COL; j++)
		{
			sum[i] += score[i][j];
		}
	}

	for (i = 0; i < ROW; i++)
	{
		printf("ÇÐ»ý %d¹ø:", i);
		for (j = 0; j < COL; j++)
		{
			printf("%3d", score[i][j]);
		}
		printf(" = %d\n", sum[i]);
	}

	return 0;

}