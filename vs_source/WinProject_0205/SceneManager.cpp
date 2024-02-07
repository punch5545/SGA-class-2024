#include "pch.h"
#include "SceneManager.h"
#include "IGame.h"

SceneManager* SceneManager::Manager = NULL;

SceneManager mgr;

SceneManager::SceneManager()
	:CurrentGame(NULL), SceneIdx(0)
{
	Manager = this;
}

void SceneManager::LoadScene()
{
	if (SceneList.size() > 0)
	{
		CurrentGame->mCurrent = SceneList[SceneIdx];
	}
}
