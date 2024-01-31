#pragma once
class CImage
{
public:
	HBITMAP mHBitmap;
	BITMAP mInfo;

	CImage(const WCHAR* ResourceName);
	~CImage();

	int GetHeight() { return mInfo.bmHeight; }
	int GetWidth() { return mInfo.bmWidth; }

	void Draw(HDC hdc, int dx, int dy);
	void TransDraw(HDC hdc, int dx, int dy, UINT transColor);
};