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

	std::vector<CALLBACK_FUNC> clickEvents;

public:
	CSprite() : 
		mDestX(0),
		mDestY(0),
		mDestWidth(0),
		mDestHeight(0),
		mSrcX(0),
		mSrcY(0),
		mSrcWidth(0),
		mSrcHeight(0), 
		mAlpha(0x00),
		mTransColor(0),
		mDrawType(DrawType_Draw),
		mImgFile(NULL)
	{

	};
public:
	void Set(int dx, int dy, int sx, int sy, CImageFile* img, UINT color, TDrawType dt);
	void Draw(HDC hdc);
	bool IsInRect(int x, int y);
	bool IsInRect(Vector2 pos);
	bool IsInRect(int x, int y, int width, int height);
	bool IsInRect(RECT rect);

	bool isClicked(int x, int y);
	void onClick();

	void addClickEvent(CALLBACK_FUNC func);
};