#include "pch.h"
#include "CLobbyScene.h"

#include "CApplication.h"
#include "CGameFQ4.h"
#include "CImageFile.h"
#include "SceneManager.h"
#include "CMainStoryScene.h"

#include "resource.h"

CLobbyScene::CLobbyScene()
	:mFont(NULL)
{
	mImageFile = new CImageFile(MAKEINTRESOURCE(IDB_LOBBY));
	mBG.Set(0, 0, 0, 0, mImageFile, 0, CSprite::DrawType_AlphaBlend);
	mBG.mAlpha = 0xFF;

	mSelectImageFile = new CImageFile(MAKEINTRESOURCE(IDB_SELECTBG));

	int y = 160;
	for (int i = 0; i < 4; i++)
	{
		mSelectBGs.push_back(CSprite());

		mSelectBGs[i].Set(237, y, 0, 0, mSelectImageFile, 0, CSprite::DrawType_AlphaBlend);
		mSelectBGs[i].mAlpha = 0xFF;

		y += 16;
	}

	mSelectBGs.push_back(CSprite());

	mSelectBGs[mSelectBGs.size() - 1].Set(237, 241, 0, 0, mSelectImageFile, 0, CSprite::DrawType_AlphaBlend);
	mSelectBGs[mSelectBGs.size() - 1].mAlpha = 0xFF;

	mFont = CreateFont(18, 6, 0, 0, FW_NORMAL, 0, 0, 0,
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, L"HY견고딕");

	saveFiles.push_back(SaveFile(L".\\", L"리오스/서쪽",		391));
	saveFiles.push_back(SaveFile(L".\\", L"우리집/입구",		80));
	saveFiles.push_back(SaveFile(L".\\", L"너네집/출구",		10));
	saveFiles.push_back(SaveFile(L".\\", L"카리온성",		8));

	for (int i = 0; i < mSelectBGs.size(); i++)
	{
		if (i < mSelectBGs.size() - 1)
		{
			LPCWSTR saveName = saveFiles[i].saveName;
			mSelectBGs[i].addClickEvent(([=]() { OutputDebugStringW(saveName); }));
		}
		else
		{
			mSelectBGs[i].addClickEvent(([&]() { 
				OutputDebugStringW(L" >> 새 게임 ");


			}));
		}
	}
}

CLobbyScene::~CLobbyScene()
{
	DeleteObject(mFont);
	delete this->mImageFile;
}

bool CLobbyScene::isFinished()
{
    return false;
}

void CLobbyScene::onFrameMove()
{
	for (auto& selectBG : mSelectBGs)
	{
		if (selectBG.IsInRect(CApplication::theApp->mMousePos))
		{
			selectBG.mAlpha = 0xFF;
			if (CApplication::theApp->mMouseBtn == VK_LBUTTON)
			{
				selectBG.onClick();
			}
		}
		else
		{
			selectBG.mAlpha = 0x00;
		}
	}

	CApplication::theApp->mMouseBtn = 0;
}

void CLobbyScene::onDraw(HDC hdc)
{
	mBG.Draw(hdc);
	for(CSprite selectBG : mSelectBGs)
		selectBG.Draw(hdc);

	HFONT oldFont = (HFONT)SelectObject(hdc, mFont);

	SetBkMode(hdc, TRANSPARENT);

	int left = 237;
	int right = 432;
	int y = 160;
	SetTextAlign(hdc, TA_LEFT);
	SetTextColor(hdc, RGB(227, 97, 0));

	TextOut(hdc, left, 129, L"시작 장소 선택", wcslen(L"시작 장소 선택"));
	TextOut(hdc, left+1, 129, L"시작 장소 선택", wcslen(L"시작 장소 선택"));

	for (SaveFile save : saveFiles)
	{
		wchar_t timeStr[8];
		swprintf_s(timeStr, 8, L"%d분", save.playTime);
		
		SetTextColor(hdc, RGB(0, 113, 130));
		TextOut(hdc, left + 1, y, save.saveName, wcslen(save.saveName));
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOut(hdc, left, y, save.saveName, wcslen(save.saveName));

		SetTextAlign(hdc, TA_RIGHT);
		
		SetTextColor(hdc, RGB(0, 113, 130));
		TextOut(hdc, right, y, timeStr, wcslen(timeStr));
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOut(hdc, right - 1, y, timeStr, wcslen(timeStr));
		
		y += 16;
		SetTextAlign(hdc, TA_LEFT);
	}
	SetTextColor(hdc, RGB(0, 113, 130));
	TextOut(hdc, left+1, 241, L"처음부터", wcslen(L"처음부터"));
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, left, 241, L"처음부터", wcslen(L"처음부터"));

	SelectObject(hdc, oldFont);
	DeleteObject(oldFont);
}
