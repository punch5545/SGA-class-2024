#include "pch.h"
#include "GameManager.h"
#include "TetriminoManager.h"

TetriminoManager::TetriminoManager()
{
	for(int i = 0; i < 7; i++)
	{
		m_Tetriminos.push_back(new Tetrimino((TetriminoType)i));
	}
}

TetriminoManager::~TetriminoManager()
{
	for(auto tetrimino : m_Tetriminos)
	{
		delete tetrimino;
	}
}

void TetriminoManager::Input(Direction dir)
{
	int PosX = CurrentTetrimino->PosX;
	int PosY = CurrentTetrimino->PosY;

	switch (dir)
	{
	case Left:
		CurrentTetrimino->PosX--;

		if(GameManager::m_pInstance->CheckCollision(*CurrentTetrimino)) {
			CurrentTetrimino->PosX = PosX;
		}
		break;

	case Right:
		CurrentTetrimino->PosX++;

		if(GameManager::m_pInstance->CheckCollision(*CurrentTetrimino)) {
			CurrentTetrimino->PosX = PosX;
		}
		break;

	case Down:
		CurrentTetrimino->PosY++;
		if(GameManager::m_pInstance->CheckCollision(*CurrentTetrimino)) {
			CurrentTetrimino->PosY = PosY;
			GameManager::m_pInstance->AddTetriminoToMap(*CurrentTetrimino);
			GameManager::m_pInstance->CheckLine();
			SetNextTetrimino();
		}

		break;

	case HardDown:
		while(!GameManager::m_pInstance->CheckCollision(*CurrentTetrimino)) {
			CurrentTetrimino->PosY++;
		}

		CurrentTetrimino->PosY--;

		GameManager::m_pInstance->AddTetriminoToMap(*CurrentTetrimino);
		GameManager::m_pInstance->CheckLine();
		SetNextTetrimino();

		break;
	case Rotate:
		Rotation(false);
		break;
	case RotateReverse:
		Rotation(true);
		break;
	case Hold:
		SetHoldTetrimino();
		break;
	default:
		break;
	}
}

void TetriminoManager::Rotation(bool isReverse)
{
	CurrentTetrimino->Rotate(isReverse);
}

void TetriminoManager::Init()
{
	CurrentTetrimino = m_Tetriminos[3];
	SetNextTetrimino();
	SetHoldTetrimino();
}

void TetriminoManager::Update()
{

}

void TetriminoManager::Render()
{
	for(int y = 0; y < CurrentTetrimino->GetShape().size(); y++)
	{
		for(int x = 0; x < CurrentTetrimino->GetShape()[0].size(); x++)
		{
			if(CurrentTetrimino->GetShape()[y][x] != 0)
			{
				GameManager::m_pInstance->PrintToPos(
					CurrentTetrimino->GetColor(), (CurrentTetrimino->PosX + x) * 2 + 2, CurrentTetrimino->PosY + y, "бс");
			}
		}
	}

}

void TetriminoManager::SetNextTetrimino()
{
	CurrentTetrimino = m_Tetriminos[rand() % 7];
	CurrentTetrimino->PosX = 4;
	CurrentTetrimino->PosY = 1;

	GhostTetrimino = CurrentTetrimino;
}

void TetriminoManager::SetHoldTetrimino()
{
}
