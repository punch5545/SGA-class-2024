#pragma once

struct ImageConfig
{
	int dx, dy;
	int width, height;
};

class CGame
{
public:
	HINSTANCE mhInstance;

};

extern CGame* TheGame;