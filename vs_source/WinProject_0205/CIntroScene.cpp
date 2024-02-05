#include "pch.h"
#include "CIntroScene.h"
#include "CImageFile.h"
#include "Resource.h"

CIntroScene::CIntroScene()
{
    this->mLionFile = new CImageFile(MAKEINTRESOURCE(IDB_LION));
    this->mBG.Set(0, 0, 0, 0, mLionFile, 0, CSprite::DrawType_Draw);

	this->strList = {
		L"-��-��-! ��~! ����, ���Ӵ�~!",
		L"�� ȥ�� ���� �Ҿ���� ������",
		L"�� ���� �� ����� �����ٵ���",
		L"����! ���ʿ��� ���Ⱑ ���� ���±�!",
		L"���ѷ��߰ڴ�. ���⸦ ���� �� ȥ�� �������Ρ�!"
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
