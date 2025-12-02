#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "ui.h"

// ────────────────────────────────
// 기본 UI 기능
// ────────────────────────────────

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int text, int bg) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + text);
}

void clearScreen() {
    system("cls");
}

void drawBox(int x, int y, int w, int h) {
    int i;
    gotoxy(x, y); printf("┌");
    for (i = 0; i < w - 2; i++) printf("─");
    printf("┐");

    for (i = 1; i < h - 1; i++) {
        gotoxy(x, y + i); printf("│");
        gotoxy(x + w - 1, y + i); printf("│");
    }

    gotoxy(x, y + h - 1); printf("└");
    for (i = 0; i < w - 2; i++) printf("─");
    printf("┘");
}

void centerText(int y, const char* msg) {
    int x = (80 - strlen(msg)) / 2;
    gotoxy(x, y);
    printf("%s", msg);
}

void pauseScreen() 
{
    _getch();
    /*gotoxy(x, y);
    setColor(8, 0);
    printf("\n\n 계속하려면 아무 키나 누르세요...");
    setColor(7, 0);
    _getch();
    */
}

void pauseScreenAt(int x, int y)
{
    gotoxy(x, y);
    setColor(8, 0);
    printf("계속하려면 아무 키나 누르세요...");
    setColor(7, 0);
    _getch();
}


// ────────────────────────────────
// 1) 메인 메뉴 UI (손그림 스타일)
// ────────────────────────────────
int showMainMenu()
{
    clearScreen();

    // 바깥 큰 박스
    int outerX = 30;   // 현재 너가 사용 중인 값
    int outerY = 2;
    int outerW = 60;
    int outerH = 25;
    drawBox(outerX, outerY, outerW, outerH);

    // 상단 제목 (왼쪽으로 4 이동: -4)
    gotoxy(outerX + outerW / 2 - 6 - 2, outerY + 2);
    printf("영화 예매 시스템");

    // 안쪽 박스
    int innerX = outerX + 7;   // 37
    int innerY = outerY + 5;   // 7
    int innerW = 46;
    int innerH = 15;
    drawBox(innerX, innerY, innerW, innerH);

    // 내부 제목 (왼쪽으로 4 이동)
    gotoxy(innerX + innerW / 2 - 8 - 3, innerY + 2);
    printf("< 메뉴를 선택하세요 >");

    // 메뉴 리스트 (그대로 유지)
    gotoxy(innerX + 8, innerY + 5);  printf("[1] 로그인");
    gotoxy(innerX + 8, innerY + 7);  printf("[2] 회원가입");
    gotoxy(innerX + 8, innerY + 9);  printf("[3] 회원 정보 찾기");
    gotoxy(innerX + 8, innerY + 11); printf("[4] 종료");

    // 입력 화살표 (그대로)
    gotoxy(outerX + outerW / 2 - 1-2, outerY + outerH - 3);
    printf("▶ ");

    int sel;
    scanf("%d", &sel);
    return sel;
}

void showCinemaListUI()
{
    clearScreen();

    int outerX = 20;
    int outerY = 2;
    int outerW = 80;
    int outerH = 27;

    // 바깥 큰 박스만 유지
    drawBox(outerX, outerY, outerW, outerH);

    // 제목: 상영관 목록
    gotoxy(outerX + outerW / 2 - 5, outerY + 2);
    printf("상영관 목록");

    // 내부 박스 제거하고 문구만 위로 이동
    gotoxy(outerX + 30, outerY + 7);   // ← y좌표 5 → 4 (더 위로)
    printf("< 상영관을 선택하세요 >");

    // 화살표 위치 동일
    gotoxy(outerX + outerW / 2 - 3, outerY + outerH - 3);
    printf("▶ ");
}



// ────────────────────────────────
// 2) 로그인 후 사용자 메뉴 UI (손그림 스타일 동일 적용)
// ────────────────────────────────
int showUserMenu()
{
    clearScreen();

    // 메인 메뉴와 동일한 바깥 박스 위치 (outerX = 30)
    int outerX = 30;
    int outerY = 2;
    int outerW = 60;
    int outerH = 25;

    drawBox(outerX, outerY, outerW, outerH);

    // 제목 위치도 메인 메뉴와 동일 규칙 적용
    gotoxy(outerX + outerW / 2 - 7, outerY + 2);
    printf("사용자 메뉴");

    // 내부 박스도 메인 메뉴와 동일 (innerX = outerX + 7)
    int innerX = outerX + 6;    // 37
    int innerY = outerY + 5;    // 7
    int innerW = 46;
    int innerH = 15;

    drawBox(innerX, innerY, innerW, innerH);

    // 내부 제목도 동일한 중앙 정렬 방식
    gotoxy(innerX + innerW / 2 - 8 - 2, innerY + 2);
    printf("< 기능을 선택하세요 >");

    // 메뉴 리스트 (메인 메뉴와 같은 좌표 구조)
    gotoxy(innerX + 8, innerY + 5);  printf("[1] 영화 목록 조회");
    gotoxy(innerX + 8, innerY + 7);  printf("[2] 영화 예매");
    gotoxy(innerX + 8, innerY + 9);  printf("[3] 예매 내역 조회");
    gotoxy(innerX + 8, innerY + 11); printf("[4] 예매 취소");
    gotoxy(innerX + 8, innerY + 13); printf("[5] 로그아웃");

    // 화살표도 동일 규칙 (메인 메뉴 기준)
    gotoxy(outerX + outerW / 2 - 3, outerY + outerH - 3);
    printf("▶ ");

    int sel;
    scanf("%d", &sel);
    return sel;
}



