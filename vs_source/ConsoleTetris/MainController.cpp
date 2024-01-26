#include "pch.h"
#include "MainController.h"

void MainController::ShowIntro()
{

}

void MainController::StartGame()
{
	int a = 0;
	while (true)
	{
		Update();
		Sleep(FRAME_PER_SECOND);
	}
}

void MainController::Update()
{
}

MainController::MainController()
{
	this->screen = new Screen();
}

MainController::~MainController()
{
	delete(this->screen);
}
