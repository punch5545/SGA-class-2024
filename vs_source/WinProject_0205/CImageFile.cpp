#include "pch.h"
#include "CImagefile.h"
#include "CApplication.h"

#pragma comment(lib,"Msimg32.lib")

CImageFile::CImageFile(const WCHAR* fileName)
{
	mhBitmap = LoadBitmapW(CApplication::theApp->mhInst, fileName);//생성
	GetObject(mhBitmap, sizeof(BITMAP), &mBmpInfo);
}

CImageFile::~CImageFile()
{
	DeleteObject(mhBitmap);//삭제
}

void CImageFile::Draw	(HDC hdc,
						 int dest_x, int dest_y,
						 int src_x,  int src_y,
						 int width,  int height)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC,mhBitmap);
	BitBlt(hdc, 
		dest_x, dest_y,
		width, height,
		hBmpDC, 
		src_x, src_y, SRCCOPY);

	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}

void CImageFile::TransDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);

	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);
	TransparentBlt(hdc,
		dest_x, dest_y,	width, height,
		hBmpDC,
		src_x, src_y, width, height,
		color);

	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}

void CImageFile::FadeInOut(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	BLENDFUNCTION bf;


	BITMAPINFO bmi;        // bitmap header
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;

	VOID* pvBits;          // pointer to DIB section 
	HDC hdc = CreateCompatibleDC(hdcWnd);
	HBITMAP hbitmapDIB = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	SelectObject(hdc, hbitmapDIB);

	UINT32 rgba = alpha;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			((UINT32*)pvBits)[y * width + x] = 0xFF000000;


	{
		HDC hBmpDC = CreateCompatibleDC(hdcWnd);
		HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = alpha;
		bf.AlphaFormat = 0;
		AlphaBlend(hdc, 0, 0, width, height,
			hBmpDC, src_x, src_y, width, height,
			bf);


		SelectObject(hBmpDC, old);
		DeleteDC(hBmpDC);
	}


	//bf.SourceConstantAlpha = 0xff;
	//bf.AlphaFormat = AC_SRC_ALPHA;

	//AlphaBlend(hdcWnd,
	//	dest_x, dest_y, width, height,
	//	hdc, 
	//	0, 0, width, height,
	//	bf);
	BitBlt(hdcWnd, dest_x, dest_y, width, height,
		hdc, 0, 0, SRCCOPY);


	DeleteObject(hbitmapDIB);
	DeleteDC(hdc);

}


void CImageFile::AlphaDraw(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	HDC hBmpDC = CreateCompatibleDC(hdcWnd);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = alpha;
	bf.AlphaFormat = 0;
	AlphaBlend(hdcWnd, dest_x, dest_y, width, height,
		hBmpDC, src_x, src_y, width, height,
		bf);

	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}

