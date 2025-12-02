#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct PRODUCT {
    char name[20];
    int price;
    int stock;
};

int order(struct PRODUCT* p, int amount);
void nameorder();


int main(void)
{
    nameorder();

    return 0;
}


int order(struct PRODUCT* p, int amount)
{
    if (amount > p->stock)
    {
        return 0;
    }
    p->stock -= amount;
    return p->price * amount;
}

void nameorder()
{
    struct PRODUCT item;
    int amount, pay;

    printf("제품명? ");
    scanf("%s", item.name);

    printf("가격? ");
    scanf("%d", &item.price);

    printf("재고? ");
    scanf("%d", &item.stock);

    while (1) 
    {
        printf("주문 수량? ");
        scanf("%d", &amount);

        if (amount == 0)
            break;

        pay = order(&item, amount);

        if (pay == 0) {
            printf("재고가 부족합니다.\n");
        }
        else {
            printf("결제금액: %d 재고:%d\n", pay, item.stock);
        }
    }
}