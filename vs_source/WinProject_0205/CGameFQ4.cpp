#include "pch.h"
#include "CGameFQ4.h"
#include "CIntroScene.h"

void CGameFQ4::onCreate()
{
	// OutputDebugString(L"Game Created.\n");
	mIntroScene = new CIntroScene;
	mCurrent = mIntroScene;
}

void CGameFQ4::onDestroy()
{
	// OutputDebugString(L"Game Destroyed\n");
	delete mIntroScene;
}

void CGameFQ4::onFrameMove()
{
	// OutputDebugString(L"Game Frame Moved\n");
	__super::onFrameMove();
}

void CGameFQ4::onDraw(HDC hdc)
{
	// OutputDebugString(L"Game Drawed\n");
	__super::onDraw(hdc);
}
