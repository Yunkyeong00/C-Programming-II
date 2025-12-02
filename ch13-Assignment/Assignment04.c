
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define AREA_RECT(w, h) (w* h)
#define AREA_CIRCLE(r) (3.141592 * r * r)

void preprocessor();

int main()
{
	preprocessor();

	return 0;
}
void preprocessor()
{
    int sel;
    while (1)
    {
        printf("도형의 종류(1.직사각형, 2. 원 0. 종료)? ");
        scanf("%d", &sel);

        if (sel == 0)
            break;

        switch (sel)
        {
        case 1:
        {
            double w, h;
            printf("가로 세로? ");
            scanf("%lf %lf", &w, &h);
            printf("면적:%.0lf\n", AREA_RECT(w, h));
            break;
        }

        case 2:
        {
            double r;
            printf("반지름? ");
            scanf("%lf", &r);
            printf("면적:%lf\n", AREA_CIRCLE(r));
            break;
        }

        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}



