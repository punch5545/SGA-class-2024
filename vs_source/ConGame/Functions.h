#pragma once

#define SQUARE_IDX 0
#define Z_IDX 1
#define Z_REVERSE_IDX 2
#define L_IDX 3
#define L_REVERSE_IDX 4
#define T_IDX 5
#define I_IDX 6

typedef struct Tetrimino {
	int bricks[4][4];
	int rotate;
} Tetrimino;

const char* BrickSym = "กแ";

Tetrimino tetriminos[7];
bool isStart = false;

void MoveCursor(int x, int y);
void exitApp();

void printAnimation(int index);
void printHead();
void printFoot(bool isLoop);
void PrintBackground();


void PrintToPos(const char* str, int x, int y);
void PrintBlock(int index, int rotationState, int x, int y);

void InitBlocks();
void StartGame();

Tetrimino RotateBlock(Tetrimino tetrimino, int rotate);

void InitBlocks()
{
	// Square
	tetriminos[0] = {
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		0
	};
	// Z
	tetriminos[1] = {
		{
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		2
	};
	// Z-Reverse
	tetriminos[2] = {
		{
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		2
	};
	// L
	tetriminos[3] = {
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		4
	};
	// L-Reverse
	tetriminos[4] = {
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		4
	};
	// T
	tetriminos[5] = {
		{
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		4
	};
	// I
	tetriminos[6] = {
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		2
	};
}

void StartGame()
{
	isStart = true;

	InitBlocks();
	system("cls");
	PrintBackground();

	PrintBlock(1, 0, 3, 3);
	PrintBlock(1, 1, 10, 3);

}

void MoveCursor(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void exitApp()
{
	exit(0);
}

void PrintBackground()
{
	int rightWall = 118;
	const char* symbol = isStart ? "กเ" : "กแ";

	if (isStart)
	{
		rightWall = 22;
		PrintToPos("กเกเกเกเกเกเกเกเกเกเกเกเ", 0, 0);
		PrintToPos("กเกเกเกเกเกเกเกเกเกเกเกเ", 0, 29);
	}
	else
	{
		PrintToPos("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ", 0, 0);
		PrintToPos("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ", 0, 29);
	}
	for (int i = 0; i < 29; i++)
	{
		PrintToPos(symbol, 0, i);
		PrintToPos(symbol, rightWall, i);
	}
}

void printAnimation(int index)
{
	switch (index) {
	case 0:
		PrintToPos("กแ                                                                                                                    กแ", 0, 4);
		PrintToPos("กแ                                                                                                                    กแ", 0, 5);
		PrintToPos("กแ                                                                                                                    กแ", 0, 6);
		PrintToPos("กแ                                                                                                                    กแ", 0, 7);
		PrintToPos("กแ                                                                                                                    กแ", 0, 8);
		PrintToPos("กแ                                                                                                                    กแ", 0, 9);
		PrintToPos("กแ                                                                                                                    กแ", 0, 10);
		PrintToPos("กแ                                                                                                                    กแ", 0, 11);
		PrintToPos("กแ                                                                                                                    กแ", 0, 12);
		PrintToPos("กแ                                                                                                                    กแ", 0, 13);
		break;
	case 1:
		PrintToPos("กแ      กเกเกเกเกเกเกเกเ                                                                                              กแ", 0, 4);
		PrintToPos("กแ      กเกเกเกเกเกเกเกเ                                                                                              กแ", 0, 5);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 6);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 7);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 8);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 9);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 10);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 11);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 12);
		PrintToPos("กแ            กเกเ                                                                                                    กแ", 0, 13);
		break;
	case 2:
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเกเ                                                                              กแ", 0, 4);
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเกเ                                                                              กแ", 0, 5);
		PrintToPos("กแ            กแกแ        กเกเ                                                                                        กแ", 0, 6);
		PrintToPos("กแ            กแกแ        กเกเ                                                                                        กแ", 0, 7);
		PrintToPos("กแ            กแกแ        กเกเกเกเกเกเกเ                                                                              กแ", 0, 8);
		PrintToPos("กแ            กแกแ        กเกเกเกเกเกเกเ                                                                              กแ", 0, 9);
		PrintToPos("กแ            กแกแ        กเกเ                                                                                        กแ", 0, 10);
		PrintToPos("กแ            กแกแ        กเกเ                                                                                        กแ", 0, 11);
		PrintToPos("กแ            กแกแ        กเกเกเกเกเกเกเ                                                                              กแ", 0, 12);
		PrintToPos("กแ            กแกแ        กเกเกเกเกเกเกเ                                                                              กแ", 0, 13);
		break;
	case 3:
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กเกเกเกเกเกเกเกเ                                                            กแ", 0, 4);
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กเกเกเกเกเกเกเกเ                                                            กแ", 0, 5);
		PrintToPos("กแ            กแกแ        กแกแ                  กเกเ                                                                  กแ", 0, 6);
		PrintToPos("กแ            กแกแ        กแกแ                  กเกเ                                                                  กแ", 0, 7);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กเกเ                                                                  กแ", 0, 8);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กเกเ                                                                  กแ", 0, 9);
		PrintToPos("กแ            กแกแ        กแกแ                  กเกเ                                                                  กแ", 0, 10);
		PrintToPos("กแ            กแกแ        กแกแ                  กเกเ                                                                  กแ", 0, 11);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กเกเ                                                                  กแ", 0, 12);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กเกเ                                                                  กแ", 0, 13);
		break;
	case 4:
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเ                                              กแ", 0, 4);
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเกเกเ                                          กแ", 0, 5);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กเกเ        กเกเ                                          กแ", 0, 6);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กเกเ        กเกเ                                          กแ", 0, 7);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กเกเกเกเกเกเ                                              กแ", 0, 8);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กเกเกเกเกเกเ                                              กแ", 0, 9);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กเกเ        กเกเ                                          กแ", 0, 10);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กเกเ        กเกเ                                          กแ", 0, 11);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กเกเ        กเกเ                                          กแ", 0, 12);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กเกเ        กเกเ                                          กแ", 0, 13);
		break;
	case 5:
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแ      กเกเกเกเกเกเกเกเ                        กแ", 0, 4);
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเกเกเ                        กแ", 0, 5);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กเกเ                              กแ", 0, 6);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กเกเ                              กแ", 0, 7);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กเกเ                              กแ", 0, 8);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กเกเ                              กแ", 0, 9);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กเกเ                              กแ", 0, 10);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กเกเ                              กแ", 0, 11);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กเกเกเกเกเกเกเกเ                        กแ", 0, 12);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กเกเกเกเกเกเกเกเ                        กแ", 0, 13);
		break;
	case 6:
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแ      กแกแกแกแกแกแกแกแ      กเกเกเกเกเกเ      กแ", 0, 4);
		PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ      กเกเกเกเกเกเ      กแ", 0, 5);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ        กเกเ                  กแ", 0, 6);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ        กเกเ                  กแ", 0, 7);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กแกแ        กเกเกเกเกเกเกเกเ      กแ", 0, 8);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กแกแ        กเกเกเกเกเกเกเกเ      กแ", 0, 9);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ                    กเกเ      กแ", 0, 10);
		PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ                    กเกเ      กแ", 0, 11);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเ          กแ", 0, 12);
		PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กแกแกแกแกแกแกแกแ  กเกเกเกเกเกเ          กแ", 0, 13);
		break;
	default:
		if (index % 2 == 0)
		{
			PrintToPos("กแ                                                                                                                    กแ", 0, 4);
			PrintToPos("กแ                                                                                                                    กแ", 0, 5);
			PrintToPos("กแ                                                                                                                    กแ", 0, 6);
			PrintToPos("กแ                                                                                                                    กแ", 0, 7);
			PrintToPos("กแ                                                                                                                    กแ", 0, 8);
			PrintToPos("กแ                                                                                                                    กแ", 0, 9);
			PrintToPos("กแ                                                                                                                    กแ", 0, 10);
			PrintToPos("กแ                                                                                                                    กแ", 0, 11);
			PrintToPos("กแ                                                                                                                    กแ", 0, 12);
			PrintToPos("กแ                                                                                                                    กแ", 0, 13);
		}
		else
		{
			PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแ      กแกแกแกแกแกแกแกแ      กแกแกแกแกแกแ      กแ", 0, 4);
			PrintToPos("กแ      กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแกแกแ      กแกแกแกแกแกแ      กแ", 0, 5);
			PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ        กแกแ                  กแ", 0, 6);
			PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ        กแกแ                  กแ", 0, 7);
			PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กแกแ        กแกแกแกแกแกแกแกแ      กแ", 0, 8);
			PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแกแกแกแกแ            กแกแ        กแกแกแกแกแกแกแกแ      กแ", 0, 9);
			PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ                    กแกแ      กแ", 0, 10);
			PrintToPos("กแ            กแกแ        กแกแ                  กแกแ        กแกแ        กแกแ        กแกแ                    กแกแ      กแ", 0, 11);
			PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแ          กแ", 0, 12);
			PrintToPos("กแ            กแกแ        กแกแกแกแกแกแกแ        กแกแ        กแกแ        กแกแ  กแกแกแกแกแกแกแกแ  กแกแกแกแกแกแ          กแ", 0, 13);
		}
	}
}

