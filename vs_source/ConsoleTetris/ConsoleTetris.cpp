// ConsoleTetris.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include "MainController.h"

MainController* mainController;

int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	mainController = new MainController();
	
	mainController->StartGame();
}
