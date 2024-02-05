#pragma once
#include "CApplication.h"
#include "IScene.h"

class IGame
{
public:
    IGame() : mCurrent(NULL) {}

    virtual void onFrameMove() 
    { 
        if (mCurrent) mCurrent->onFrameMove(); 
        InvalidateRect(CApplication::theApp->mhWnd, NULL, FALSE);
    }
    virtual void onDraw(HDC hdc) { if (mCurrent) mCurrent->onDraw(hdc); }

public:
    IScene* mCurrent;
};

