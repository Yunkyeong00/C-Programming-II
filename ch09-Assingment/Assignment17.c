/*
학번:202511238
이름:조윤경
프로그램 명:
날짜:

*/
#include <stdio.h>
#include <string.h>

void input();
void addSong(char songs[][40], int* count);
void modifySong(char songs[][40], int count);
void printSongs(char songs[][40], int count);

int main()
{
    input();
    return 0;
}

void input()
{
    char songs[20][40];
    int count = 0;
    int menu;

    while (1) {
        printf("\n[ 0.종료  1.추가  2.수정  3.목록 ] 선택: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else if (menu == 1) {
            addSong(songs, &count);
        }
        else if (menu == 2) {
            modifySong(songs, count);
        }
        else if (menu == 3) {
            printSongs(songs, count);
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }
}

void addSong(char songs[][40], int* count)
{
    if (*count >= 20) {
        printf("더 이상 추가할 수 없습니다.\n");
        return;
    }

    printf("추가할 제목? ");
    gets_s(songs[*count], sizeof(songs[*count]));
    (*count)++;
    printf("노래가 추가되었습니다!\n");
}

void modifySong(char songs[][40], int count)
{
    if (count == 0) {
        printf("수정할 곡이 없습니다.\n");
        return;
    }

    int index;
    printf("수정할 곡 번호(0 ~ %d)? ", count - 1);
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    printf("새 제목? ");
    gets_s(songs[index], sizeof(songs[index]));
    printf("수정이 완료되었습니다!\n");
}

void printSongs(char songs[][40], int count)
{
    if (count == 0) {
        printf("저장된 노래가 없습니다.\n");
        return;
    }

    printf("<< 노래 목록 >>\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i, songs[i]);
    }
}
