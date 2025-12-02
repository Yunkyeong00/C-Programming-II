
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char ID[20];
    char PW[20];
} LOGIN;

int main() 
{
    FILE* fp;
    LOGIN user[20];
    int count = 0;
    char input_ID[20];
    char input_PW[20];
    char answer;

    
    fp = fopen("password.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

  
    while (fscanf(fp, "%s %s", user[count].ID, user[count].PW) == 2 && count < 20)
    {
        count++;
    }
    fclose(fp);

    while (1)
    {
        printf("ID? ");
        scanf("%s", input_ID);

        // 종료조건
        if (strcmp(input_ID, ".") == 0)
            break;

        int found = -1;

        // ID 검색
        for (int i = 0; i < count; i++)
        {
            if (strcmp(input_ID, user[i].ID) == 0)
            {
                found = i;
                break;
            }
        }

        
        if (found >= 0) 
        {
            printf("Password? ");
            scanf("%s", input_PW);

            if (strcmp(input_PW, user[found].PW) == 0)
                printf("로그인 성공\n");
            else
                printf("로그인 실패\n");
        }

       
        else
        {
            printf("아이디를 찾을 수 없습니다 등록하시겠습니까?(y/n)? ");
            scanf(" %c", &answer);

            if (answer == 'y')
            {
                while (1)
                {
                    printf("PW? ");
                    scanf("%s", user[count].PW);

                    printf("PW again? ");
                    scanf("%s", input_PW);

                    if (strcmp(user[count].PW, input_PW) == 0)
                    {
                       
                        strcpy(user[count].ID, input_ID);
                        count++;
                        printf("ID and PW registered successfully\n");
                        break;

                    }
                    else
                    {
                        printf("Password doesn't match.\n");
                    }
                }
            }
        }
    }

   
    fp = fopen("contacts.txt", "w");
    if (fp == NULL)
    {
        printf("파일 저장 오류!\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s\n", user[i].ID, user[i].PW);
    }

    fclose(fp);

    return 0;
}
