#include "pch.h"
#include "CIntroScene.h"
#include "CImageFile.h"
#include "Resource.h"

CIntroScene::CIntroScene()
{
    this->mLionFile = new CImageFile(MAKEINTRESOURCE(IDB_LION));
    this->mBG.Set(0, 0, 0, 0, mLionFile, 0, CSprite::DrawType_Draw);

	this->strList = {
		L"-아-아-! 으~! …괴, 괴롭다~!",
		L"내 혼에 열을 불어넣지 않으면",
		L"이 몸은 곧 사라져 버릴텐데…",
		L"…오! 북쪽에서 열기가 느껴 지는군!",
		L"서둘러야겠다. 열기를 따라 내 혼을 북쪽으로…!"
	};

	current_x = 1;
	current_y = 0;

	dest_x = wcslen(strList[current_y]);
	dest_y = strList.size();

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
	timeDelta+=0.1f;

	if (timeDelta >= 1.0f)
	{
		current_x++;
	}

	if (current_y <= dest_y)
	{
		if (current_x > dest_x)
		{
			current_x = 0;
			current_y = current_y + 1;
		}
	}
	else
	{
		current_x = 0;
		current_y = 0;
	}

}

void CIntroScene::onDraw(HDC hdc)
{
    mBG.Draw(hdc);

	TextOut(hdc, 300, 280 + (current_y * 20), strList[current_y], current_x);


	//SetBkMode(hdc, TRANSPARENT);
	//SetTextColor(hdc, RGB(255, 255, 255));
	//SetTextAlign(hdc, TA_CENTER);

	//TextOut(hdc, 300, 280 + (i * 20), strList[i], ++j);
}
