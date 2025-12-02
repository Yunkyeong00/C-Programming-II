// 라이브러리 포함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ui.h"

// 버퍼 파일 최대 크기
#define MAX_SIZE 100

// 구조체 정의
typedef struct member 
{
    char username[20];
    char identity[20];
    char id[10];
    char password[20];
} Member;

typedef struct cinema {
    char code[20];
    char date[15];
    char m_title[30];
    int total_seats;
    int available_seats;
} Cinema;

typedef struct movie {
    char code[20];
    char title[50];
    char genre[50];
    int duration;
    char rating[50];
} Movie;

typedef struct seat {
    char seat_code[10];
    int is_reserved;
    char cinema_code[20];
} Seat;

typedef struct booking {
    char cinema_code[20];
    char id[10];
    char seat_codes[10];
    char booking_date[15];
} Booking;


// 파일 이름들 지정 (파일 설계)
char filename[7][32] = {
    "member.txt",       // 0
    "movie.txt",        // 1
    "cinema.txt",       // 2
    "seat_CIN01.txt",   // 3
    "seat_CIN02.txt",   // 4
    "seat_CIN03.txt",   // 5
    "booking.txt"       // 6
};

Member members[MAX_SIZE];
Cinema cinemas[MAX_SIZE];
Seat seats[MAX_SIZE];
Booking bookings[MAX_SIZE];

void make_seat_filename(char* out, int cinema_number)
{
    sprintf(out, "seat_CIN%02d.txt", cinema_number);
}

void trim(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

// 회원 저장
void save_member(Member* m)
{
    FILE* fp = fopen(filename[0], "a");
    if (!fp) {
        printf("member.txt 를 열 수 없습니다.\n");
        return;
    }

    fprintf(fp, "%s | %s | %s | %s\n",
        m->username, m->identity, m->id, m->password);

    fclose(fp);
}

// 아이디 중복 검사
int id_exists(const char* id)
{
    FILE* fp = fopen(filename[0], "r");
    if (!fp) return 0;

    char line[128], name[20], idnum[20], file_id[10], pw[20];
    char id_copy[20];
    strcpy(id_copy, id);
    trim(id_copy);

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, " %19[^|] | %19[^|] | %9[^|] | %19[^\n]",
            name, idnum, file_id, pw) == 4)
        {
            trim(file_id);
            if (strcmp(id, file_id) == 0) {
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}

// 로그인
int login(char* login_id)
{
    char id[20], pw[20];

    showLoginUI();

    // 내부 박스(로그인 UI) 기준 좌표
    int innerX = 30 + 7;   // = 37
    int innerY = 2 + 5;    // = 7
    int inputX = innerX + 20;

    int y_id = innerY + 5;   // 아이디 줄
    int y_pw = innerY + 7;   // 비번 줄

    // 입력을 글자 바로 옆에 받음
    gotoxy(inputX, y_id);
    scanf("%s", id);

    gotoxy(inputX, y_pw);
    scanf("%s", pw);

    FILE* fp = fopen(filename[0], "r");
    if (!fp) {
        printf("member.txt 파일이 없습니다.\n");
        return 0;
    }

    char line[128], name[20], idnum[20], file_id[20], file_pw[20];

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, " %19[^|] | %19[^|] | %19[^|] | %19[^|] ",
            name, idnum, file_id, file_pw) == 4)
        {
            // 앞뒤 공백 제거
            trim(name);
            trim(idnum);
            trim(file_id);
            trim(file_pw);

            if (strcmp(id, file_id) == 0 && strcmp(pw, file_pw) == 0) 
            {
                int msgX = inputX-7;        // 비번 입력칸과 같은 X 위치
                int msgY = y_pw + 4;      // 비번 바로 아래

                gotoxy(msgX, msgY);
                printf("%s님 환영합니다!", name);

                pauseScreen();

                strcpy(login_id, file_id);
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    int msgX = inputX-16;      // 입력칸과 같은 위치
    int msgY = y_pw + 4;    // 비번 바로 아래

    gotoxy(msgX, msgY);
    printf("로그인 실패: 정보가 일치하지 않습니다.");

    pauseScreen();          // 엔터 눌러 넘어가기
    return 0;
}

// 아이디 찾기
void find_login_id()
{
    showFindIDUI();

    FILE* fp = fopen(filename[0], "r");
    if (!fp) return ;

    char identity[20];


    // 작은 박스 시작 좌표 (showFindIDUI와 동일해야 함)
    int innerX = 30 + 7;   // 37
    int innerY = 2 + 5;     // 7

    int labelX = innerX + 6;     // 43 (주민번호 텍스트 위치)
    int inputX = labelX + 12;    // 47 (입력칸 위치)
    int y_input = innerY + 5;    // 13 (주민번호 행)

    // 🔥 여기! 주민번호 텍스트 오른쪽에서 입력하도록 이동
    gotoxy(inputX, y_input);
    scanf("%s", identity);

    Member m;

    char line[128];

    int infoX = innerX + 2;   // 오른쪽 위치
    int infoY = innerY + 5;    // 위쪽 기준

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line, " %19[^|] | %19[^|] | %9[^|] | %19[^\n]",
            m.username, m.identity, m.id, m.password) == 4)
        {
            trim(m.identity);
            trim(m.id);
            trim(m.password);

            if (strcmp(m.identity, identity) == 0)
            {
                // 🔥 오른쪽에 깔끔하게 출력되는 부분
                gotoxy(infoX, infoY);
                printf("회원이름 : %s    ", m.username);

                gotoxy(infoX, infoY + 2);
                printf("ID       : %s", m.id);

                gotoxy(infoX, infoY + 4);
                printf("PW       : %s", m.password);

                pauseScreen();
                fclose(fp);
                return;
            }
        }
    }

    // 못 찾았을 때
    gotoxy(infoX, infoY);
    printf("일치하는 회원 정보가 없습니다.");
    pauseScreen();

    pauseScreen();
    fclose(fp);
}

