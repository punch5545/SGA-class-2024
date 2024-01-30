#pragma once
const char* BrickSym = "��";

int timeDelta = 0;

Tetrimino tetriminos[7];
bool isStart = false;
int deltaTime = 0;

int highScore = 0;
int score = 0;

int bestCombo = 0;
int combo = 0;


void MoveCursor(int x, int y);
void exitApp();

void CursorView(BOOL cursorState)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = cursorState; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void MoveBlock(int key);
void printAnimation(int index);
void printFoot(bool isLoop);
void PrintBackground();


void PrintToPos(const char* str, int x, int y);
void PrintToPos(int x, int y, const char* str, ...);

void PrintBlock(int x, int y);
void PrintBlock(int x, int y, bool isGhost);
void PrintNext();
void PrintHold();

void Hold();

void MoveLeft();
void MoveRight();
void MoveDown();
void HardDown();
void RemoveLine();

void AddCombo();
void AddScore(int lineCount);

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
	-1,
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}, 0, 0, 0, 0
};

// ��Ʈ���� ��
// �׵θ��� ������ ������ �κ� (y��ǥ 1~21, x��ǥ 1~11������ ���
// �ش� ��ǥ�� ���� ������ 1, ������ ���� ������ 0���� ����������.
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

// �� ��Ʈ���̳븦 �ʱ�ȭ (7��)
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

// ���� ���� �Լ�
void StartGame()
{
	time(NULL);
	srand((unsigned int)time(NULL));	

	isStart = true;
	InitBlocks();
	
	PrintBackground();
	PrintToPos("HOLD", 31, 1);
	PrintToPos("NEXT", 31, 6);
	PrintToPos("SCORE", 31, 11);
	PrintToPos("COMBO", 31, 13);

	while (true)
	{
		// �� �����Ӹ��� �����ϱ�.
		// FRAME_PER_SECOND�� ������� �ֻ����� ���� �ٸ���, pch.h�� ����Ǿ� ����.

		Update();
		Sleep(FRAME_PER_SECOND);
	}
}
int i = 0;

// �� �����Ӹ��� ����Ǵ� �Լ�.
void Update() {
	PrintBackground();

	// ���� ������ y��ǥ�� 0�̸�, ������ �������� ���� ������ �����Ͽ� ���ο� ���� �����ϱ�
	if (CurrentBlock.y == 0)
	{
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		CurrentBlock.x = 4;
		CurrentBlock.y = 1;

		NextBlock = tetriminos[rand() % 7];
	}

	// Ű �Է� ó��
	if (_kbhit())
	{
		int key = _getch();
		MoveBlock(key);
	}

	// 0.3�ʸ��� ������ y��ǥ ����
	if (deltaTime > (FRAME_RATE / 3))
	{
		// ��ǥ�� ������ ���� ���� �Ʒ��ʿ� �ٸ� ����, �Ǵ� �ٴ��� �ִٸ� ����.
		CheckBottomCollision();

		CurrentBlock.y++;
		deltaTime = 0;
	}

	deltaTime++;


	PrintToPos(32, 12, "%d", score);
	PrintToPos(33, 14, "%d", combo > 0 ? combo - 1 : 0);
	
	PrintGhost();

	PrintBlock(CurrentBlock.x, CurrentBlock.y);

	CheckGameOver();

	PrintNext();
	PrintHold();
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
			// ���� ������ ȸ��, �Լ����� ��ȯ�� ȸ���� �Ϸ�� ������ ���� �������� �ٲ���.
			CurrentBlock = RotateBlock(CurrentBlock, 1, n);
			break;
		case 'KEY_LEFT': MoveLeft();
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
			Hold();
			break;
		case KEY_LEFT_CTRL:
			CurrentBlock = RotateBlock(CurrentBlock, -1, n);
			break;
		default: break;

	}
}

void Hold()
{
	Tetrimino tmp;

	if (HoldBlock.index < 0)
	{
		HoldBlock = CurrentBlock;
		CurrentBlock = NextBlock;

		int startBlock = rand() % 7;
		NextBlock = tetriminos[startBlock];
	}
	else
	{
		tmp = HoldBlock;
		HoldBlock = CurrentBlock;
		CurrentBlock = tmp;
	}

	CurrentBlock.x = 4;
	CurrentBlock.y = 1;

	PrintHold();
}


