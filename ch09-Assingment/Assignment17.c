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
        printf("\n[ 0.����  1.�߰�  2.����  3.��� ] ����: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 0) {
            printf("���α׷��� �����մϴ�.\n");
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
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
}

void addSong(char songs[][40], int* count)
{
    if (*count >= 20) {
        printf("�� �̻� �߰��� �� �����ϴ�.\n");
        return;
    }

    printf("�߰��� ����? ");
    gets_s(songs[*count], sizeof(songs[*count]));
    (*count)++;
    printf("�뷡�� �߰��Ǿ����ϴ�!\n");
}

void modifySong(char songs[][40], int count)
{
    if (count == 0) {
        printf("������ ���� �����ϴ�.\n");
        return;
    }

    int index;
    printf("������ �� ��ȣ(0 ~ %d)? ", count - 1);
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= count) {
        printf("�߸��� ��ȣ�Դϴ�.\n");
        return;
    }

    printf("�� ����? ");
    gets_s(songs[index], sizeof(songs[index]));
    printf("������ �Ϸ�Ǿ����ϴ�!\n");
}

void printSongs(char songs[][40], int count)
{
    if (count == 0) {
        printf("����� �뷡�� �����ϴ�.\n");
        return;
    }

    printf("<< �뷡 ��� >>\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i, songs[i]);
    }
}
