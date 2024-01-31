#pragma once
class Tetris
{
public:
	Tetris();
	~Tetris();

	std::vector<CImage*> mBlockImages;

	CImage* mWallImg;

	void OnTimer();

	void KeyPressed(int key);
	void Draw(HDC hdc);
};