void CheckBottomCollision()
{
	// �浹 ���°�: �⺻-false (0)
	bool isCollision = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// ���� �Ʒ��� ���� �ִٸ�
			if (CurrentBlock.bricks[j][i] == 1 && TetrisMap[CurrentBlock.y + j + 1][CurrentBlock.x + i] == 1)
			{
				// �浹 ���°��� true(1)�� �����ϰ� for�� ��������
				isCollision = true;
				break;
			}
		}
	}
	// ������ �浹 ���°��� true�� �ٲ���ٸ� (���� �Ʒ��� ���� �ִٸ�)
	if (isCollision)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// ���� ������ ��ǥ��� Map�� �׸���
				// �ٴڿ� ���� �������� ó����.
				if(CurrentBlock.bricks[j][i] == 1)
					TetrisMap[CurrentBlock.y + j][CurrentBlock.x + i] = CurrentBlock.bricks[j][i];
			}
		}

		// �ٴڿ� ���� ������ �������Ƿ� �� ���� ����
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		// �� ������ �ʱ� ��ġ ����
		CurrentBlock.x = 4;
		CurrentBlock.y = 1;
	}
}

// �ܼ��� Ŀ���� X, Y ��ǥ�� �̵���
void MoveCursor(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ���α׷� ����
void exitApp()
{
	exit(0);
}

// ��� �׸���
void PrintBackground()
{
	int rightWall = 118;

	// ������ ���۵� ��� ��Ʈ���� �� �迭�� �׸�.
	if (isStart)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				const char* symbol = TetrisMap[i][j] == 0 ? "  " : (i == 0 || i == 21 || j == 0 || j == 11) ? "��" : "��";
				PrintToPos(symbol, j * 2, i);
			}
		}
	}
	// ������ ���۵��� ���� ��� ��Ʈ�� ȭ�� �׵θ� �׸���
	else
	{
		PrintToPos("�������������������������������������������������������������", 0, 0);
		PrintToPos("�������������������������������������������������������������", 0, 29);
		for (int i = 0; i < 29; i++)
		{
			PrintToPos("��", 0, i);
			PrintToPos("��", 118, i);
		}
	}
}

void MoveLeft() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (CurrentBlock.bricks[y][x] == 1) {
				if (CurrentBlock.x + x - 1 < 0) 
					return; // ������ �����ʿ� ���� �ְų� �� ���̸� �̵����� ����

				if (CurrentBlock.y + y >= 0 && TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x - 1]) 
					return; // ������ �����ʿ� �ٸ� ������ ������ �̵����� ����
				
			}
		}
	}
	// �浹���� ������ �������� �̵�
	CurrentBlock.x--;
	return;
}

void MoveRight() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (CurrentBlock.bricks[y][x] != 0) {
				if (CurrentBlock.x + x + 1 >= 11) 
					return; // ������ �����ʿ� ���� �ְų� �� ���̸� �̵����� ����

				if (CurrentBlock.y + y >= 0 && TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x + 1])
					return; // ������ �����ʿ� �ٸ� ������ ������ �̵����� ����
			}
		}
	}
	// �浹���� ������ ���������� �̵�
	CurrentBlock.x++;
	return;
}

void MoveDown() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			// ������ ���� Ȯ���ؼ� 0�� �ƴ� ��� (ǥ��Ǵ� ���)�� ����
			if (CurrentBlock.bricks[y][x] != 0) {
				// ������ ������ �̵�, ������ �����ƴٸ� �ش� ���� ����
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
	// �浹���� ������ �Ʒ��� �̵�
	CurrentBlock.y++;
	return; 
}

// �����̽���
void HardDown()
{
	// �Ʒ��� �̵��ϴ� �ڵ尡 �浹�������� ����ǵ��� ��
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
		// �浹���� ������ �Ʒ��� �̵�
		CurrentBlock.y++;
		//PrintBackground();
		PrintBlock(CurrentBlock.x, CurrentBlock.y);
		//Sleep(1);
	}
}

void RemoveLine()
{
	bool isLine = false;
	int lineCount = 0;

	for (int y = 1; y < 21; y++)
	{
		for (int x = 1; x < 11; x++)
		{
			if (TetrisMap[y][x] == 0)
			{
				isLine = false;
				break;
			}
			else
				isLine = true;
		}
		if (isLine)
		{
			for (int x = 1; x < 11; x++)
			{
				TetrisMap[y][x] = 0; // ���� ����
			}

			for (int i = y; i > 1; i--) // ���پ� ������
			{
				for (int j = 1; j < 11; j++)
				{
					TetrisMap[i][j] = TetrisMap[i - 1][j];
				}
			}
			lineCount++;
		}
	}

if (lineCount > 0)
	{
		AddScore(lineCount);
		AddCombo();
	}
	else
		combo = 0;
}

