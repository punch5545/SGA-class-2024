#include "pch.h"
#include "Tetrimino.h"
#include "TetriminoManager.h"

#include "GameManager.h"

GameManager* GameManager::m_pInstance = NULL;
std::vector<std::vector<TetrisBlock>> GameManager::m_TetrisMap;

GameManager::GameManager()
{
	m_pInstance = this;

	srand(time(NULL));
}
bool GameManager::CheckCollision(Tetrimino& mino)
{
	const std::vector<std::vector<int>> minoShape = mino.GetShape();

	int tSize_y = minoShape.size();
	int tSize_x = minoShape[0].size();

	int mSize_y = m_TetrisMap.size();
	int mSize_x = m_TetrisMap[0].size();

	for (int y = 0; y < tSize_y; y++)
	{
		for (int x = 0; x < tSize_x; x++)
		{
			if (minoShape[y][x] == 1)
			{
				if (x + mino.PosX < 0 
					|| x + mino.PosX >= mSize_x 
					|| y + mino.PosY >= mSize_y)
				{
					return true;
				}
				if (m_TetrisMap[y + mino.PosY][x + mino.PosX].Data != 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void GameManager::AddTetriminoToMap(Tetrimino& Tetrimino)
{
	const std::vector<std::vector<int>> minoShape = Tetrimino.GetShape();

	int tSize_y = minoShape.size();
	int tSize_x = minoShape[0].size();

	for (int y = 0; y < tSize_y; y++)
	{
		for (int x = 0; x < tSize_x; x++)
		{
			if (minoShape[y][x] == 1)
			{
				m_TetrisMap[y + Tetrimino.PosY][x + Tetrimino.PosX].Data = 1;
				m_TetrisMap[y + Tetrimino.PosY][x + Tetrimino.PosX].Color = Tetrimino.GetColor();
			}
		}
	}
}

void GameManager::CheckLine()
{
	for (int y = 0; y < m_TetrisMap.size(); y++)
	{
		bool isFull = true;
		for (int x = 0; x < m_TetrisMap[y].size(); x++)
		{
			if (m_TetrisMap[y][x].Data == 0)
			{
				isFull = false;
				break;
			}
		}

		if (isFull)
		{
			m_TetrisMap.erase(m_TetrisMap.begin() + y);
			m_TetrisMap.insert(m_TetrisMap.begin(), std::vector<TetrisBlock>(m_TetrisMap[0].size(), { 0, 0 }));
		}
	}
}

void GameManager::Init()
{
	m_TetrisMap = std::vector<std::vector<TetrisBlock>>(20, std::vector<TetrisBlock>(10, { 0, 0 }));
	m_pMinoMgr = new TetriminoManager();

	m_pMinoMgr->Init();

	Update();
}

void GameManager::Update()
{
	m_pMinoMgr->Update();

	// Render
	while (1)
	{
		Render();
		int key = 0;
		while (_kbhit()) { key = _getch(); }

		DeltaTime+=0.1;
		m_pMinoMgr->Input((Direction)key);

		if (DeltaTime >= FRAME_RATE / 3 / 9)
		{
			m_pMinoMgr->CurrentTetrimino->PosY++;
			DeltaTime = 0;
		}
		Sleep(FRAME_PER_SECOND);
	}

}

void GameManager::Render()
{

	for (int x = 0; x < 12; x++)
	{
		PrintToPos(x * 2, 0, "▩");
		PrintToPos(x * 2, 21, "▩");
	}
	for(int y = 0;  y < 22; y++)
	{
		PrintToPos(0, y, "▩");
		PrintToPos(22, y, "▩");
	}


	for (int y = 0; y < m_TetrisMap.size(); y++)
	{
		for (int x = 0; x < m_TetrisMap[y].size(); x++)
		{
			if (m_TetrisMap[y][x].Data == 1)
			{
				PrintToPos(m_TetrisMap[y][x].Color, x * 2 + 2, y + 1, "■");
			}
			else
			{
				PrintToPos(x * 2 + 2, y + 1, "  ");
			}
		}
	}

	m_pMinoMgr->Render();
}

void GameManager::Release()
{
}

void GameManager::MoveCursor(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GameManager::PrintToPos(int x, int y, const char* str, ...)
{
	MoveCursor(x, y);

	int _Result;
	va_list _ArgList;
	__crt_va_start(_ArgList, str);
	_Result = _vfprintf_l(stdout, str, NULL, _ArgList);
	__crt_va_end(_ArgList);
}

void GameManager::PrintToPos(DWORD color, int x, int y, const char* str, ...)
{
	MoveCursor(x, y);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들을 가져옵니다.
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo; // 현재 콘솔 색상 정보를 저장할 구조체
	WORD saved_attributes; // 원래 콘솔 색상을 저장할 변수

	// 현재 콘솔 색상 정보를 가져옵니다.
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, color); // 색상을 설정합니다.

	va_list args; // 가변 인자 목록
	va_start(args, str);
	vprintf(str, args); // 포맷된 문자열을 출력합니다.
	va_end(args);

	SetConsoleTextAttribute(hConsole, saved_attributes); // 원래 색상으로 복원합니다.
}