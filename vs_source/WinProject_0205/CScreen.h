#pragma once
#include "CMemoryBitmap.h"

class CScreen
	: public CMemoryBitmap
{
public:
	CScreen(HDC hdcWnd, int width, int height)
		: CMemoryBitmap(hdcWnd, width, height) {}

	void Draw(HDC hdc);
};