void AddScore(int lineCount)
{
	score += ( 90 + (combo * 10) ) * lineCount;
	if (highScore < score)
		highScore = score;

}

void AddCombo()
{
	combo++;

	if(bestCombo < combo)
		bestCombo = combo;
}

void BlockToMap()
{
// ������ �ʿ� �߰�
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++)
		{
			if (CurrentBlock.bricks[y][x] != 0)
				TetrisMap[CurrentBlock.y + y][CurrentBlock.x + x] = CurrentBlock.bricks[y][x];
		}
	}

	// ���� ����
	int startBlock = rand() % 7;
	CurrentBlock = NextBlock;
	NextBlock = tetriminos[startBlock];

	CurrentBlock.x = 4;
	CurrentBlock.y = 1;
}

// ��Ʈ�� �ִϸ��̼�
void printAnimation(int index)
{
	switch (index) {
	case 0:
		PrintToPos("��                                                                                                                    ��", 0, 4);
		PrintToPos("��                                                                                                                    ��", 0, 5);
		PrintToPos("��                                                                                                                    ��", 0, 6);
		PrintToPos("��                                                                                                                    ��", 0, 7);
		PrintToPos("��                                                                                                                    ��", 0, 8);
		PrintToPos("��                                                                                                                    ��", 0, 9);
		PrintToPos("��                                                                                                                    ��", 0, 10);
		PrintToPos("��                                                                                                                    ��", 0, 11);
		PrintToPos("��                                                                                                                    ��", 0, 12);
		PrintToPos("��                                                                                                                    ��", 0, 13);
		break;
	case 1:
		PrintToPos("��      ���������                                                                                              ��", 0, 4);
		PrintToPos("��      ���������                                                                                              ��", 0, 5);
		PrintToPos("��            ���                                                                                                    ��", 0, 6);
		PrintToPos("��            ���                                                                                                    ��", 0, 7);
		PrintToPos("��            ���                                                                                                    ��", 0, 8);
		PrintToPos("��            ���                                                                                                    ��", 0, 9);
		PrintToPos("��            ���                                                                                                    ��", 0, 10);
		PrintToPos("��            ���                                                                                                    ��", 0, 11);
		PrintToPos("��            ���                                                                                                    ��", 0, 12);
		PrintToPos("��            ���                                                                                                    ��", 0, 13);
		break;
	case 2:
		PrintToPos("��      ���������  ��������                                                                              ��", 0, 4);
		PrintToPos("��      ���������  ��������                                                                              ��", 0, 5);
		PrintToPos("��            ���        ���                                                                                        ��", 0, 6);
		PrintToPos("��            ���        ���                                                                                        ��", 0, 7);
		PrintToPos("��            ���        ��������                                                                              ��", 0, 8);
		PrintToPos("��            ���        ��������                                                                              ��", 0, 9);
		PrintToPos("��            ���        ���                                                                                        ��", 0, 10);
		PrintToPos("��            ���        ���                                                                                        ��", 0, 11);
		PrintToPos("��            ���        ��������                                                                              ��", 0, 12);
		PrintToPos("��            ���        ��������                                                                              ��", 0, 13);
		break;
	case 3:
		PrintToPos("��      ���������  ��������  ���������                                                            ��", 0, 4);
		PrintToPos("��      ���������  ��������  ���������                                                            ��", 0, 5);
		PrintToPos("��            ���        ���                  ���                                                                  ��", 0, 6);
		PrintToPos("��            ���        ���                  ���                                                                  ��", 0, 7);
		PrintToPos("��            ���        ��������        ���                                                                  ��", 0, 8);
		PrintToPos("��            ���        ��������        ���                                                                  ��", 0, 9);
		PrintToPos("��            ���        ���                  ���                                                                  ��", 0, 10);
		PrintToPos("��            ���        ���                  ���                                                                  ��", 0, 11);
		PrintToPos("��            ���        ��������        ���                                                                  ��", 0, 12);
		PrintToPos("��            ���        ��������        ���                                                                  ��", 0, 13);
		break;
	case 4:
		PrintToPos("��      ���������  ��������  ���������  �������                                              ��", 0, 4);
		PrintToPos("��      ���������  ��������  ���������  ���������                                          ��", 0, 5);
		PrintToPos("��            ���        ���                  ���        ���        ���                                          ��", 0, 6);
		PrintToPos("��            ���        ���                  ���        ���        ���                                          ��", 0, 7);
		PrintToPos("��            ���        ��������        ���        �������                                              ��", 0, 8);
		PrintToPos("��            ���        ��������        ���        �������                                              ��", 0, 9);
		PrintToPos("��            ���        ���                  ���        ���        ���                                          ��", 0, 10);
		PrintToPos("��            ���        ���                  ���        ���        ���                                          ��", 0, 11);
		PrintToPos("��            ���        ��������        ���        ���        ���                                          ��", 0, 12);
		PrintToPos("��            ���        ��������        ���        ���        ���                                          ��", 0, 13);
		break;
	case 5:
		PrintToPos("��      ���������  ��������  ���������  �������      ���������                        ��", 0, 4);
		PrintToPos("��      ���������  ��������  ���������  ���������  ���������                        ��", 0, 5);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                              ��", 0, 6);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                              ��", 0, 7);
		PrintToPos("��            ���        ��������        ���        �������            ���                              ��", 0, 8);
		PrintToPos("��            ���        ��������        ���        �������            ���                              ��", 0, 9);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                              ��", 0, 10);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                              ��", 0, 11);
		PrintToPos("��            ���        ��������        ���        ���        ���  ���������                        ��", 0, 12);
		PrintToPos("��            ���        ��������        ���        ���        ���  ���������                        ��", 0, 13);
		break;
	case 6:
		PrintToPos("��      ���������  ��������  ���������  �������      ���������      �������      ��", 0, 4);
		PrintToPos("��      ���������  ��������  ���������  ���������  ���������      �������      ��", 0, 5);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���        ���                  ��", 0, 6);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���        ���                  ��", 0, 7);
		PrintToPos("��            ���        ��������        ���        �������            ���        ���������      ��", 0, 8);
		PrintToPos("��            ���        ��������        ���        �������            ���        ���������      ��", 0, 9);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                    ���      ��", 0, 10);
		PrintToPos("��            ���        ���                  ���        ���        ���        ���                    ���      ��", 0, 11);
		PrintToPos("��            ���        ��������        ���        ���        ���  ���������  �������          ��", 0, 12);
		PrintToPos("��            ���        ��������        ���        ���        ���  ���������  �������          ��", 0, 13);
		break;
	default:
		if (index % 2 == 0)
		{
			PrintToPos("��                                                                                                                    ��", 0, 4);
			PrintToPos("��                                                                                                                    ��", 0, 5);
			PrintToPos("��                                                                                                                    ��", 0, 6);
			PrintToPos("��                                                                                                                    ��", 0, 7);
			PrintToPos("��                                                                                                                    ��", 0, 8);
			PrintToPos("��                                                                                                                    ��", 0, 9);
			PrintToPos("��                                                                                                                    ��", 0, 10);
			PrintToPos("��                                                                                                                    ��", 0, 11);
			PrintToPos("��                                                                                                                    ��", 0, 12);
			PrintToPos("��                                                                                                                    ��", 0, 13);
		}
		else
		{
			PrintToPos("��      ���������  ��������  ���������  �������      ���������      �������      ��", 0, 4);
			PrintToPos("��      ���������  ��������  ���������  ���������  ���������      �������      ��", 0, 5);
			PrintToPos("��            ���        ���                  ���        ���        ���        ���        ���                  ��", 0, 6);
			PrintToPos("��            ���        ���                  ���        ���        ���        ���        ���                  ��", 0, 7);
			PrintToPos("��            ���        ��������        ���        �������            ���        ���������      ��", 0, 8);
			PrintToPos("��            ���        ��������        ���        �������            ���        ���������      ��", 0, 9);
			PrintToPos("��            ���        ���                  ���        ���        ���        ���                    ���      ��", 0, 10);
			PrintToPos("��            ���        ���                  ���        ���        ���        ���                    ���      ��", 0, 11);
			PrintToPos("��            ���        ��������        ���        ���        ���  ���������  �������          ��", 0, 12);
			PrintToPos("��            ���        ��������        ���        ���        ���  ���������  �������          ��", 0, 13);
		}
	}
}


