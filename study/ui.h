#ifndef UI_H
#define UI_H

// --- 콘솔 UI 기본 기능 ---
void gotoxy(int x, int y);
void setColor(int text, int bg);
void clearScreen();
void drawBox(int x, int y, int w, int h);
void centerText(int y, const char* msg);
void pauseScreen();

// --- 페이지별 UI 화면 ---
int showMainMenu();          // 메인 메뉴 UI
int showUserMenu();          // 로그인 후 사용자 메뉴 UI
void showLoginUI();          // 로그인 UI (입력창 포함 X)
void showSignUpUI();         // 회원가입 UI (입력창 포함 X)
void showMovieListUI();      // 영화 목록 UI (제목 박스만)
void showSeatUI();           // 좌석 선택 UI (박스만)
void showBookingListUI();    // 예매 내역 UI
void showCancelUI();         // 예매 취소 UI
void pauseScreenAt(int x, int y);
#endif
