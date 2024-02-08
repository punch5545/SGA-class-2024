#pragma once
#include "pch.h"
#include "CApplication.h"
#include "IScene.h"
#include "CScreen.h"

class IGame
{
public:
    IGame() : mCurrent(NULL) {}

    virtual void onFrameMove() 
    { 
        if (mCurrent) mCurrent->onFrameMove(); 
        InvalidateRect(CApplication::theApp->mhWnd, NULL, FALSE);
    }
    virtual void onDraw(HDC hdcWnd) { 
        if (mCurrent) 
        {
            CScreen screen(hdcWnd, WINDOW_WIDTH, WINDOW_HEIGHT);
            mCurrent->onDraw(screen.m_HDC);

            screen.Draw(hdcWnd);
        }
    }

    virtual bool GetKeyDown(WORD keyCode)
    {
        bool res;
        
        if (currentMessage == WM_KEYDOWN && currentParam != NULL && keyCode == VK_ANYKEY)
            res = true;
        else
            res = (currentMessage == WM_KEYDOWN && currentParam == keyCode);

        currentMessage = NULL;
        currentParam = NULL;

        return res;
    }

    virtual void onGameMessage(UINT msg, UINT wParam) = 0;

public:
    IScene* mCurrent;
    HWND popupHandle;

    UINT currentMessage;
    UINT currentParam;
};

