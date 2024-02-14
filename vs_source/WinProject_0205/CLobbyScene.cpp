#include "pch.h"
#include "CLobbyScene.h"

#include "CApplication.h"
#include "CGameFQ4.h"
#include "CImageFile.h"
#include "SceneManager.h"

#include "resource.h"

CLobbyScene::CLobbyScene()
	:mFont(NULL)
{
	mImageFile = new CImageFile(MAKEINTRESOURCE(IDB_LOBBY));
	mBG.Set(0, 0, 0, 0, mImageFile, 0, CSprite::DrawType_AlphaBlend);
	mBG.mAlpha = 0xFF;

	mFont = CreateFont(18, 6, 0, 0, FW_NORMAL, 0, 0, 0,
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, L"HY�߰��");

	saveFiles.push_back(SaveFile(L".\\", L"������/����", 391));
	saveFiles.push_back(SaveFile(L".\\", L"�츮��",		80));
	saveFiles.push_back(SaveFile(L".\\", L"ī���¼�",	10));
	saveFiles.push_back(SaveFile(L".\\", L"������",		8));
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
}


/*
225,130
225,160          432
225,176 +16
225,192
225,208
225,242
*/

void CLobbyScene::onDraw(HDC hdc)
{
	mBG.Draw(hdc);

	HFONT oldFont = (HFONT)SelectObject(hdc, mFont);

	SetBkMode(hdc, TRANSPARENT);

	int left = 225;
	int right = 432;
	int y = 160;
	SetTextAlign(hdc, TA_LEFT);
	SetTextColor(hdc, RGB(227, 97, 0));

	TextOut(hdc, left, 129, L"���� ����� ����", wcslen(L"���� ����� ����"));
	TextOut(hdc, left+1, 129, L"���� ����� ����", wcslen(L"���� ����� ����"));

	for (SaveFile save : saveFiles)
	{

		wchar_t timeStr[8];
		swprintf_s(timeStr, 8, L"%d��", save.playTime);
		
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
	TextOut(hdc, left+1, 241, L"ó������", wcslen(L"ó������"));
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, left, 241, L"ó������", wcslen(L"ó������"));

	SelectObject(hdc, oldFont);
	DeleteObject(oldFont);
}