void printHead()
{
	printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
	printf("กแ                                                                                                                    กแ\n");
	printf("กแ                                                                                                                    กแ\n");
}

void printFoot(bool isLoop)
{
	if (isLoop)
	{
		PrintToPos("กแ                                                   กแ    กแกแ    กแกแกแ    กแกแ                                     กแ", 0, 17);
		PrintToPos("กแ                                   กแกแกแกแ    กแกแกแ    กแกแ      กแ        กแกแ                                   กแ", 0, 18);
		PrintToPos("กแ                                               PRESS ANY KEY TO START                                               กแ", 0, 22);
	}
	else
	{
		PrintToPos("กแ                                                   กแ    กแกแ    กแกแกแ    กแกแ                                     กแ", 0, 17);
		PrintToPos("กแ                                   กแกแกแกแ    กแกแกแ    กแกแ      กแ        กแกแ                                   กแ", 0, 18);
		PrintToPos("กแ                                                                                                                    กแ", 0, 22);
	}
}

void PrintToPos(const char* str, int x, int y)
{
	MoveCursor(x, y);
	printf(str);
}

void PrintBlock(int index, int rotationState, int x, int y)
{
	int n = 3;

	if (index == I_IDX) n = 4;
	Tetrimino tmp = RotateBlock(tetriminos[index], 1, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			PrintToPos(BrickSym, x, y);
		}
	}
}

Tetrimino RotateBlock(Tetrimino tetrimino, int rotate, int n)
{
	Tetrimino rotated;

	for (int rot = 0; rot < rotate; rot++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				rotated.bricks[i][j] = tetrimino.bricks[n-1 - j][i];
			}
		}
	}


	return rotated;
}


