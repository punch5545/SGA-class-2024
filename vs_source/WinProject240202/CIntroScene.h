#pragma once
#include "CScene.h"
#include "CSprite.h"
//#include "CImagefile.h"

class CImageFile;

class CIntroScene : public CScene
{
public:
	CIntroScene();
	~CIntroScene();

	void onFrameMove();
	void onDraw(HDC hdc);

public:
	CImageFile* mLionFile;
	CSprite mLionSprite;
};
