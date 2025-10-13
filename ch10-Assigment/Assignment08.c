/* 파일명: ch10-8

  * 내용: PRODUCT 구조체를 정의하시오. 각 제품별로 제품명, 가격, 재고를 저장할 수 있어야 한다.
  PRODUCT 구조체를 매개변수로 전달받아 제품 정보를 출력하는 print_product 함수를 정의하시오.
  PRODUCT 구조체 변수를 선언한 다음 제품명, 가격, 재고를 입력받아 저장하고 출력하는 프로그램을 작성하시오.
  참고로 제품명은 빈칸 없는 한 단어로 입력한다.

  * 작성자: 조윤경

  * 날짜: 2025.06.06

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

  // 구조체 정의
struct PRODUCT
{
    char name[20];   // 제품명
    int price;       // 가격
    int stock;       // 재고 수량
};


void print_product(struct PRODUCT p)
{
    printf("[%s: %d원 재고:%d]\n", p.name, p.price, p.stock);
}

int slove()
{
    struct PRODUCT p;

    printf("제품명? ");
    scanf("%s", p.name);

    printf("가격? ");
    scanf("%d", &p.price);

    printf("재고? ");
    scanf("%d", &p.stock);

    print_product(p);

    return 0;
}

int main()
{
    slove();

    return 0;
}