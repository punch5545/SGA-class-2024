#pragma once

#include <vector>

class IGame;
class IScene;

class SceneManager
{
public:
	static SceneManager* Manager;

	SceneManager();

	int SceneIdx;

	IGame* CurrentGame;
	std::vector<IScene*> SceneList;


	void LoadScene();
};