// ��Ʈ�� �ִϸ��̼� �ϴܺ�
void printFoot(bool isLoop)
{
	// �ʹ� 1ȸ ����� ������ Press Any Key... ���� ���
	if (isLoop)
	{
		PrintToPos("��                                                   ��    ���    ����    ���                                     ��", 0, 17);
		PrintToPos("��                                   �����    ����    ���      ��        ���                                   ��", 0, 18);
		PrintToPos("��                                               PRESS ANY KEY TO START                                               ��", 0, 22);
	}
	// �ʹ� 1ȸ ����� ��� ��¾���.
	else
	{
		PrintToPos("��                                                   ��    ���    ����    ���                                     ��", 0, 17);
		PrintToPos("��                                   �����    ����    ���      ��        ���                                   ��", 0, 18);
		PrintToPos("��                                                                                                                    ��", 0, 22);
	}
}

// �ܼ��� ���ϴ� ��ġ�� �̵��� printf�� str ���ڿ� ���
void PrintToPos(const char* str, int x, int y)
{
	MoveCursor(x, y);
	printf(str);
}

// �� �Լ��� ����, printf�� "%d" �� ������ �޾Ƽ� ���
void PrintToPos(int x, int y, const char* str, ...)
{
	MoveCursor(x, y);

	int _Result;
	va_list _ArgList;
	__crt_va_start(_ArgList, str);
	_Result = _vfprintf_l(stdout, str, NULL, _ArgList);
	__crt_va_end(_ArgList);

};