// 회원가입
void sign_up()
{
    Member m;

    // showSignUpUI()에서 작은 박스가 그려졌다고 가정
    // 작은 박스 위치 기준 (네 UI 그대로 반영)
    int innerX = 30 + 7;   // = 30 (작은 박스 시작 x)
    int innerY = 2 + 5;     // = 8  (작은 박스 시작 y)

    int labelX = innerX + 5;     // 35 ("이름" 출력 위치)
    int inputX = labelX + 12;    // 47 ("입력칸" 위치)

    int y_name = innerY + 5;   // 13
    int y_jumin = innerY + 7;   // 15
    int y_id = innerY + 9;   // 17
    int y_pw = innerY + 11;  // 19

    // 이름 입력
    gotoxy(inputX, y_name);
    scanf("%s", m.username);

    // 주민번호 입력
    gotoxy(inputX, y_jumin);
    scanf("%s", m.identity);

    // 아이디 입력 + 중복 검사
    while (1)
    {
        gotoxy(inputX, y_id);
        scanf("%s", m.id);

        if (id_exists(m.id))
        {
            gotoxy(inputX, y_id + 1);
            printf("이미 존재하는 아이디입니다.");
            pauseScreen();
            
            gotoxy(inputX, y_id + 1);
            printf("                          "); // 아이디 지우기

            gotoxy(inputX, y_id);
            printf("               ");     // 이전 입력 지우기
            gotoxy(inputX, y_id);

            gotoxy(inputX, y_id);
            continue;
        }
        else break;
    }

    // 비밀번호 입력
    gotoxy(inputX, y_pw);
    scanf("%s", m.password);

    save_member(&m);

    // 완료 메시지 (화면 아래 아무 곳)
    gotoxy(inputX-10, y_pw);
    printf("회원가입이 완료되었습니다!");
    pauseScreen();
}
// 영화 목록 조회  
void show_movie_list()
{
    showMovieListUI();

    int outerX = 30;
    int outerY = 2;

    // 큰 박스 내부 좌측 상단 기준
    int listX = outerX + 4;     // 34
    int listY = outerY + 6;
    int offset = 0;

    FILE* fp = fopen(filename[1], "r");
    if (!fp) {
        printf("%s 파일을 열 수 없습니다.\n", filename[1]);
        return;
    }

    Movie m;
    char line[256];

    //printf("=========== 현재 상영작 목록 ===========\n");

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%19[^|] | %49[^|] | %49[^|] | %d | %49[^\n]",
            m.code, m.title, m.genre, &m.duration, m.rating) == 5)
        {

            trim(m.code);
            trim(m.title);
            trim(m.genre);
            trim(m.rating);

            // 첫 번째 줄: 코드, 제목, 장르
            gotoxy(listX, listY + offset);
            printf("[%s] %-30s / %-10s",
                m.code, m.title, m.genre);

            // 두 번째 줄: duration
            gotoxy(listX + 5, listY + offset + 1);
            printf("/ %d분", m.duration);

            // 세 번째 줄: rating
            gotoxy(listX + 5, listY + offset + 2);
            printf("/ %s", m.rating);

            // 다음 영화는 3줄 아래에 출력
            offset += 4;
        }
    }

    printf("\n");
    fclose(fp);

    pauseScreen();
}

