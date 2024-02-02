#include "pch.h"
#include "resource.h"
#include "CImagefile.h"
#include "CIntroScene.h"


CIntroScene::CIntroScene()
{
	mLionFile = new CImageFile(MAKEINTRESOURCE(IDB_LION));
	mLionSprite.setSprite(0, 0, 0, 0, CSprite::DrawType_Draw, 0, mLionFile);
}

CIntroScene::~CIntroScene()
{
	delete mLionFile;
}

void CIntroScene::onFrameMove()
{
}

void CIntroScene::onDraw(HDC hdc)
{
	mLionSprite.Draw(hdc);
}
