#pragma once
//#include "CIntroScene.h"

class CIntroScene;

class CGame
{
public:
	void onCreate();
	void onDestroy();
	void onFrameMove();
	void onDraw(HDC hdc);

	CIntroScene* mIntroScene;
};

