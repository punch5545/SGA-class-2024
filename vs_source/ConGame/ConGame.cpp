// ConGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
//#include "Functions.h"
#include "GameManager.h"
#include "TetriminoManager.h"
#include "Tetrimino.h"


void CursorView(BOOL cursorState)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = cursorState; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void MoveCursor(int x, int y);
void PrintBackground();
void printAnimation(int index);
void printFoot(bool isLoop);
void PrintToPos(int x, int y, const char* str, ...);
void PrintToPos(const char* str, int x, int y);

int main()
{
	GameManager gm;

	int cnt = 0;
	bool isLoop = false;

	CursorView(false);

	while(true)
	{
		if (_kbhit())
		{
			int key = _getch();
			//printf("Key Hitted: %c | %d", key, key);
			if (isLoop) break;
		}

		MoveCursor(0, 0);

		PrintBackground();
		if (!gm.IsStart)
		{
			printAnimation(cnt);
			printFoot(isLoop);
		}

		cnt++;
		Sleep(300);
		
		if(cnt > 7) isLoop = true;
		if (cnt > 15) cnt = 0;
	}
	system("cls");
	gm.Init();
}


// 콘솔의 커서를 X, Y 좌표로 이동함
void MoveCursor(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 프로그램 종료
void exitApp()
{
	exit(0);
}

// 배경 그리기
void PrintBackground()
{
	int rightWall = 118;

	PrintToPos("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 0, 0);
	PrintToPos("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 0, 29);
	for (int i = 0; i < 29; i++)
	{
		PrintToPos("■", 0, i);
		PrintToPos("■", 118, i);
	}
}


// 인트로 애니메이션
void printAnimation(int index)
{
	switch (index) {
	case 0:
		PrintToPos("■                                                                                                                    ■", 0, 4);
		PrintToPos("■                                                                                                                    ■", 0, 5);
		PrintToPos("■                                                                                                                    ■", 0, 6);
		PrintToPos("■                                                                                                                    ■", 0, 7);
		PrintToPos("■                                                                                                                    ■", 0, 8);
		PrintToPos("■                                                                                                                    ■", 0, 9);
		PrintToPos("■                                                                                                                    ■", 0, 10);
		PrintToPos("■                                                                                                                    ■", 0, 11);
		PrintToPos("■                                                                                                                    ■", 0, 12);
		PrintToPos("■                                                                                                                    ■", 0, 13);
		break;
	case 1:
		PrintToPos("■      □□□□□□□□                                                                                              ■", 0, 4);
		PrintToPos("■      □□□□□□□□                                                                                              ■", 0, 5);
		PrintToPos("■            □□                                                                                                    ■", 0, 6);
		PrintToPos("■            □□                                                                                                    ■", 0, 7);
		PrintToPos("■            □□                                                                                                    ■", 0, 8);
		PrintToPos("■            □□                                                                                                    ■", 0, 9);
		PrintToPos("■            □□                                                                                                    ■", 0, 10);
		PrintToPos("■            □□                                                                                                    ■", 0, 11);
		PrintToPos("■            □□                                                                                                    ■", 0, 12);
		PrintToPos("■            □□                                                                                                    ■", 0, 13);
		break;
	case 2:
		PrintToPos("■      ■■■■■■■■  □□□□□□□                                                                              ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  □□□□□□□                                                                              ■", 0, 5);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 6);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 7);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 8);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 9);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 10);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 11);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 12);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 13);
		break;
	case 3:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■", 0, 5);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 6);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 9);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 10);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 13);
		break;
	case 4:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□                                              ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□□□                                          ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■", 0, 13);
		break;
	case 5:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      □□□□□□□□                        ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  □□□□□□□□                        ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■", 0, 13);
		break;
	case 6:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      □□□□□□      ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      □□□□□□      ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■", 0, 13);
		break;
	default:
		if (index % 2 == 0)
		{
			PrintToPos("■                                                                                                                    ■", 0, 4);
			PrintToPos("■                                                                                                                    ■", 0, 5);
			PrintToPos("■                                                                                                                    ■", 0, 6);
			PrintToPos("■                                                                                                                    ■", 0, 7);
			PrintToPos("■                                                                                                                    ■", 0, 8);
			PrintToPos("■                                                                                                                    ■", 0, 9);
			PrintToPos("■                                                                                                                    ■", 0, 10);
			PrintToPos("■                                                                                                                    ■", 0, 11);
			PrintToPos("■                                                                                                                    ■", 0, 12);
			PrintToPos("■                                                                                                                    ■", 0, 13);
		}
		else
		{
			PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      ■■■■■■      ■", 0, 4);
			PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      ■■■■■■      ■", 0, 5);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■", 0, 6);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■", 0, 7);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■", 0, 8);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■", 0, 9);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■", 0, 10);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■", 0, 11);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■", 0, 12);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■", 0, 13);
		}
	}
}


// 인트로 애니메이션 하단부
void printFoot(bool isLoop)
{
	// 초반 1회 재생이 끝나면 Press Any Key... 문구 출력
	if (isLoop)
	{
		PrintToPos("■                                                   ■    ■■    ■■■    ■■                                     ■", 0, 17);
		PrintToPos("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■", 0, 18);
		PrintToPos("■                                               PRESS ANY KEY TO START                                               ■", 0, 22);
	}
	// 초반 1회 재생일 경우 출력안함.
	else
	{
		PrintToPos("■                                                   ■    ■■    ■■■    ■■                                     ■", 0, 17);
		PrintToPos("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■", 0, 18);
		PrintToPos("■                                                                                                                    ■", 0, 22);
	}
}

// 콘솔의 원하는 위치로 이동해 printf로 str 문자열 출력
void PrintToPos(const char* str, int x, int y)
{
	MoveCursor(x, y);
	printf(str);
}

// 위 함수와 같음, printf의 "%d" 등 변수를 받아서 출력
void PrintToPos(int x, int y, const char* str, ...)
{
	MoveCursor(x, y);

	int _Result;
	va_list _ArgList;
	__crt_va_start(_ArgList, str);
	_Result = _vfprintf_l(stdout, str, NULL, _ArgList);
	__crt_va_end(_ArgList);

};


/*
■■
■■

■■■■

■
■
■
■

■■
  ■■

  ■
■■
■

■
■■
  ■

  ■■
■■

■■■
■

■■
  ■
  ■

	■
■■■

■
■
■■

■
■■■

■■
■
■

■■■
	■

  ■
  ■
■■

■■■
  ■

  ■
■■
  ■

  ■
■■■

  ■
  ■■
  ■
*/