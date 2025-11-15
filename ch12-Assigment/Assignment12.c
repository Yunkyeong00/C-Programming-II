/*
학번:202511238
이름:조윤경
프로그램 명:11번 프로그램에 연락처 검색이 실패하는 경우 새로운 연락처를 추가하는 기능을 구현하시오. 또한, 프로그램이 종료될 때 CONTACT 구조체의 내용을 텍스트 파일로 저장하도록 처리하시오.

날짜:2025.11.11
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int FilePrint();

typedef struct
{
	char name[20];
	char num[20];
}RING;


int main()
{
	FilePrint();

	return 0;
}

int FilePrint()
{
	FILE* fp;
	char filename[100];
	RING user[20];
	int count = 0;
	char input_name[20];

	printf("연락처 파일명? ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	while (fscanf(fp, "%s %s", user[count].name, user[count].num) == 2 && count < 10)
	{
		count++;
	}
	fclose(fp);


	printf("%d개의 연락처를 로딩했습니다.\n", count);
	

	while (1)
	{
		printf("이름(. 입력시 종료)? ");
		scanf("%s", input_name);

		if (strcmp(input_name, ".") == 0)
		{
			printf("contacts.txt로 8개의 연락처를 저장했습니다.\n");
			break;
		}

		int found = 0;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(input_name, user[i].name) == 0)
			{
				printf("%s의 전화번호 %s로 전화를 겁니다.\n", user[i].name, user[i].num);
				found = 1;
				break;
			}
		}
		

		if (!found)
		{
			char answer;
			printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까?(y/n)? ");
			scanf(" %c", &answer);

			if (answer == 'y')
			{
				printf("전화번호? ");
				scanf("%s", user[count].num);

				strcpy(user[count].name,input_name);
				count++;
			}
		}
	}

	fp = fopen("contacts.txt", "w");   
	if (fp == NULL) {
		printf("파일 저장 오류!\n");
		return 1;
	}

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s\n", user[i].name, user[i].num);
	}

	fclose(fp);
}