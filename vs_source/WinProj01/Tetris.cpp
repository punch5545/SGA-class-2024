#include "pch.h"
#include "resource.h"
#include "CImage.h"
#include "Tetris.h"


Tetris::Tetris()
{
	mWallImg = new CImage(MAKEINTRESOURCE(IDB_BITMAP3));
}

Tetris::~Tetris()
{
}

void Tetris::OnTimer()
{
}

void Tetris::KeyPressed(int key)
{
}

void Tetris::Draw(HDC hdc)
{
	mWallImg->Draw(hdc, 0, 0);

}
