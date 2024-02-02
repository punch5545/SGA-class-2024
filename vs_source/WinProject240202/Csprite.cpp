#include "pch.h"
#include "CImagefile.h"
#include "Csprite.h"

void CSprite::setSprite(int dx, int dy, int srcx, int srcy, TDrawType Dt, UINT color, CImageFile* file)
{
	 mdestX =dx;
	 mdestY = dy;
	 mSrcX = srcx;
	 mSrcY = srcy;
	 mSrcWidth = file->Width();
	 mSrcHeight = file->Height();
	 mImgFile = file;
	 mTransColor = color;
	 mDrawType = Dt;
}

void CSprite::Draw(HDC hdc)
{
	switch (mDrawType)
	{
	case DrawType_Draw:
		mImgFile->Draw(hdc,
			mdestX, mdestY,
			mSrcX, mSrcY,
			mSrcWidth, mSrcHeight);
			break;
	case DrawType_Transparent:
		mImgFile->transDraw(hdc, mdestX, mdestY, mSrcX, mSrcY, mSrcWidth, mSrcHeight,mTransColor);
		break;
	default:
		break;
	}
}
