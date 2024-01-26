#pragma once

class Tetrimino
{
	int PosX;
	int PosY;

	std::string color;

	int Shape[4][4];
	TetriminoType type;

	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void HardDown();

public:
	Tetrimino(TetriminoType type);

	void Draw();

	void MoveTo(Direction dir);
	void Rotate(bool isReverse);
	bool CheckCollision();
	bool CheckBottomCollision();

	int GetPosX();
	int GetPosY();
};