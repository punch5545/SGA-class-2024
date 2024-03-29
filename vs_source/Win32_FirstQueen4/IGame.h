#pragma once
#include "pch.h"
#include "CApplication.h"
#include "IScene.h"
#include "CScreen.h"
#include "SceneManager.h"
#include "CLobbyScene.h"

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

    virtual void onKeyDown(UINT vKey) 
    {
        if (vKey == VK_RETURN)
            SceneManager::Manager->LoadScene(new CLobbyScene());
    }

    virtual void onMouseMove(int x, int y, char btn = 0x0000)
    {
        CApplication::theApp->mMousePos.X = x;
        CApplication::theApp->mMousePos.Y = y;
    }
    virtual void onMouseDown(int x, int y, char btn)
    {
        CApplication::theApp->mMousePos.X = x;
        CApplication::theApp->mMousePos.Y = y;

        CApplication::theApp->mMouseBtn = btn;
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


public:
    IScene* mCurrent;
    HWND popupHandle;

    UINT currentMessage;
    UINT currentParam;
};

