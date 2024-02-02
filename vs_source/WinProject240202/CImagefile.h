#pragma once
class CImageFile
{
public:
	HBITMAP  mhBitmap;
	BITMAP   mBmpInfo;

	CImageFile(const WCHAR* filename);
	~CImageFile();

	void Draw(HDC hdc, 
				int dest_x, int dest_y, //그릴려는 타겟
				int src_x, int src_y,   //내그림을 어디에 그릴지
				int width, int height); //그림의 크기


	void transDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color);
	int Height() const { return mBmpInfo.bmHeight; }
	int Width() const { return mBmpInfo.bmWidth; }

};

