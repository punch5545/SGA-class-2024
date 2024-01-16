#pragma once
const char* BrickSym = "■";

int timeDelta = 0;

Tetrimino tetriminos[7];
bool isStart = false;
int deltaTime = 0;

void MoveCursor(int x, int y);
void exitApp();

void CursorView(BOOL cursorState)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = cursorState; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void MoveBlock(int key);
void printAnimation(int index);
void printFoot(bool isLoop);
void PrintBackground();


void PrintToPos(const char* str, int x, int y);
void PrintBlock(int x, int y);
void PrintBlock(int x, int y, bool isGhost);
void PrintNext();
void PrintHold();

void MoveLeft();
void MoveRight();
void MoveDown();
void HardDown();
void RemoveLine();

void PrintGhost();

void BlockToMap();

void InitBlocks();
void StartGame();
void Update();

void CheckGameOver();
void CheckBottomCollision();

Tetrimino RotateBlock(Tetrimino tetrimino, int rotate, int n);

Tetrimino CurrentBlock = {
	0,
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}, 0, 0, 0, 0
};

Tetrimino NextBlock = {
	0,
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}, 0, 0, 0, 0
};

Tetrimino HoldBlock = {
	0,
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}, 0, 0, 0, 0
};

int TetrisMap[22][12] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

void InitBlocks()
{
	// Square
	tetriminos[0] = {
		0,
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		0,0,0,0
	};
	// Z
	tetriminos[1] = {
		1,
		{
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		2, 0, 0, 0
	};
	// Z-Reverse
	tetriminos[2] = {
		2,
		{
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		2, 0, 0, 0
	};
	// L
	tetriminos[3] = {
		3,
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		4, 0, 0, 0
	};
	// L-Reverse
	tetriminos[4] = {
		4,
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		4, 0, 0, 0
	};
	// T
	tetriminos[5] = {
		5,
		{
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		4, 0, 0, 0
	};
	// I
	tetriminos[6] = {
		6,
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		2, 0, 0, 0
	};
}

void StartGame()
{
	time(NULL);
	srand((unsigned int)time(NULL));

	

	isStart = true;
	InitBlocks();
	
	PrintBackground();
	PrintToPos("HOLD", 31, 1);
	PrintToPos("NEXT", 31, 6);
	PrintBlock(15, 2);
	PrintBlock(15, 7);

	while (true)
	{
		Update();
		Sleep(FRAME_PER_SECOND);
	}
}
int i = 0;

void Update() {
	PrintBackground();

	if (CurrentBlock.y == 0)
	{
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		CurrentBlock.x = 4;
		CurrentBlock.y = 1;

		NextBlock = tetriminos[rand() % 7];
	}

	// Draw blocks
	if (_kbhit())
	{
		int key = _getch();
		MoveBlock(key);
	}

	if (deltaTime > (FRAME_RATE / 3))
	{
		CheckBottomCollision();

		CurrentBlock.y++;
		deltaTime = 0;
	}

	deltaTime++;
	PrintNext();
	PrintHold();
	
	PrintBlock(CurrentBlock.x, CurrentBlock.y);
	PrintGhost();

	CheckGameOver();
}


void MoveBlock(int key)
{
	bool isCollision = false;

	// Check collision, TetrisMap and CurrentBlock

	int x = CurrentBlock.x;
	int y = CurrentBlock.y;
	int n = 3;
	if (CurrentBlock.index == I_IDX) n = 4;

	switch (key)
	{
		case KEY_UP:
			CurrentBlock = RotateBlock(CurrentBlock, 1, n);
			break;
		case KEY_LEFT: MoveLeft();
			break;
		case KEY_RIGHT: MoveRight();
			break;
		case KEY_DOWN: MoveDown();
			break;
		case KEY_SPACE: HardDown();
			break;
		case KEY_ESC: exitApp();
			break;
		case KEY_ENTER:
			break;
		case KEY_C:
			break;
		case KEY_LEFT_CTRL:
			CurrentBlock = RotateBlock(CurrentBlock, -1, n);
			break;
		default: break;

	}
}

void CheckBottomCollision()
{
	bool isCollision = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (CurrentBlock.bricks[j][i] == 1 && TetrisMap[CurrentBlock.y + j + 1][CurrentBlock.x + i] == 1)
			{
				isCollision = true;
				break;
			}
		}
	}
	if (isCollision)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if(CurrentBlock.bricks[j][i] == 1)
					TetrisMap[CurrentBlock.y + j][CurrentBlock.x + i] = CurrentBlock.bricks[j][i];
			}
		}

		// Current block to Map, Create new block
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		CurrentBlock.x = 4;
		CurrentBlock.y = 1;
	}
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

	if (isStart)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				const char* symbol = TetrisMap[i][j] == 0 ? "  " : (i == 0 || i == 21 || j == 0 || j == 11) ? "□" : "▦";
				PrintToPos(symbol, j * 2, i);
			}
		}
	}
	else
	{
		PrintToPos("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 0, 0);
		PrintToPos("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 0, 29);
		for (int i = 0; i < 29; i++)
		{
			PrintToPos("■", 0, i);
			PrintToPos("■", 118, i);
		}
	}
}

void MoveLeft() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (CurrentBlock.bricks[y][x] == 1) {
				if (CurrentBlock.x + x - 1 < 0) 
					return; // 블럭의 오른쪽에 벽이 있거나 맵 밖이면 이동하지 않음

				if (CurrentBlock.y + y >= 0 && TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x - 1]) 
					return; // 블럭의 오른쪽에 다른 블럭이 있으면 이동하지 않음
				
			}
		}
	}
	// 충돌하지 않으면 왼쪽으로 이동
	CurrentBlock.x--;
	return;
}

