#include "pch.h"
#include "CIntroScene.h"
#include "CImageFile.h"
#include "Resource.h"
#include "CGameFQ4.h"

#define TEXT_X 300
#define TEXT_Y(x) (280 + (x * 22))

#define OUTLINE_X 301
#define OUTLINE_Y(x) (281 + (x * 22))


CIntroScene::CIntroScene()
{
    this->mLionFile = new CImageFile(MAKEINTRESOURCE(IDB_LION));
    this->mBG.Set(0, 0, 0, 0, mLionFile, 0, CSprite::DrawType_Draw);

	current_x = 1;
	current_y = 0;

	dest_y = strList.size();
	dest_x = wcslen(strList[current_y]);
}

CIntroScene::~CIntroScene()
{
	DeleteObject(font);
    delete this->mLionFile;
}

bool CIntroScene::isFinished()
{
    return false;
}

void CIntroScene::onFrameMove()
{
	timeDelta+=0.2f;

	if (current_y < dest_y)
	{
		if (timeDelta >= 1.0f) {
			current_x++;
			timeDelta = 0;
		}

		if (current_x == dest_x - 1)
		{
			current_y = current_y < dest_y ? current_y + 1 : dest_y - 1;
			current_x = current_y < dest_y ? 0 : wcslen(strList[current_y - 1]) - 1;
			dest_x = current_y < dest_y ? wcslen(strList[current_y]) : wcslen(strList[current_y - 1]);
		}
	}

	
}

void CIntroScene::onDraw(HDC hdc)
{
    mBG.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextAlign(hdc, TA_CENTER);

	font = CreateFont(22, 8, 0, 0, FW_BOLD, 0, 0, 0, 
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, FF_DONTCARE, L"±Ã¼­Ã¼");
	oldfont = (HFONT)SelectObject(hdc, font);

	if (current_y == dest_y)
	{
		for (int i = 0; i < dest_y; i++)
		{
			SetTextColor(hdc, RGB(0, 0, 0));
			TextOut(hdc, OUTLINE_X, OUTLINE_Y(i), strList[i], wcslen(strList[i]));
			SetTextColor(hdc, RGB(255, 255, 255));
			TextOut(hdc, TEXT_X, TEXT_Y(i), strList[i], wcslen(strList[i]));
		}
	}
	else
	{
		for (int i = 0; i < current_y + 1; i++)
		{
			if (i != current_y)
			{
				SetTextColor(hdc, RGB(0, 0, 0));
				TextOut(hdc, OUTLINE_X, OUTLINE_Y(i), strList[i], wcslen(strList[i]));
				SetTextColor(hdc, RGB(255, 255, 255));
				TextOut(hdc, TEXT_X, TEXT_Y(i), strList[i], wcslen(strList[i]));
			}
			else
			{
				SetTextColor(hdc, RGB(0, 0, 0));
				TextOut(hdc, OUTLINE_X, OUTLINE_Y(i), strList[i], current_x);
				SetTextColor(hdc, RGB(255, 255, 255));
				TextOut(hdc, TEXT_X, TEXT_Y(i), strList[i], current_x);
			}
		}
	}
	
	SelectObject(hdc, oldfont);

	//TextOut(hdc, 300, 280 + (i * 20), strList[i], ++j);
}
