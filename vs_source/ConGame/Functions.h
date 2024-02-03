#pragma once
const char* BrickSym = "■";

int timeDelta = 0;

void exitApp();


void MoveBlock(int key);


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

// 테트리스 맵
// 테두리를 제외한 나머지 부분 (y좌표 1~21, x좌표 1~11까지만 사용
// 해당 좌표에 놓인 블럭은 1, 놓이지 않은 블럭은 0으로 가지고있음.
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

// 각 테트리미노를 초기화 (7개)
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

// 게임 시작 함수
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
		// 매 프레임마다 실행하기.
		// FRAME_PER_SECOND는 모니터의 주사율에 따라 다르며, pch.h에 선언되어 있음.

		Update();
		Sleep(FRAME_PER_SECOND);
	}
}
int i = 0;

// 매 프레임마다 실행되는 함수.
void Update() {
	PrintBackground();

	// 현재 블록의 y좌표가 0이면, 블록이 등장하지 않은 것으로 간주하여 새로운 블록 생성하기
	if (CurrentBlock.y == 0)
	{
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		CurrentBlock.x = 4;
		CurrentBlock.y = 1;

		NextBlock = tetriminos[rand() % 7];
	}

	// 키 입력 처리
	if (_kbhit())
	{
		int key = _getch();
		MoveBlock(key);
	}

	// 0.3초마다 블럭의 y좌표 내림
	if (deltaTime > (FRAME_RATE / 3))
	{
		// 좌표를 내리기 전에 블록 아래쪽에 다른 블록, 또는 바닥이 있다면 멈춤.
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
			// 현재 블록을 회전, 함수에서 반환된 회전이 완료된 블럭을 현재 블럭으로 바꿔줌.
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
	// 충돌 상태값: 기본-false (0)
	bool isCollision = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 블럭 아래에 뭔가 있다면
			if (CurrentBlock.bricks[j][i] == 1 && TetrisMap[CurrentBlock.y + j + 1][CurrentBlock.x + i] == 1)
			{
				// 충돌 상태값을 true(1)로 변경하고 for문 빠져나감
				isCollision = true;
				break;
			}
		}
	}
	// 위에서 충돌 상태값이 true로 바뀌었다면 (블럭 아래에 뭔가 있다면)
	if (isCollision)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// 현재 블럭의 좌표대로 Map에 그리기
				// 바닥에 놓인 블럭으로 처리함.
				if(CurrentBlock.bricks[j][i] == 1)
					TetrisMap[CurrentBlock.y + j][CurrentBlock.x + i] = CurrentBlock.bricks[j][i];
			}
		}

		// 바닥에 기존 블럭이 놓였으므로 새 블럭 생성
		int startBlock = rand() % 7;
		CurrentBlock = tetriminos[startBlock];

		// 새 블럭의 초기 위치 지정
		CurrentBlock.x = 4;
		CurrentBlock.y = 1;
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
			// 블럭과 맵을 확인해서 0이 아닌 경우 (표기되는 경우)만 실행
			if (CurrentBlock.bricks[y][x] != 0) {
				// 블럭을 맵으로 이동, 라인이 생성됐다면 해당 라인 삭제
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

// 스페이스바
void HardDown()
{
	// 아래로 이동하는 코드가 충돌직전까지 수행되도록 함
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
				TetrisMap[y][x] = 0; // 한줄 제거
			}

			for (int i = y; i > 1; i--) // 한줄씩 내리기
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


// 현재 떨어지고 있는 블록 (테트리미노) 출력
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

// 현재 떨어지고 있는 블록 (테트리미노)의 낙하지점 미리보기 출력
void PrintBlock(int x, int y, bool isGhost)
{
	const char* sym = isGhost ? "▤" : BrickSym;
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

// 블럭 회전
Tetrimino RotateBlock(Tetrimino tetrimino, int rotate, int n)
{
	// 임시 테트리미노 선언 후 기존 테트리미노로 초기화, 블럭의 비정상적 회전을 막기 위함임.
	Tetrimino tmp = tetrimino;

	bool isCollision = false;

	// 테트리미노의 회전 상태값 저장
	tetrimino.rotateState += rotate;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rotate < 0)
				tetrimino.bricks[i][j] = tmp.bricks[j][n - i - 1]; // 90도 회전 (시계방향)
			else
				tetrimino.bricks[i][j] = tmp.bricks[n - j - 1][i]; // -90도 회전 (반시계방향)

			// 회전 후 인근 블럭 또는 벽과 충돌할 경우 좌우로 한칸 이동시킴
			// 회전 후 벽과 겹치지 않게 하기 위함임.
			if (tetrimino.x + i >= 11)
				tetrimino.x--;
			else if(tetrimino.x + i < 1)
				tetrimino.x++;

		}
	}

	// 회전이 완료된 테트리미노를 반환
	return tetrimino;
}

// 다음에 나올 블럭 출력
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

// 홀드한 블럭 출력
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

	// Hard Down과 동일하나, 맵으로 이동시키진 않음.
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