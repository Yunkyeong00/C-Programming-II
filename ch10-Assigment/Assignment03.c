/* 파일명: ch10-3

  * 내용: LOGIN 구조체 배열을 이용해서 로그인 과정을 프로그램으로 작성하시오.
  아이디를 입력받아 LOGIN 구조체 배열에서 아이디를 찾은 다음 입력받은 패스워드와
  등록된 패스워드를 비교해서 같으면 "로그인 성공"이라고 출력한다. LOGIN 구조체 배열은 크기가
  5인 배열로 선언하고 적당한 값으로 초기화해서 사용한다.

  * 작성자: 조윤경

  * 날짜: 2025.06.05

  * 버전: v1.0

  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct login
{
    char ID[20];
    char Password[20];
};

// 로그인 검증 함수
int check(struct login users[], char id[], char pw[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(users[i].ID, id) == 0 && strcmp(users[i].Password, pw) == 0) {
            return 1; // 로그인 성공
        }
    }

    return 0;
}

int slove()
{
    struct login users[5] =
    {
        {"guest", "idontknow"},
        {"admin", "1234"},
        {"user1", "pw1"},
        {"user2", "pw2"},
        {"user3", "pw3"}
    };

    char id[20], pw[20];

    while (1)
    {
        printf("ID? ");
        scanf("%s", id);

        if (!strcmp(id, "."))
        {
            break;
        }

        printf("PW? ");
        scanf("%s", pw);

        if (check(users, id, pw))
        {
            printf("로그인 성공\n");
        }
        else
        {
            printf("로그인 실패\n");
        }
    }

    return 0;
}

int main()
{
    slove();

    return 0;
}