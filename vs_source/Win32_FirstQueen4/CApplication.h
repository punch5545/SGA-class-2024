#pragma once

class CGameFQ4;

class CApplication
{
public:
    CApplication();

    void About();

    void 화면갱신();

public:
    static CApplication* theApp;

    Vector2 mMousePos;

    HINSTANCE mhInst;
    HWND      mhWnd;
    CGameFQ4* pGame;

    char mMouseBtn;
    char mKeyboard;
};