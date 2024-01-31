#include "pch.h"
#include "CImage.h"
#include "CGame.h"

CImage::CImage(const WCHAR* ResourceName)
{
	mHBitmap = LoadBitmapW(TheGame->mhInstance, ResourceName);
	GetObject(mHBitmap, sizeof(BITMAP), &mInfo);	
}

CImage::~CImage()
{
	DeleteObject(mHBitmap);
}

void CImage::Draw(HDC hdc, int dx, int dy)
{
	HDC hdcBmp = CreateCompatibleDC(hdc);

	HBITMAP old = (HBITMAP) SelectObject(hdcBmp, mHBitmap);

	BitBlt(hdc, dx, dy, GetWidth(), GetHeight(), 
		hdcBmp, 0, 0, SRCCOPY);

	SelectObject(hdcBmp, old);
	DeleteDC(hdcBmp);
}

void CImage::TransDraw(HDC hdc, int dx, int dy, UINT transColor)
{
	HDC hdcBmp = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hdcBmp, mHBitmap);

	TransparentBlt(hdc, dx, dy, GetWidth(), GetHeight(),
		hdcBmp, 0, 0, GetWidth(), GetHeight(), transColor);

	SelectObject(hdcBmp, old);
	DeleteDC(hdcBmp);
}
