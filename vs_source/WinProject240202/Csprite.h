#pragma once
#include "CImagefile.h"

class CSprite
{
public:
	int mdestX;
	int mdestY;
	int mdestWidth;
	int mdestHeight;

	int mSrcX;
	int mSrcY;
	int mSrcWidth;
	int mSrcHeight;

	UINT mTransColor;
	
public:
	enum TDrawType {
		DrawType_Transparent,
		DrawType_Draw,
	};


	TDrawType mDrawType;

	CImageFile* mImgFile;

	void setSprite(int dx, int dy, int srcx, int srcy, TDrawType Dt, UINT color, CImageFile* file);
	void Draw(HDC hdc);
};

