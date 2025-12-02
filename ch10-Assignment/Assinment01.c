#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count();


int cont_digits(int n) 
{
    if (n == 0)
        return 0; 

    return 1 + cont_digits(n / 10);
}

int main(void) 
{
   
    count();
    return 0;
}

void count()
{
    while (1)
    {
        int num;

        printf("정수? ");
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
       
        if (num < 0)
            num = -num;

        if (num == 0)
            printf("숫자의 개수: 1\n");
        else
            printf("숫자의 개수: %d\n", cont_digits(num));
    }
}
