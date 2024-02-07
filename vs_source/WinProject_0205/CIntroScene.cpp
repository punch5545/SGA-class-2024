#include "pch.h"
#include "CIntroScene.h"
#include "CImageFile.h"
#include "CGameFQ4.h"

#include "SceneManager.h"

CIntroScene::CIntroScene(const WCHAR* ResourceFilename,
	std::vector<LPCWSTR> strList)
		:OUTLINE_X(0), OUTLINE_Y(0), 
		 TEXT_X(0), TEXT_Y(0), 
		 current_x(0), current_y(0), 
		 dest_x(0), dest_y(0),
		 font(NULL), oldfont(NULL),
		strList(strList)
{
    this->mLionFile = new CImageFile(ResourceFilename);
    this->mBG.Set(0, 0, 0, 0, mLionFile, 0, CSprite::DrawType_FadeInOut);
	this->mBG.mAlpha = 0x00;

	current_x = 1;
	current_y = 0;

	dest_y = strList.size();
	dest_x = wcslen(strList[current_y]);
}

CIntroScene::~CIntroScene()
{
    delete this->mLionFile;
}

bool CIntroScene::isFinished()
{
    return false;
}

void CIntroScene::onFrameMove()
{
	timeDelta+=0.2f;

	if (goNext && timeDelta >= 20)
	{
		if (mBG.mAlpha <= 0x05)
		{
			mBG.mAlpha = 0x00;
			if (SceneManager::Manager->SceneIdx < SceneManager::Manager->SceneList.size())
			{
				SceneManager::Manager->SceneIdx++;
				SceneManager::Manager->LoadScene();
			}
		}
		else
		{
			showText = false;
			this->mBG.mAlpha -= 5;
		}
	}
	else
	{
		if (mBG.mAlpha >= 0xf0)
		{
			mBG.mAlpha = 0xff;
			showText = true;
		}
		else this->mBG.mAlpha += 5;
	}


	if (current_y < dest_y && showText)
	{
		if (timeDelta >= sleepTime) {
			current_x++;
			timeDelta = 0;
			sleepTime = 1;
		}

		if (current_x == dest_x - 1)
		{
			current_y = current_y < dest_y ? current_y + 1 : dest_y - 1;
			current_x = current_y < dest_y ? 0 : wcslen(strList[current_y - 1]) - 1;
			dest_x = current_y < dest_y ? wcslen(strList[current_y]) : wcslen(strList[current_y - 1]);
			sleepTime = 10;
		}
	}
}

void CIntroScene::onDraw(HDC hdc)
{
    mBG.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextAlign(hdc, TA_CENTER);

	font = CreateFont(22, 8, 0, 0, FW_BLACK, 0, 0, 0, 
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, FF_DONTCARE, L"±Ã¼­Ã¼");
	oldfont = (HFONT)SelectObject(hdc, font);


	if (showText)
	{
		if (current_y == dest_y)
		{
			for (int i = 0; i < dest_y; i++)
			{
				SetTextColor(hdc, RGB(0, 0, 0));
				TextOut(hdc, OUTLINE_X, OUTLINE_Y + (i * 22), strList[i], wcslen(strList[i]));
				TextOut(hdc, OUTLINE_X + 1, OUTLINE_Y + (i * 22) + 1, strList[i], wcslen(strList[i]));
				SetTextColor(hdc, RGB(255, 255, 255));
				TextOut(hdc, TEXT_X, TEXT_Y + (i * 22), strList[i], wcslen(strList[i]));
			}
			goNext = true;
		}
		else
		{
			for (int i = 0; i < current_y + 1; i++)
			{
				if (i != current_y)
				{
					SetTextColor(hdc, RGB(0, 0, 0));
					TextOut(hdc, OUTLINE_X, OUTLINE_Y + (i * 22), strList[i], wcslen(strList[i]));
					TextOut(hdc, OUTLINE_X + 1, OUTLINE_Y + (i * 22) + 1, strList[i], wcslen(strList[i]));
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOut(hdc, TEXT_X, TEXT_Y + (i * 22), strList[i], wcslen(strList[i]));
				}
				else
				{
					SetTextColor(hdc, RGB(0, 0, 0));
					TextOut(hdc, OUTLINE_X, OUTLINE_Y + (i * 22), strList[i], current_x);
					TextOut(hdc, OUTLINE_X + 1, OUTLINE_Y + (i * 22) + 1, strList[i], current_x);
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOut(hdc, TEXT_X, TEXT_Y + (i * 22), strList[i], current_x);
				}
			}
		}

	}
	
	SelectObject(hdc, oldfont);
	DeleteObject(font);

	//TextOut(hdc, 300, 280 + (i * 20), strList[i], ++j);
}