void MoveRight() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (CurrentBlock.bricks[y][x] != 0) {
				if (CurrentBlock.x + x + 1 >= 11) 
					return; // 블럭의 오른쪽에 벽이 있거나 맵 밖이면 이동하지 않음

				if (CurrentBlock.y + y >= 0 && TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x + 1])
					return; // 블럭의 오른쪽에 다른 블럭이 있으면 이동하지 않음
			}
		}
	}
	// 충돌하지 않으면 오른쪽으로 이동
	CurrentBlock.x++;
	return;
}

void MoveDown() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (CurrentBlock.bricks[y][x] != 0) {
				if (CurrentBlock.y + y + 1 >= 21)
				{
					BlockToMap();
					RemoveLine();

					return;
				}
				if (TetrisMap[CurrentBlock.y + y + 1][CurrentBlock.x + x])
				{
					BlockToMap();
					RemoveLine();

					return;
				}
			}
		}
	}
	// 충돌하지 않으면 아래로 이동
	CurrentBlock.y++;
	return; 
}

void HardDown()
{
	while (true)
	{
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++)
			{
				if (CurrentBlock.bricks[y][x] != 0)
				{
					if (CurrentBlock.y + y + 1 >= 21)
					{
						BlockToMap();
						RemoveLine();

						return;
					}
					if (TetrisMap[CurrentBlock.y + y + 1][CurrentBlock.x + x])
					{
						BlockToMap();
						RemoveLine();

						return;
					}
				}
			}
		}
		// 충돌하지 않으면 아래로 이동
		CurrentBlock.y++;
		//PrintBackground();
		PrintBlock(CurrentBlock.x, CurrentBlock.y);
		//Sleep(1);
	}
}

void RemoveLine()
{
	for (int i = 1; i < 21; i++)
	{

	}
}


void BlockToMap()
{
// 블럭을 맵에 추가
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++)
		{
			if (CurrentBlock.bricks[y][x] != 0)
				TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x] = CurrentBlock.bricks[y][x];
		}
	}

	// 블럭 생성
	int startBlock = rand() % 7;
	CurrentBlock = NextBlock;
	NextBlock = tetriminos[startBlock];

	CurrentBlock.x = 4;
	CurrentBlock.y = 1;
}


