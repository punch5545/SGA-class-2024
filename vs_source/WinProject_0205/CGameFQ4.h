#pragma once
#include "IGame.h"

class CIntroScene;

class CGameFQ4 : public IGame
{
public:
	void onCreate();
	void onDestroy();

	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;

public:
	CIntroScene* mIntroScene;
};