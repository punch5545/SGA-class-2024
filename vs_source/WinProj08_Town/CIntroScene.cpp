#include "pch.h"
#include "CImageFile.h"
#include "CIntroScene.h"
#include "resource.h"

CIntroScene::CIntroScene()
{
    mIntroTime = 50;

    mString = new CString();

    mLionFile = new CImageFile(MAKEINTRESOURCE(IDB_LION));
    mLionSprite.Set(0, 0, 0, 0, mLionFile, 0, CSprite::DrawType_Draw);
}

CIntroScene::~CIntroScene()
{
    delete mLionFile;
}

bool CIntroScene::isChanged()
{
    return (mIntroTime <= 0);
}

void CIntroScene::onFrameMove()
{
    --mIntroTime;
}

void CIntroScene::onDraw(HDC hdc)
{
    mString->Draw(hdc, MAKEINTRESOURCE(IDS_LION));
    mLionSprite.Draw(hdc);
}
