#pragma once
class MainController
{
	Screen* screen;

public:
	void ShowIntro();

	void StartGame();
	void Update();

	MainController();
	~MainController();
};

