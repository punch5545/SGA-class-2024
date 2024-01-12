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

const char* BrickSym = "¡á";

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
	const char* symbol = isStart ? "¡à" : "¡á";

	if (isStart)
	{
		rightWall = 22;
		PrintToPos("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à", 0, 0);
		PrintToPos("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à", 0, 29);
	}
	else
	{
		PrintToPos("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á", 0, 0);
		PrintToPos("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á", 0, 29);
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
		PrintToPos("¡á                                                                                                                    ¡á", 0, 4);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 5);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 6);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 7);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 8);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 9);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 10);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 11);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 12);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 13);
		break;
	case 1:
		PrintToPos("¡á      ¡à¡à¡à¡à¡à¡à¡à¡à                                                                                              ¡á", 0, 4);
		PrintToPos("¡á      ¡à¡à¡à¡à¡à¡à¡à¡à                                                                                              ¡á", 0, 5);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 6);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 7);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 8);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 9);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 10);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 11);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 12);
		PrintToPos("¡á            ¡à¡à                                                                                                    ¡á", 0, 13);
		break;
	case 2:
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 4);
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 5);
		PrintToPos("¡á            ¡á¡á        ¡à¡à                                                                                        ¡á", 0, 6);
		PrintToPos("¡á            ¡á¡á        ¡à¡à                                                                                        ¡á", 0, 7);
		PrintToPos("¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 8);
		PrintToPos("¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 9);
		PrintToPos("¡á            ¡á¡á        ¡à¡à                                                                                        ¡á", 0, 10);
		PrintToPos("¡á            ¡á¡á        ¡à¡à                                                                                        ¡á", 0, 11);
		PrintToPos("¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 12);
		PrintToPos("¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à                                                                              ¡á", 0, 13);
		break;
	case 3:
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                                                            ¡á", 0, 4);
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                                                            ¡á", 0, 5);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡à¡à                                                                  ¡á", 0, 6);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡à¡à                                                                  ¡á", 0, 7);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡à¡à                                                                  ¡á", 0, 8);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡à¡à                                                                  ¡á", 0, 9);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡à¡à                                                                  ¡á", 0, 10);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡à¡à                                                                  ¡á", 0, 11);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡à¡à                                                                  ¡á", 0, 12);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡à¡à                                                                  ¡á", 0, 13);
		break;
	case 4:
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à                                              ¡á", 0, 4);
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                                          ¡á", 0, 5);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 6);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 7);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡à¡à¡à¡à¡à¡à                                              ¡á", 0, 8);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡à¡à¡à¡à¡à¡à                                              ¡á", 0, 9);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 10);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 11);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 12);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡à¡à        ¡à¡à                                          ¡á", 0, 13);
		break;
	case 5:
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á      ¡à¡à¡à¡à¡à¡à¡à¡à                        ¡á", 0, 4);
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                        ¡á", 0, 5);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                              ¡á", 0, 6);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                              ¡á", 0, 7);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡à¡à                              ¡á", 0, 8);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡à¡à                              ¡á", 0, 9);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                              ¡á", 0, 10);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                              ¡á", 0, 11);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                        ¡á", 0, 12);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡à¡à¡à¡à¡à¡à¡à¡à                        ¡á", 0, 13);
		break;
	case 6:
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á¡á¡á      ¡à¡à¡à¡à¡à¡à      ¡á", 0, 4);
		PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á      ¡à¡à¡à¡à¡à¡à      ¡á", 0, 5);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                  ¡á", 0, 6);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á        ¡à¡à                  ¡á", 0, 7);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à¡à      ¡á", 0, 8);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡á¡á        ¡à¡à¡à¡à¡à¡à¡à¡à      ¡á", 0, 9);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                    ¡à¡à      ¡á", 0, 10);
		PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                    ¡à¡à      ¡á", 0, 11);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à          ¡á", 0, 12);
		PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡à¡à¡à¡à¡à¡à          ¡á", 0, 13);
		break;
	default:
		if (index % 2 == 0)
		{
			PrintToPos("¡á                                                                                                                    ¡á", 0, 4);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 5);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 6);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 7);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 8);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 9);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 10);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 11);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 12);
			PrintToPos("¡á                                                                                                                    ¡á", 0, 13);
		}
		else
		{
			PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á      ¡á", 0, 4);
			PrintToPos("¡á      ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á      ¡á¡á¡á¡á¡á¡á      ¡á", 0, 5);
			PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                  ¡á", 0, 6);
			PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                  ¡á", 0, 7);
			PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á¡á      ¡á", 0, 8);
			PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á¡á¡á¡á¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á¡á      ¡á", 0, 9);
			PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                    ¡á¡á      ¡á", 0, 10);
			PrintToPos("¡á            ¡á¡á        ¡á¡á                  ¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á                    ¡á¡á      ¡á", 0, 11);
			PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á          ¡á", 0, 12);
			PrintToPos("¡á            ¡á¡á        ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á        ¡á¡á        ¡á¡á  ¡á¡á¡á¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á¡á          ¡á", 0, 13);
		}
	}
}

void printHead()
{
	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n");
	printf("¡á                                                                                                                    ¡á\n");
	printf("¡á                                                                                                                    ¡á\n");
}

void printFoot(bool isLoop)
{
	if (isLoop)
	{
		PrintToPos("¡á                                                   ¡á    ¡á¡á    ¡á¡á¡á    ¡á¡á                                     ¡á", 0, 17);
		PrintToPos("¡á                                   ¡á¡á¡á¡á    ¡á¡á¡á    ¡á¡á      ¡á        ¡á¡á                                   ¡á", 0, 18);
		PrintToPos("¡á                                               PRESS ANY KEY TO START                                               ¡á", 0, 22);
	}
	else
	{
		PrintToPos("¡á                                                   ¡á    ¡á¡á    ¡á¡á¡á    ¡á¡á                                     ¡á", 0, 17);
		PrintToPos("¡á                                   ¡á¡á¡á¡á    ¡á¡á¡á    ¡á¡á      ¡á        ¡á¡á                                   ¡á", 0, 18);
		PrintToPos("¡á                                                                                                                    ¡á", 0, 22);
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