// ────────────────────────────────
// 3) 로그인 UI (그림 느낌으로 단순화)
// ────────────────────────────────
void showLoginUI()
{
    clearScreen();

    // 큰 박스
    int outerX = 30, outerY = 2, outerW = 60, outerH = 25;
    drawBox(outerX, outerY, outerW, outerH);

    // 큰 박스 제목 (영화 예매 시스템)
    gotoxy(outerX + outerW / 2 - 6, outerY + 2);
    printf("영화 예매 시스템");

    // 작은 박스
    int innerX = outerX + 7;    // 큰 박스 안쪽 여백
    int innerY = outerY + 5;
    int innerW = 46;
    int innerH = 15;

    drawBox(innerX, innerY, innerW, innerH);

    // 작은 박스 제목 (로그인)
    gotoxy(innerX + innerW / 2 - 3, innerY + 2);
    printf("로그인");

    // 아이디 / 비번 텍스트 (그림처럼 간단하게)
    gotoxy(innerX + 6, innerY + 5);
    printf("아이디");

    gotoxy(innerX + 6, innerY + 7);
    printf("비번");
}



// ────────────────────────────────
// 4) 회원가입 UI
// ────────────────────────────────
void showSignUpUI()
{
    clearScreen();

    // 큰 박스
    int outerX = 30, outerY = 2, outerW = 60, outerH = 25;
    drawBox(outerX, outerY, outerW, outerH);

    // 큰 박스 제목
    gotoxy(outerX + outerW / 2 - 6, outerY + 2);
    printf("영화 예매 시스템");

    // 작은 박스
    int innerX = outerX + 7;   // 30
    int innerY = outerY + 5;    // 8
    int innerW = 46;
    int innerH = 15;
    drawBox(innerX, innerY, innerW, innerH);

    // 작은 박스 제목
    gotoxy(innerX + innerW / 2 - 3, innerY + 2);
    printf("회원가입");

    // 정보 텍스트
    gotoxy(innerX + 5, innerY + 5);
    printf("이름");

    gotoxy(innerX + 5, innerY + 7);
    printf("주민번호");

    gotoxy(innerX + 5, innerY + 9);
    printf("아이디");

    gotoxy(innerX + 5, innerY + 11);
    printf("비밀번호");
}



// ────────────────────────────────
// 5) 영화 목록 화면 (타이틀만)
// ────────────────────────────────
void showMovieListUI()
{
    clearScreen();

    // 메인 메뉴와 동일한 큰 박스
    int outerX = 30, outerY = 2, outerW = 60, outerH = 25;
    drawBox(outerX, outerY, outerW, outerH);

    // 제목 위치도 동일한 규칙
    gotoxy(outerX + outerW / 2 - 6, outerY + 2);
    printf("현재 상영작 목록");

}



// ────────────────────────────────
// 6) 좌석 화면
// ────────────────────────────────
void showSeatUI()
{
    clearScreen();

    // 큰 박스(메인 UI)
    int outerX = 20;
    int outerY = 2;
    int outerW = 80;
    int outerH = 27;

    drawBox(outerX, outerY, outerW, outerH);

    // 제목 중앙
    gotoxy(outerX + outerW / 2 - 6, outerY + 4);
    printf("영화 예매 시스템");

    // 🔹 작은 박스 추가 (좌석 목록을 넣을 공간)
    int innerX = outerX + 10;    // 큰 박스 안에서 오른쪽/아래로 띄움
    int innerY = outerY + 7;
    int innerW =outerW -20;
    int innerH = outerH-14;

    drawBox(innerX, innerY, innerW, innerH);

    gotoxy(innerX + innerW / 2 - 4, innerY + 2);
    printf("좌석 선택");
    printf("\n\n");
}



// ────────────────────────────────
// 7) 예매 내역
// ────────────────────────────────
void showBookingListUI()
{
    clearScreen();

    // 메인 메뉴와 동일한 큰 네모
    int outerX = 30;
    int outerY = 2;
    int outerW = 60;
    int outerH = 25;

    drawBox(outerX, outerY, outerW, outerH);

    // 제목 중앙 정렬
    gotoxy(outerX + outerW / 2 - 4, outerY + 2);
    printf("예매 내역");
}



// ────────────────────────────────
// 8) 예매 취소
// ────────────────────────────────
void showCancelUI()
{
    clearScreen();
    drawBox(30, 2, 60, 25);//왼쪽부터 박스의 시작 x좌표, y좌표,가로크기,세로 크기

    gotoxy(30 + 60 / 2 - 4, 2+2); //박스의 시작 x,박스 가로 길이, 제목 y 위치
    printf("예매 취소");
}


void showFindIDUI()
{
    clearScreen();

    // 큰 박스
    int outerX = 30, outerY = 2, outerW = 60, outerH = 25;
    drawBox(outerX, outerY, outerW, outerH);

    // 큰 박스 제목
    gotoxy(outerX + outerW / 2 - 6, outerY + 2);
    printf("영화 예매 시스템");

    // 작은 박스
    int innerX = outerX + 7;  // 30
    int innerY = outerY + 5;   // 8
    int innerW = 46;
    int innerH = 15;
    drawBox(innerX, innerY, innerW, innerH);

    // 작은 박스 제목
    gotoxy(innerX + innerW / 2 - 5, innerY + 2);
    printf("회원 정보 찾기");

    // 텍스트
    gotoxy(innerX + 6, innerY + 5);
    printf("주민번호");
}