// ���� �������� �ִ� ���� (��Ʈ���̳�) ���
void PrintBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (CurrentBlock.bricks[j][i] == 1)
				PrintToPos((x + i) * 2, y + j, "%s%s%s", "\033[0;34m", BrickSym, "\033[0m");
		}
	}
}

// ���� �������� �ִ� ���� (��Ʈ���̳�)�� �������� �̸����� ���
void PrintBlock(int x, int y, bool isGhost)
{
	const char* sym = isGhost ? "��" : BrickSym;
	char* symColor = NULL;
	symColor = (char*) malloc(sizeof(char) * 10);

	if(isGhost)
		strcpy_s(symColor, sizeof(char) * 10, "\033[0;36m");
	else
		strcpy_s(symColor, sizeof(char) * 10, "\033[0;34m");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(CurrentBlock.bricks[j][i] == 1)
				PrintToPos((x + i)*2, y + j, "%s%s%s", symColor, sym, "\033[0m");
		}
	}

	free(symColor);
}

// ���� ȸ��
Tetrimino RotateBlock(Tetrimino tetrimino, int rotate, int n)
{
	// �ӽ� ��Ʈ���̳� ���� �� ���� ��Ʈ���̳�� �ʱ�ȭ, ������ �������� ȸ���� ���� ������.
	Tetrimino tmp = tetrimino;

	bool isCollision = false;

	// ��Ʈ���̳��� ȸ�� ���°� ����
	tetrimino.rotateState += rotate;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rotate < 0)
				tetrimino.bricks[i][j] = tmp.bricks[j][n - i - 1]; // 90�� ȸ�� (�ð����)
			else
				tetrimino.bricks[i][j] = tmp.bricks[n - j - 1][i]; // -90�� ȸ�� (�ݽð����)

			// ȸ�� �� �α� ���� �Ǵ� ���� �浹�� ��� �¿�� ��ĭ �̵���Ŵ
			// ȸ�� �� ���� ��ġ�� �ʰ� �ϱ� ������.
			if (tetrimino.x + i >= 11)
				tetrimino.x--;
			else if(tetrimino.x + i < 1)
				tetrimino.x++;

		}
	}

	// ȸ���� �Ϸ�� ��Ʈ���̳븦 ��ȯ
	return tetrimino;
}

// ������ ���� ���� ���
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

// Ȧ���� ���� ���
void PrintHold()
{
	PrintToPos("HOLD", 31, 1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (HoldBlock.bricks[j][i] == 1)
				PrintToPos(BrickSym, (i + 15) * 2, j + 2);
			else
				PrintToPos("  ", (i + 15) * 2, j + 2);

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
	int ghostY = CurrentBlock.y;
	bool isCollision = false;

	// Hard Down�� �����ϳ�, ������ �̵���Ű�� ����.
	while (!isCollision)
	{
		ghostY++;
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++)
			{
				if (CurrentBlock.bricks[y][x] != 0)
				{
					if (ghostY + y + 1 >= 21)
					{
						isCollision = true;
						break;
					}
					if (TetrisMap[ghostY + y + 1][CurrentBlock.x + x])
					{
						isCollision = true;
						break;
					}
				}
			}
		}
	}

	PrintBlock(CurrentBlock.x, ghostY, true);
}