void printAnimation(int index)
{
	switch (index) {
	case 0:
		PrintToPos("■                                                                                                                    ■", 0, 4);
		PrintToPos("■                                                                                                                    ■", 0, 5);
		PrintToPos("■                                                                                                                    ■", 0, 6);
		PrintToPos("■                                                                                                                    ■", 0, 7);
		PrintToPos("■                                                                                                                    ■", 0, 8);
		PrintToPos("■                                                                                                                    ■", 0, 9);
		PrintToPos("■                                                                                                                    ■", 0, 10);
		PrintToPos("■                                                                                                                    ■", 0, 11);
		PrintToPos("■                                                                                                                    ■", 0, 12);
		PrintToPos("■                                                                                                                    ■", 0, 13);
		break;
	case 1:
		PrintToPos("■      □□□□□□□□                                                                                              ■", 0, 4);
		PrintToPos("■      □□□□□□□□                                                                                              ■", 0, 5);
		PrintToPos("■            □□                                                                                                    ■", 0, 6);
		PrintToPos("■            □□                                                                                                    ■", 0, 7);
		PrintToPos("■            □□                                                                                                    ■", 0, 8);
		PrintToPos("■            □□                                                                                                    ■", 0, 9);
		PrintToPos("■            □□                                                                                                    ■", 0, 10);
		PrintToPos("■            □□                                                                                                    ■", 0, 11);
		PrintToPos("■            □□                                                                                                    ■", 0, 12);
		PrintToPos("■            □□                                                                                                    ■", 0, 13);
		break;
	case 2:
		PrintToPos("■      ■■■■■■■■  □□□□□□□                                                                              ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  □□□□□□□                                                                              ■", 0, 5);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 6);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 7);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 8);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 9);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 10);
		PrintToPos("■            ■■        □□                                                                                        ■", 0, 11);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 12);
		PrintToPos("■            ■■        □□□□□□□                                                                              ■", 0, 13);
		break;
	case 3:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  □□□□□□□□                                                            ■", 0, 5);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 6);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 9);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 10);
		PrintToPos("■            ■■        ■■                  □□                                                                  ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        □□                                                                  ■", 0, 13);
		break;
	case 4:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□                                              ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  □□□□□□□□                                          ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□□□□□                                              ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        □□        □□                                          ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        □□        □□                                          ■", 0, 13);
		break;
	case 5:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      □□□□□□□□                        ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  □□□□□□□□                        ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            □□                              ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        □□                              ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  □□□□□□□□                        ■", 0, 13);
		break;
	case 6:
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      □□□□□□      ■", 0, 4);
		PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      □□□□□□      ■", 0, 5);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■", 0, 6);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        □□                  ■", 0, 7);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■", 0, 8);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        □□□□□□□□      ■", 0, 9);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■", 0, 10);
		PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    □□      ■", 0, 11);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■", 0, 12);
		PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  □□□□□□          ■", 0, 13);
		break;
	default:
		if (index % 2 == 0)
		{
			PrintToPos("■                                                                                                                    ■", 0, 4);
			PrintToPos("■                                                                                                                    ■", 0, 5);
			PrintToPos("■                                                                                                                    ■", 0, 6);
			PrintToPos("■                                                                                                                    ■", 0, 7);
			PrintToPos("■                                                                                                                    ■", 0, 8);
			PrintToPos("■                                                                                                                    ■", 0, 9);
			PrintToPos("■                                                                                                                    ■", 0, 10);
			PrintToPos("■                                                                                                                    ■", 0, 11);
			PrintToPos("■                                                                                                                    ■", 0, 12);
			PrintToPos("■                                                                                                                    ■", 0, 13);
		}
		else
		{
			PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■      ■■■■■■■■      ■■■■■■      ■", 0, 4);
			PrintToPos("■      ■■■■■■■■  ■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■■■      ■■■■■■      ■", 0, 5);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■", 0, 6);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■        ■■                  ■", 0, 7);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■", 0, 8);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■■■■■            ■■        ■■■■■■■■      ■", 0, 9);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■", 0, 10);
			PrintToPos("■            ■■        ■■                  ■■        ■■        ■■        ■■                    ■■      ■", 0, 11);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■", 0, 12);
			PrintToPos("■            ■■        ■■■■■■■        ■■        ■■        ■■  ■■■■■■■■  ■■■■■■          ■", 0, 13);
		}
	}
}

