/*
학번:202511238
이름:조윤경
프로그램 명:아이디와 패스워드가 저장된 텍스트 파일을 크기가 10인
            LOGIN 구조체 배열로 읽어온 다음, 입력 받은 아이디와 패스워드가 일치하면
			"로그인 성공" 아니면 "로그인 실패"라고 출력하는 프로그램을 작성하시오. 텍스트 파일의
			형식은 다음과 같다.
날짜:2025.11.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void PassWord();


typedef struct
{
	char id[10];
	char pw[20];
}LOGIN;

int main(void)
{
	PassWord();

	return 0;

}

void PassWord()
{
	FILE* fp;
	LOGIN user[10];
	char input_id[10], input_pw[10];
	int count = 0, success = 0, found_id = 0;

	fp = fopen("password.txt", "r");
	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	while (fscanf(fp, "%s %s", user[count].id, user[count].pw) == 2 && count < 10)
	{
		count++;
	}
	fclose(fp);

	while (1)
	{
		printf("ID? ");
		scanf("%s", input_id);

		if (strcmp(input_id, ".") == 0)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		for (int i = 0; i < count; i++)
		{
			if (strcmp(input_id, user[i].id) == 0)
			{
				found_id = 1;
				printf("password? ");
				scanf("%s", input_pw);

				if (strcmp(input_pw, user[i].pw) == 0)
					success = 1;
				else
					printf("비밀번호가 일치하지 않습니다.\n");
				break;
			}
		}

		if (!found_id)
			printf("아이디를 찾을 수 없습니다.\n");
		else 
			printf("로그인 성공!\n");
		
	}
}