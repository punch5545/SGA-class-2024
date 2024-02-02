#pragma once
class CImageFile
{
public:
	HBITMAP  mhBitmap;
	BITMAP   mBmpInfo;

	CImageFile(const WCHAR* filename);
	~CImageFile();

	void Draw(HDC hdc, 
				int dest_x, int dest_y, //�׸����� Ÿ��
				int src_x, int src_y,   //���׸��� ��� �׸���
				int width, int height); //�׸��� ũ��


	void transDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color);
	int Height() const { return mBmpInfo.bmHeight; }
	int Width() const { return mBmpInfo.bmWidth; }

};