// 상영관 로드
int load_cinemas(Cinema* c)
{
    FILE* fp = fopen(filename[2], "r");
    if (!fp) return 0;

    char line[200];
    int count = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line,
            " %19[^|] | %14[^|] | %d | %d | %29[^\n]",
            c[count].code,
            c[count].date,
            &c[count].total_seats,
            &c[count].available_seats,
            c[count].m_title) == 5)
        {
            trim(c[count].code);
            trim(c[count].date);
            trim(c[count].m_title);
            count++;
        }
        else {}
    }

    fclose(fp);
    return count;
}

int load_seats(Seat* s, const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) return 0;

    char line[128];
    int count = 0;

    while (fgets(line, sizeof(line), fp))
    {
        char code[10], room[20];
        int res;

        if (sscanf(line, " %9[^|] | %d | %19[^\n]", code, &res, room) == 3)
        {
            trim(code);
            trim(room);

            strcpy(s[count].seat_code, code);
            s[count].is_reserved = res;
            strcpy(s[count].cinema_code, room);
            count++;
        }
    }

    fclose(fp);
    return count;
}

// 좌석 정보 저장
void save_seats(const char* seat_filename, Seat* s, int count)
{
    FILE* fp = fopen(seat_filename, "w");
    if (!fp) {
        printf("%s 파일 저장 실패\n", seat_filename);
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s | %d | %s\n",
            s[i].seat_code,
            s[i].is_reserved,
            s[i].cinema_code);
    }

    fclose(fp);
}

// 상영관 좌석 수 업데이트
void save_cinemas(Cinema* c, int count)
{
    FILE* fp = fopen(filename[2], "w");
    if (!fp) return;
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s | %s | %d | %d | %s\n",
            c[i].code,
            c[i].date,
            c[i].total_seats,
            c[i].available_seats,
            c[i].m_title);
    fclose(fp);
}

// 예매 정보 저장
void save_booking(const char* cinema_code, const char* id, const char* seat, const char* date)
{
    FILE* fp = fopen(filename[6], "a");
    if (!fp) {
        printf("booking.txt 파일을 열 수 없습니다.\n");
        return;
    }

    fprintf(fp, "%s | %s | %s | %s\n",
        cinema_code, id, seat, date);

    fclose(fp);
}

