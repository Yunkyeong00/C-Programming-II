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