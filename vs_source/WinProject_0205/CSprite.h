#pragma once
class CImageFile;

class CSprite
{
public:
	int mDestX;
	int mDestY;
	int mDestWidth;
	int mDestHeight;

	int mSrcX;
	int mSrcY;
	int mSrcWidth;
	int mSrcHeight;

	UINT mTransColor;//크로마키 색상
	
public:
	enum TDrawType{
		DrawType_Draw,
		DrawType_Transparent, 
		DrawType_AlphaBlend,
		DrawType_FadeInOut,
	};
	TDrawType mDrawType;

	CImageFile* mImgFile;

	BYTE mAlpha;

public:
	CSprite() : mAlpha(0xFF) {};
	void Set(int dx, int dy, int sx, int sy, CImageFile* img, UINT color, TDrawType dt);
	void Draw(HDC hdc);
};

