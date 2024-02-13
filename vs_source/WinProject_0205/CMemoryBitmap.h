#pragma once

class CMemoryBitmap
{
	HBITMAP m_Old;

public:
	HBITMAP m_hBitmap;
	HDC     m_HDC;

	UINT32* m_Colors;
	BITMAPINFO m_BMI;        // bitmap header

public:
	CMemoryBitmap(HDC hdcWnd, int width, int height);
	~CMemoryBitmap();

	UINT32 getColor(int x, int y)			{ return m_Colors[y * m_BMI.bmiHeader.biWidth + x]; }
	void setColor(int x, int y, UINT32 c)	{ m_Colors[y * m_BMI.bmiHeader.biWidth + x] = c; }



	int getWidth()							{ return m_BMI.bmiHeader.biWidth; }
	int getHeight()							{ return m_BMI.bmiHeader.biHeight; }

	void Clear(UINT32 color = 0xFF000000);
};

