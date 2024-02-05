#include "pch.h"
#include "CImageFile.h"
#include "CApplication.h"

#pragma comment(lib, "Msimg32.lib")

CImageFile::CImageFile(const WCHAR* fileName)
{
    mhBitmap = LoadBitmapW(CApplication::theApp->mhInst, fileName);
    GetObject(mhBitmap, sizeof(BITMAP), &mBmpInfo);
}

CImageFile::~CImageFile()
{
    DeleteObject(mhBitmap);
}

void CImageFile::Draw(HDC hdc, 
                      int dest_x, int dest_y, 
                      int src_x, int src_y, 
                      int width, int height)
{
    HDC hBmpDC = CreateCompatibleDC(hdc);
    HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);
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
        dest_x, dest_y, width, height,
        hBmpDC,
        src_x, src_y, width, height,
        color);


    SelectObject(hBmpDC, old);
    DeleteDC(hBmpDC);
}