void printFoot(bool isLoop)
{
	if (isLoop)
	{
		PrintToPos("■                                                   ■    ■■    ■■■    ■■                                     ■", 0, 17);
		PrintToPos("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■", 0, 18);
		PrintToPos("■                                               PRESS ANY KEY TO START                                               ■", 0, 22);
	}
	else
	{
		PrintToPos("■                                                   ■    ■■    ■■■    ■■                                     ■", 0, 17);
		PrintToPos("■                                   ■■■■    ■■■    ■■      ■        ■■                                   ■", 0, 18);
		PrintToPos("■                                                                                                                    ■", 0, 22);
	}
}

void PrintToPos(const char* str, int x, int y)
{
	MoveCursor(x, y);
	printf(str);
}

void PrintBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (CurrentBlock.bricks[j][i] == 1)
				PrintToPos(BrickSym, (x + i) * 2, y + j);
		}
	}
}

void PrintBlock(int x, int y, bool isGhost)
{
	const char* sym = isGhost ? "▤" : BrickSym;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(CurrentBlock.bricks[j][i] == 1)
				PrintToPos(sym, (x + i)*2, y + j);
		}
	}
}


Tetrimino RotateBlock(Tetrimino tetrimino, int rotate, int n)
{
	Tetrimino tmp = tetrimino;

	bool isCollision = false;

	tetrimino.rotateState += rotate;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rotate < 0)
				tetrimino.bricks[i][j] = tmp.bricks[j][n - i - 1];
			else
				tetrimino.bricks[i][j] = tmp.bricks[n - j - 1][i];


			// Check if collision after rotate
			if (tetrimino.x + i >= 11)
				tetrimino.x--;
			else if(tetrimino.x + i < 1)
				tetrimino.x++;

		}
	}

	return tetrimino;
}

void PrintNext()
{
	PrintToPos("NEXT", 31, 6);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (NextBlock.bricks[j][i] == 1)
				PrintToPos(BrickSym, (i + 15) * 2, j + 7);
			else
				PrintToPos("  ", (i + 15) * 2, j + 7);

		}
	}
}

void PrintHold()
{
	PrintToPos("HOLD", 31, 1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (HoldBlock.bricks[j][i] == 1)
				PrintToPos(BrickSym, (i + 15) * 2, j + 7);
			else
				PrintToPos("  ", (i + 15) * 2, j + 7);

		}
	}
}

void CheckGameOver()
{
	for (int i = 1; i < 11; i++)
	{
		if (TetrisMap[1][i] == 1)
			exitApp();
	}
}

void PrintGhost()
{
	//int ghostY = CurrentBlock.y;
	//bool isCollision = false;

	//while (!isCollision)
	//{
	//	ghostY++;
	//	for (int y = 0; y < 4; y++) {
	//		for (int x = 0; x < 4; x++)
	//		{
	//			if (CurrentBlock.bricks[y][x] != 0)
	//			{
	//				if (CurrentBlock.y + y + 1 >= 21)
	//				{
	//					isCollision = true;
	//					break;
	//				}
	//				if (TetrisMap[CurrentBlock.y + y + 1][CurrentBlock.x + x])
	//				{
	//					isCollision = true;
	//					break;
	//				}
	//			}
	//		}
	//	}
	//}

	//PrintBlock(CurrentBlock.x, ghostY, true);
}