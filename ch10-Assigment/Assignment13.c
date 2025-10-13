/* 파일명: ch10-13

  * 내용: RECT 구조체를 정의하시오. 직사각형은 좌하단점과 우상단점으로 구성되며
  점의 좌표는 POINT 구조체를 이용해서 나타낸다. 직사각형 정보를 출력하는 print_rect 함수를 정의하고
  RECT 구조체 변수를 선언해서 직사각형 정보를 입력받고 출력하는 프로그램을 작성하시오.

  * 작성자: 조윤경

  * 날짜: 2025.06.07

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

  // 점 구조체 정의
struct POINT
{
    int x;
    int y;
};

// 사각형 구조체 정의
struct RECT
{
    struct POINT left_bottom;
    struct POINT right_top;
};

// 출력 함수
void print_rect(struct RECT r)
{
    printf("[RECT 좌하단점:(%d, %d) 우상단점:(%d, %d)]\n",
        r.left_bottom.x, r.left_bottom.y,
        r.right_top.x, r.right_top.y);
}

int slove()
{
    struct RECT rect;

    printf("직사각형의 좌하단점(x,y)? ");
    scanf("%d %d", &rect.left_bottom.x, &rect.left_bottom.y);

    printf("직사각형의 우상단점(x,y)? ");
    scanf("%d %d", &rect.right_top.x, &rect.right_top.y);

    print_rect(rect);

    return 0;
}

int main()
{
    slove();

    return 0;
}