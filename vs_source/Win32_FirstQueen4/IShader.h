#pragma once
#include "pch.h"


class IShader
{
public:
	IShader(HBITMAP hBitmap, UINT32* Color, int imgWidth, int imgHeight)
		:mhBitmap(hBitmap), mPixel(Color), imgWidth(imgWidth), imgHeight(imgHeight)
	{

	}
public:
	HBITMAP mhBitmap;
	UINT32* mPixel;
	int imgWidth;
	int imgHeight;

public:
	virtual UINT32* Execute() = 0;
};