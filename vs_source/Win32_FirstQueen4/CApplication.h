#pragma once

class CGameFQ4;

class CApplication
{
public:
    CApplication();

    void About();

    void ȭ�鰻��();

public:
    static CApplication* theApp;

    MousePos mMousePos;

    HINSTANCE mhInst;
    HWND      mhWnd;
    CGameFQ4* pGame;

    char mMouseBtn;
    char mKeyboard;
};