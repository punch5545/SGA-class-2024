#include "pch.h"
#include "CText.h"

CText::CText()
{
	if(this->instance == NULL)	
		this->instance = new CText();
}

void CText::Out(HDC hdc, int width, int height, LPCWSTR fontName, int weight, LPCWSTR string)
{
	this->Out(hdc, width, height, fontName, weight, string, Color(0xFF000000), 0, 0, 0);
}

void CText::Out(HDC hdc, int width, int height, LPCWSTR fontName, 
	int weight, LPCWSTR string, Color color, bool italic, bool underline, bool strike)
{
	HFONT font = CreateFont(width, height, 0, 0, weight, italic, underline, strike,
		OEM_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, fontName);

	HFONT oldFont = (HFONT)SelectObject(hdc, font);

	SetTextColor(hdc, RGB(0, 0, 0));



	SelectObject(hdc, oldFont);
	DeleteObject(oldFont);
}