//예매 내역 취소
void cancelBooking(const char* loginID)
{
    int offsetX = 19;

    showCancelUI();

    FILE* fp = fopen("booking.txt", "r");
    if (fp == NULL)
    {
        gotoxy(20, 12);
        printf("booking.txt 파일을 열 수 없습니다.\n");
        pauseScreen();
        return;
    }

    Booking arr[200];
    int total = 0;

    while (fscanf(fp, " %19[^|] | %9[^|] | %9[^|] | %14[^\n]",
        arr[total].cinema_code,
        arr[total].id,
        arr[total].seat_codes,
        arr[total].booking_date) == 4)
    {
        trim(arr[total].cinema_code);
        trim(arr[total].id);
        trim(arr[total].seat_codes);
        trim(arr[total].booking_date);

        total++;
    }
    fclose(fp);


    int indexList[200];
    int idxCount = 0;

    gotoxy(25+offsetX, 8);
    printf("======= [%s]님 예매 내역 =======", loginID);

    int lineY=10;
    for (int i = 0; i < total; i++)
    {
        if (strcmp(arr[i].id, loginID) == 0)
        {
            indexList[idxCount] = i;

            gotoxy(14+offsetX, lineY);
            printf("%d) 상영관:%s | 좌석:%s | 날짜:%s\n",
                idxCount + 1,
                arr[i].cinema_code,
                arr[i].seat_codes,
                arr[i].booking_date);

            idxCount++;
            lineY++;
        }
    }

    if (idxCount == 0)
    {
        gotoxy(28+ offsetX, 12);
        printf("예매 내역이 없습니다.\n");


        pauseScreenAt(17+ offsetX,18);
        return;
    }

    gotoxy(14+ offsetX, lineY + 2);
    printf("취소할 번호 선택: ");

    int choice;

    while (1)   // ★ 번호 입력 반복 루프 추가 ★
    {
        gotoxy(14 + offsetX, lineY + 2);
        printf("취소할 번호 선택: ");

        scanf("%d", &choice);

        if (choice < 1 || choice > idxCount)
        {
            gotoxy(14 + offsetX, lineY + 4);
            printf("잘못된 번호입니다.");
            pauseScreen();

            // 메시지 지우기
            gotoxy(14 + offsetX, lineY + 4);
            printf("                     ");

            // 입력칸 지우기
            gotoxy(14 + offsetX + strlen("취소할 번호 선택: "), lineY + 2);
            printf("      ");
            gotoxy(14 + offsetX + strlen("취소할 번호 선택: "), lineY + 2);

            continue;   // 다시 번호 입력
        }

        break;  // 정상 입력 → 루프 종료
    }

    int delIndex = indexList[choice - 1];
    Booking del = arr[delIndex];


    char seatFile[64];
    sprintf(seatFile, "seat_%s.txt", del.cinema_code);

    Seat seatArr[200];
    int sCount = load_seats(seatArr, seatFile);

    for (int i = 0; i < sCount; i++)
    {
        if (strcmp(seatArr[i].seat_code, del.seat_codes) == 0)
        {
            seatArr[i].is_reserved = 0;
            break;
        }
    }

    save_seats(seatFile, seatArr, sCount);


    int cCount = load_cinemas(cinemas);

    for (int i = 0; i < cCount; i++)
    {
        if (strcmp(cinemas[i].code, del.cinema_code) == 0)
        {
            cinemas[i].available_seats++;
            break;
        }
    }

    save_cinemas(cinemas, cCount);


    for (int i = delIndex; i < total - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    total--;
    fp = fopen("booking.txt", "w");
    for (int i = 0; i < total; i++)
    {
        trim(arr[i].cinema_code);
        trim(arr[i].id);
        trim(arr[i].seat_codes);
        trim(arr[i].booking_date);


        fprintf(fp, "%s | %s | %s | %s\n",
            arr[i].cinema_code,
            arr[i].id,
            arr[i].seat_codes,
            arr[i].booking_date);
    }
    fclose(fp);

    gotoxy(14 + offsetX, lineY + 6);
    printf("[%s] 좌석 취소 완료!", del.seat_codes);
    pauseScreen();
}


// 영화 예매
void book_movie(const char* login_id)
{
    int c_count = load_cinemas(cinemas);
    if (c_count == 0)
    {
        printf("상영관 데이터 없음\n");
        return;
    }

    // UI 좌표 기준
    int outerX = 20;
    int outerY = 2;
    int outerW = 80;
    int outerH = 27;

    showCinemaListUI();

    int innerX = outerX + 4;
    int innerY = outerY + 7;
    int listX = innerX + 3;
    int listY = innerY + 7;

    // 상영관 목록 출력
    for (int i = 0; i < c_count; i++)
    {
        gotoxy(listX-2, listY-1 + i * 2);
        printf("%2d) %-10s | %s | 좌석:%2d/%2d | %s",
            i + 1,
            cinemas[i].code,
            cinemas[i].date,
            cinemas[i].available_seats,
            cinemas[i].total_seats,
            cinemas[i].m_title);
    }

    // ▶ 출력 위치
    gotoxy(outerX + outerW / 2 - 3, outerY + outerH - 3);
    printf("▶ ");

    // 숫자 입력 위치 (▶ 바로 오른쪽)
    gotoxy(outerX + outerW / 2 - 1, outerY + outerH - 3);
    int cinema_num;
    scanf("%d", &cinema_num);

    // 좌석 파일 로드
    char seat_file[64];
    make_seat_filename(seat_file, cinema_num);

    int s_count = load_seats(seats, seat_file);

    // 좌석 선택 UI 시작
    clearScreen();
    showSeatUI();   // 큰 박스 + 작은 박스 그려짐

    // showSeatUI 기준으로 위치 잡기
    int seatBoxX = outerX + 10;      // 작은 박스 시작점
    int seatBoxY = outerY + 5;
    int seatX = seatBoxX + 20;
    int seatY = seatBoxY + 5;



    // 좌석 목록 출력
    gotoxy(seatX, seatY);

    char currentRow = seats[0].seat_code[0];

    for (int i = 0; i < s_count; i++)
    {
        char row = seats[i].seat_code[0];

        if (row != currentRow) {
            seatY++;
            gotoxy(seatX, seatY);
            currentRow = row;
        }

        printf("%s(%d) ", seats[i].seat_code, seats[i].is_reserved);
    }

    // 안내문 (큰 박스 아래쪽)
    int msgX = outerX + 30;
    int msgY = outerY + outerH - 6;

    gotoxy(msgX, msgY);
    printf("취소하려면 'C' 입력");

    gotoxy(msgX, msgY + 2);
    printf("예매할 좌석 코드 ▶ ");

    char seat_code[10];

    while (1)
    {
        // 입력칸 표시
        gotoxy(msgX + strlen("예매할 좌석 코드 ▶ "), msgY + 2);
        scanf("%s", seat_code);

        // 취소
        if (strcmp(seat_code, "C") == 0) return;

        int found = 0;

        for (int i = 0; i < s_count; i++)
        {
            if (strcmp(seats[i].seat_code, seat_code) == 0)
            {
                found = 1;

                // 이미 예약됨
                if (seats[i].is_reserved == 1)
                {
                    gotoxy(msgX, msgY + 4);
                    printf("이미 예약된 좌석입니다.");
                    pauseScreen();

                    // 메시지 지우기
                    gotoxy(msgX, msgY + 4);
                    printf("                                 ");

                    // ★ 입력칸 지우기 추가
                    int inputX = msgX + strlen("예매할 좌석 코드 ▶ ");
                    int inputY = msgY + 2;
                    gotoxy(inputX, inputY);
                    printf("               ");   // 15칸 지움
                    gotoxy(inputX, inputY);       // 커서 위치 복귀

                    continue;
                }

                // 예약
                seats[i].is_reserved = 1;
                cinemas[cinema_num - 1].available_seats--;

                save_seats(seat_file, seats, s_count);
                save_cinemas(cinemas, c_count);

                save_booking(
                    cinemas[cinema_num - 1].code,
                    login_id,
                    seat_code,
                    cinemas[cinema_num - 1].date
                );

                // 성공 메시지
                gotoxy(msgX, msgY + 4);
                printf("%s 좌석 예약 완료!", seat_code);
                pauseScreen();
                return;
            }
        }

        // 좌석 없음
        if (!found)
        {
            gotoxy(msgX, msgY + 4);
            printf("존재하지 않는 좌석입니다.");
            pauseScreen();

            // 메시지 지우기
            gotoxy(msgX, msgY + 4);
            printf("                                 ");

            // ★ 입력칸 지우기 추가
            int inputX = msgX + strlen("예매할 좌석 코드 ▶ ");
            int inputY = msgY + 2;
            gotoxy(inputX, inputY);
            printf("               ");   // 15칸 지움
            gotoxy(inputX, inputY);       // 커서 위치 복귀

            continue;
        }
    }
}

// 예매 내역 조회
void view_bookings(const char* login_id)
{
    showBookingListUI();

    FILE* fp = fopen(filename[6], "r");
    if (!fp) {
        printf("booking.txt 없음\n");
        return;
    }

    char line[200];
    Booking b;

    //printf("\n===== 나의 예매 내역 =====\n");
    int outerX = 30;
    int outerY = 2;

    int startX = outerX + 4;        // 출력 시작 X
    int startY = outerY + 6;        // 첫 줄 출력 Y
    int offset = 0;

    while (fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line, " %19[^|] | %9[^|] | %9[^|] | %14[^\n]",
            b.cinema_code, b.id, b.seat_codes, b.booking_date) == 4)
        {
            trim(b.cinema_code);
            trim(b.id);
            trim(b.seat_codes);
            trim(b.booking_date);

            if (strcmp(b.id, login_id) == 0)
            {
                gotoxy(startX, startY + offset);
                printf("상영관:%s  좌석:%s  날짜:%s",
                    b.cinema_code, b.seat_codes, b.booking_date);

                offset += 2; // 2줄 내려가게
                //printf("상영관:%s  좌석:%s  날짜:%s\n",
                  //  b.cinema_code, b.seat_codes, b.booking_date);
            }
        }
    }

    fclose(fp);
    printf("\n");

    pauseScreen();
}


void main_menu()
{
    int sel;
    char login_id[20];

    // 메인 메뉴 루프
    while (1)
    {
        sel = showMainMenu();   // UI 화면 호출

        if (sel == 1) {
           // showLoginUI();      // UI 화면
            if (login(login_id)) break;
        }
        else if (sel == 2) {
            showSignUpUI();     // UI 화면
            sign_up();
        }
        else if (sel == 3) {
            find_login_id();
        }
        else if (sel == 4) return;
    }

    // 로그인 후 사용자 메뉴
    while (1)
    {
        sel = showUserMenu();  // UI 화면 호출

        if (sel == 1) show_movie_list();
        else if (sel == 2) book_movie(login_id);
        else if (sel == 3) view_bookings(login_id);
        else if (sel == 4) cancelBooking(login_id);
        else if (sel == 5) return;
    }
}

int main()
{
    main_menu();
    return 0;
}
