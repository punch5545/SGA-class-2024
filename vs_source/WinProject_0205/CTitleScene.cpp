#include "pch.h"
#include "CTitleScene.h"

#include "CApplication.h"
#include "CGameFQ4.h"
#include "CImageFile.h"
#include "SceneManager.h"

#include "resource.h"

CTitleScene::CTitleScene()
	:mFont(NULL)
{
	mTitleFile = new CImageFile(MAKEINTRESOURCE(IDB_MAIN_TITLE));
	mBG.Set(0, 0, 0, 0, mTitleFile, 0, CSprite::DrawType_AlphaBlend);
	mBG.mAlpha = 0x00;

	mFont = CreateFont(22, 8, 0, 0, FW_BLACK, 0, 0, 0,
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, L"HY°ß°íµñ");
}

CTitleScene::~CTitleScene()
{
	DeleteObject(mFont);
	delete this->mTitleFile;
}

bool CTitleScene::isFinished()
{
	return false;
}

void CTitleScene::onFrameMove()
{
	timeDelta += 0.2f;

	if (mBG.mAlpha <= 0xf0)
		mBG.mAlpha += 0x05;
	else
	{
		if (timeDelta >= 10.0f && !goNext)
		{
			showText = (!showText);
			timeDelta = 0;
		}
	}
}

void CTitleScene::onDraw(HDC hdc)
{
	mBG.Draw(hdc);

	HFONT oldFont = (HFONT)SelectObject(hdc, mFont);
	
	SetBkMode(hdc, TRANSPARENT);
	SetTextAlign(hdc, TA_CENTER);

	if(showText)
	{
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOut(hdc, WINDOW_INTERNAL_CENTER_X+1, WINDOW_INTERNAL_CENTER_Y + 21, L"PRESS ANY KEY TO START", 22);
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOut(hdc, WINDOW_INTERNAL_CENTER_X, WINDOW_INTERNAL_CENTER_Y + 20, L"PRESS ANY KEY TO START", 22);
	}

	if (CApplication::theApp->pGame->GetKeyDown(VK_ANYKEY))
	{
		if (SceneManager::Manager->SceneIdx < SceneManager::Manager->SceneList.size())
		{
			SceneManager::Manager->SceneIdx++;
			SceneManager::Manager->LoadScene();
		}
	}

	SelectObject(hdc, oldFont);
	DeleteObject(oldFont);
}