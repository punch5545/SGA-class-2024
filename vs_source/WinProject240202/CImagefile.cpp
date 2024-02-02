#include "pch.h"
#include "CImagefile.h"
#include "CApplication.h"
#pragma comment(lib, "Msimg32.lib")

CImageFile::CImageFile(const WCHAR* filename)
{
	mhBitmap = LoadBitmapW(CApplication::theApp->mhInstance, filename);
	GetObject(mhBitmap, sizeof(BITMAP), &mBmpInfo);

	//GetObject (관심있는 그래픽개체에 대한 핸들, 
	//			버퍼에 쓸 바이트 수, 
	//			지정된 그래픽개체에 대한 정보를 수신하는 버퍼에 대한 포인터)
}

CImageFile::~CImageFile()
{

	DeleteObject(mhBitmap);

}

void CImageFile::Draw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);


	BitBlt(hdc, dest_x, dest_y, width, height,
		hBmpDC, src_x, src_y, SRCCOPY);


	//지우기전에 되돌리기
	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}

void CImageFile::transDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color)
{
	HDC hBmpDC = CreateCompatibleDC(hdc);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);


	TransparentBlt(hdc, dest_x, dest_y, width, height,
		hBmpDC, 
		src_x, src_y,width, height,
		color);


	//지우기전에 되돌리기
	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}



