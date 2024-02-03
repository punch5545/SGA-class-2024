#include "pch.h"
#include "Tetrimino.h"

Tetrimino::Tetrimino(TetriminoType type)
	: PosX(5), PosY(2), type(type)
{
	switch (type)
	{
	case Square:
		color = COLOR_YELLOW;
		Shape = {
			{1, 1},
			{1, 1}
		};
		break;
	case Z:
		color = COLOR_RED;
		Shape = {
			{1, 1, 0},
			{0, 1, 1}
		};

		break;
	case Z_Reverse:
		color = COLOR_GREEN;
		Shape = {
			{0, 1, 1},
			{1, 1, 0}
		};
		break;
	case L:
		color = COLOR_ORANGE;
		Shape = {
			{1, 0},
			{1, 0},
			{1, 1}
		};
		break;
	case L_Reverse:
		color = COLOR_BLUE;
		Shape = {
			{0, 1},
			{0, 1},
			{1, 1}
		};
		break;
	case T:
		color = COLOR_PURPLE;
		Shape = {
			{1, 1, 1},
			{0, 1, 0}
		};
		break;
	case I:
		color = COLOR_CYAN;
		Shape = {
			{1},
			{1},
			{1},
			{1}
		};
		break;
	default: break;
	}
}

void Tetrimino::Rotate(bool isReverse)
{
	std::vector<std::vector<int>> temp = this->Shape;
	int n = temp.size();
	int m = temp[0].size();
	std::vector<std::vector<int>> newShape(m, std::vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (newShape[m - 1 - j][i] == 1 && (PosX + i > 9 || GameManager::m_TetrisMap[PosY+j][PosX+i].Data == 1))
				PosX--;
			while (newShape[m - 1 - j][i] == 1 && (PosX + i < 0 || GameManager::m_TetrisMap[PosY + j][PosX + i].Data == 1))
				PosX++;

			if (isReverse)
			{
				newShape[m - 1 - j][i] = temp[i][j];
			}
			else
			{
				newShape[j][n - 1 - i] = temp[i][j];
			}
		}
	}



	this->Shape = newShape;
}

std::vector<std::vector<int>> Tetrimino::GetShape() { return this->Shape; }

DWORD Tetrimino::GetColor()
{
	return color;
}
