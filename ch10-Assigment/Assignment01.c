/* 파일명: ch10-1

  * 내용: LOGIN 구조체 변수를 선언한 다음 아이디와 패스워드를 입력받아 저장하고 출력하는 프로그램을 작성하시오.
  패스워드를 출력할 때는 패스워드의 내용은 보이지 않도록 패스워드 글자 수만큼 *을 대신 출력하시오.

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

void plogin(struct login user)
{
	printf("ID: %s\n", user.ID);
	printf("PW: ");

	for (int i = 0; i < strlen(user.Password); i++)
	{
		printf("*");
	}
	printf("\n");
}

struct login solve()
{
	struct login user;

	printf("ID? ");
	scanf("%s", user.ID);
	printf("Password? ");
	scanf("%s", user.Password);

	return user;
}

int main()
{
	struct login user = solve();

	plogin(user);

	return 0;
}