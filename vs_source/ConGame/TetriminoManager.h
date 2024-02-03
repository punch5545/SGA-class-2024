#pragma once

#include "Tetrimino.h"

class TetriminoManager
{
	std::vector<Tetrimino*> m_Tetriminos;

public:
	Tetrimino* CurrentTetrimino = nullptr;
	Tetrimino* NextTetrimino = nullptr;
	Tetrimino* HoldTetrimino = nullptr;

	Tetrimino* GhostTetrimino = nullptr;

	void Input(Direction dir);
	void Rotation(bool isReverse);

	void Init();
	void Update();
	void Render();

	void SetNextTetrimino();
	void SetHoldTetrimino();

	TetriminoManager();
	~TetriminoManager();
};