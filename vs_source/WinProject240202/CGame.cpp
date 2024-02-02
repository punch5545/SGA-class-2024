#include "pch.h"
#include "CIntroScene.h"
#include "CGame.h"

void CGame::onCreate()
{
	mIntroScene = new CIntroScene();
}

void CGame::onFrameMove()
{
	mIntroScene->onFrameMove();
}

void CGame::onDestroy()
{
	delete mIntroScene;
}

void CGame::onDraw(HDC hdc)
{
	mIntroScene->onDraw(hdc);
}
