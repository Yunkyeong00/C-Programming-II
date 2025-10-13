#include <stdio.h>

void ArrPrint();

int main()
{
	ArrPrint();

	return 0;
}

void ArrPrint()
{
	double arr[10] = { 0.10 ,2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
	double *p = arr;
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%.2lf ", arr[i]);
	}

}