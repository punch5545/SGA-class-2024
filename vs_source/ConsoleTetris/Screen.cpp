#include "pch.h"
#include "Screen.h"


void* Screen::GetBuffer()
{
	return this->Buffer;
}

void Screen::SetBuffer(int sx, int sy, Pixel** buf)
{
	for (int y = sy; y < SCREEN_SIZE_Y; y++)
	{
		for (int x = sx; x < SCREEN_SIZE_X; x++)
		{
			this->Buffer[y][x] = buf[y][x];
		}
	}
}

void Screen::Print()
{
	for (int y = 0; y < SCREEN_SIZE_Y; y++)
	{
		for (int x = 0; x < SCREEN_SIZE_X; x++)
		{

		}
	}
}

Screen::Screen()
{
	Pixel pixel;
	pixel.Shape = -1;
	pixel.Index = -1;

	for (int y = 0; y < SCREEN_SIZE_Y; y++)
	{
		for (int x = 0; x < SCREEN_SIZE_X; x++)
		{
			this->Buffer[y][x] = pixel;
		}
	}
}

Screen::~Screen()
{
}
