#pragma once

class TetriminoManager;
class Tetrimino;
class GameManager
{
public:
	static GameManager* m_pInstance;
	static GameManager* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new GameManager();
		}
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		if (m_pInstance != nullptr)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	GameManager();
	static std::vector<std::vector<TetrisBlock>> m_TetrisMap;

	TetriminoManager* m_pMinoMgr;

	bool CheckCollision(Tetrimino& Tetrimino);
	void AddTetriminoToMap(Tetrimino& Tetrimino);

	void CheckLine();

	bool IsGameOver = false;
	bool IsStart = false;
	double DeltaTime = 0;

	int HighScore = 0;
	int Score = 0;

	int BestCombo = 0;
	int Combo = 0;

	void Init();
	void Update();
	void Render();
	void Release();

	void MoveCursor(int x, int y);
	void PrintToPos(int x, int y, const char* str, ...);
	void PrintToPos(DWORD color, int x, int y, const char* str, ...);

};

