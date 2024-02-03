#pragma once
#include "GameManager.h"

class Tetrimino
{
	std::vector<std::vector<int>> Shape;
	DWORD color;

	TetriminoType type;

public:
	Tetrimino(TetriminoType type);
	std::vector<std::vector<int>> GetShape();
	DWORD GetColor();

	int PosX;
	int PosY;

	void Rotate(bool isReverse);
};
