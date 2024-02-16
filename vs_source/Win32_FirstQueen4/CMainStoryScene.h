#pragma once
#include "IScene.h"
#include "CSprite.h"
#include "CCharacter.h"

class CMainStoryScene : IScene
{
public:
	CMainStoryScene();
	~CMainStoryScene();

	virtual bool isFinished() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;

public:
	std::map<const std::string, CImageFile*> mImages;
	std::map<const std::string, CSprite> mSprites;
	std::map<const std::string, LPCWSTR> CharacterScripts;
	std::map<const std::string, CCharacter*> mCharacters;

	HFONT mFont;

	int sleepTime = 1;
	float timeDelta = 0.0f;
};

