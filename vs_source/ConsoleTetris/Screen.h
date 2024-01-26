#pragma once

class Screen
{
	Pixel Buffer[SCREEN_SIZE_Y][SCREEN_SIZE_X];

public:

	void* GetBuffer();
	void SetBuffer(int sx, int sy, Pixel** buf);

	void Print();

	Screen();
	~Screen();
};

