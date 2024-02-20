#pragma once
#include "CSprite.h"

class CCharacter
{
public:
	struct Item
	{
		LPCWSTR name;
		int ST;
		int FT;
		int HP;
	};

	enum Status
	{
		IDLE,
		ATTACK,
		MOVE,
		BE_HITTED
	};

public:
	CCharacter();
	~CCharacter();

	virtual void Move();
	virtual void Talk();
	virtual void onDraw(HDC hdc);
	virtual void Update();

public:
	std::map<std::string, CImageFile*> mImages;
	std::map<std::string, CSprite> mSprites;
	std::vector<Item> mItems;

	HFONT mFont;

	Status mStatus;

	int mLevel;
	LPCWSTR mName;
	int mST;
	int mFT;
	int mHP;
};

