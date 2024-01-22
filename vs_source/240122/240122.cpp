// 240122.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "P_하트.h"

#include "Screen.h"
#include "Heart.h"
#include "HeartManager.h"

Screen G_SCREEN;
HeartManager* g_HeartMgr;

bool CheckKey()
{
	if (_kbhit())
	{
		while (_kbhit()) { char key = _getch(); }
		return true;
	}
	return false;
}

int main()
{
	g_HeartMgr = new HeartManager;

	//g_HeartMgr = (HeartManager*)malloc(sizeof(HeartManager));
		
	while (1)
	{
		if(CheckKey())
			g_HeartMgr->Make(2, 3);

		system("cls");
		G_SCREEN.f_스크린초기화();
		
		f_벽_그리기(&G_SCREEN);

		g_HeartMgr->Move(&G_SCREEN);
		g_HeartMgr->Draw(&G_SCREEN);


		G_SCREEN.f_스크린그리기();

		Sleep(1000 / SCREEN_FRAME_COUNT);
	}

	delete g_HeartMgr;
}