#pragma once

class CMemoryBitmap
{
	HBITMAP m_Old;

public:
	HBITMAP m_hBitmap;
	HDC     m_HDC;

	Color* m_Colors;
	BITMAPINFO m_BMI;        // bitmap header

public:
	CMemoryBitmap(HDC hdcWnd, int width, int height);
	~CMemoryBitmap();

	Color getColor(int x, int y)			{ return m_Colors[y * m_BMI.bmiHeader.biWidth + x]; }
	void setColor(int x, int y, Color c)	{ m_Colors[y * m_BMI.bmiHeader.biWidth + x] = c; }

	int getWidth()							{ return m_BMI.bmiHeader.biWidth; }
	int getHeight()							{ return m_BMI.bmiHeader.biHeight; }

	void Clear(Color color = (255,255,255,0));
};

