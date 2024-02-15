#pragma once

class CImageFile
{
public:
	HBITMAP		mhBitmap;	//��Ʈ��
	BITMAP		mBmpInfo;	//��Ʈ�� ����

	CImageFile(const WCHAR* fileName);
	~CImageFile();

	void Draw	(HDC hdc, 
				 int dest_x, int dest_y,
				 int src_x,  int src_y, 
				 int width,  int height);
	void TransDraw(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height, 
		UINT color);
	//dest->ȭ�鿡 ��µ� ��� ��ǥ src->�׸� �׸��� ��ǥ, width heigth�׸� �׸��� ������
	void AlphaDraw(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height, 
		BYTE alpha);
	void FadeInOut(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha);

	int Height()	const{ return mBmpInfo.bmHeight;}
	int Width()		const{ return mBmpInfo.bmWidth; }//const ����ȭ�ϱ� ����


};

