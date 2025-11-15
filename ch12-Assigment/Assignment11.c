/*
학번:202511238
이름:조윤경
프로그램 명:CONTACT 구조체를 이용한 연락처 관리 프로그램에 텍스트 파일에서 연락처를 로딩하는 기능을 추가한다. 
            텍스트 파일에 정해진 형식으로 연락처를 저장하고 이 파일을 읽어서 CONTACT 구조체 배열을 생성하도록 프로그램을 작성하시오. CONTACT 구조체 배열은 동적 메모리에 생성한다.

날짜:2025.11.09
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
	char line[300];
	RING user[20];
	int count=0;
	char input_name[20];
	int found_name;

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


	printf("%d개의 연락처를 로딩했습니다.\n",count);
	fclose(fp);

	while (1)
	{
		printf("이름(. 입력시 종료)? ");
		scanf("%s", input_name);

		if (strcmp(input_name, ".") == 0)
		{
			printf("프로그램을 종료합니다.\n");
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
		if(!found)
			printf("연락처를 찾을 수 없습니다.\n");
		
		
	}
}