// ConGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

void MoveCursor(int x, int y);
void exitApp();

void printAnimation(int index);
void printHead();
void printFoot(bool isLoop);

int main()
{
	int cnt = 0;
	int sleepTime = 500;
	int kbHit = 0;
	bool isLoop = false;

	while(true)
	{
		if (_kbhit())
		{
			int key = _getch();
			printf("Key Hitted: %c | %d", key, key);
			if (isLoop) exitApp();
		}

		MoveCursor(0, 0);

		printHead();
		printAnimation(cnt);
		printFoot(isLoop);

		cnt++;
		Sleep(sleepTime);
		
		if(cnt > 7) isLoop = true;

		if (cnt > 15) cnt = 0;
	}
}

void MoveCursor(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void exitApp()
{
	exit(0);
}

void printAnimation(int index)
{
	switch (index) {
	case 0:
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		break;
	case 1:
		printf("■      □□□□□□□□                                                                                              ■\n");
		printf("■      □□□□□□□□                                                                                              ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		printf("■            □□                                                                                                    ■\n");
		break;
	case 2:
		printf("■      ■■■■■■■■  □□□□□□□                                                                              ■\n");
		printf("■      ■■■■■■■■  □□□□□□□                                                                              ■\n");
		printf("■            ■■        □□                                                                                        ■\n");
		printf("■            ■■        □□                                                                                        ■\n");
		printf("■            ■■        □□□□□□□                                                                              ■\n");
		printf("■            ■■        □□□□□□□                                                                              ■\n");
		printf("■            ■■        □□                                                                                        ■\n");
		printf("■            ■■        □□                                                                                        ■\n");
		printf("■            ■■        □□□□□□□                                                                              ■\n");
		printf("■            ■■        □□□□□□□                                                                              ■\n");
		break;
	case 3:
		printf("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■\n");
		printf("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■\n");
		printf("■            ■■        ■■                  □□                                                                  ■\n");
		printf("■            ■■        ■■                  □□                                                                  ■\n");
		printf("■            ■■        ■■■■■■■        □□                                                                  ■\n");
		printf("■            ■■        ■■■■■■■        □□                                                                  ■\n");
		printf("■            ■■        ■■                  □□                                                                  ■\n");
		printf("■            ■■        ■■                  □□                                                                  ■\n");
		printf("■            ■■        ■■■■■■■        □□                                                                  ■\n");
		printf("■            ■■        ■■■■■■■        □□                                                                  ■\n");
		break;
	case 4:
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□                                              ■\n");
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□□□                                          ■\n");
		printf("■            ■■        ■■                  ■■        □□        □□                                          ■\n");
		printf("■            ■■        ■■                  ■■        □□        □□                                          ■\n");
		printf("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■\n");
		printf("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■\n");
		printf("■            ■■        ■■                  ■■        □□        □□                                          ■\n");
		printf("■            ■■        ■■                  ■■        □□        □□                                          ■\n");
		printf("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■\n");
		printf("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■\n");
		break;
	case 5:
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      □□□□□□□□                        ■\n");
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  □□□□□□□□                        ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■\n");
		break;
	case 6:
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      □□□□□□      ■\n");
		printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      □□□□□□      ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■\n");
		printf("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■\n");
		printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■\n");
		break;
	default:
		if (index % 2 == 0)
		{
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
			printf("■                                                                                                                    ■\n");
		}
		else
		{
			printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      ■■■■■■      ■\n");
			printf("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      ■■■■■■      ■\n");
			printf("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■\n");
			printf("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■\n");
			printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■\n");
			printf("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■\n");
			printf("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■\n");
			printf("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■\n");
			printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■\n");
			printf("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■\n");
		}
	}		
}

void printHead()
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                                                    ■\n");
	printf("■                                                                                                                    ■\n");
}

void printFoot(bool isLoop)
{
	if (isLoop)
	{
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                   ■    ■■    ■■■    ■■                                     ■\n");
		printf("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                               PRESS ANY KEY TO START                                               ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	}
	else
	{
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                   ■    ■■    ■■■    ■■                                     ■\n");
		printf("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■                                                                                                                    ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	}
}
