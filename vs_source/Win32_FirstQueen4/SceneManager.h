#pragma once



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
	void LoadScene(IScene* Scene);
};

