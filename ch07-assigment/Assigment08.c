/* 파일명: CH07_8.c

   * 내용: 상품 가격이 저장된 정수형 배열에 대하여 할인율(%)을 입력받아 할인된 가격을 계산해서 출력하는
   *       프로그램을 작성하시오, 상품 가격이 저장된 배열의 크기는 5이고, 상품 가격은 입력받아서 사용한다
   *       할인된 가격은 별도의 배열에 저장한다

   * 작성자: 조윤경

   * 날짜: 2025.9.21

   * 버전: v1.0

   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int price_print(int price[], int result_price[5]);
int calculate_discount(int price[], int discount);
int input_PriceDiscount();


int main()
{
	input_PriceDiscount();

	return 0;
}

int input_PriceDiscount()
{
	int i;
	int price[5];
	int discount;

	printf("상품가 5개를 입력하세요: ");

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &price[i]);
	}

	printf("할인율(%)? ");
	scanf("%d", &discount);

	calculate_discount(price, discount);

}

int calculate_discount(int price[], int discount)
{
	int result_price[5];

	for (int i = 0; i < 5; i++)
	{
		result_price[i] = (price[i] - (price[i] * discount / 100));
	}

	price_print(price,result_price);
}

int price_print(int price[], int result_price[5])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("가격: %6d --> 할인가: %6d\n", price[i], result_price[i]);
	}
}