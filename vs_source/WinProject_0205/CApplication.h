#pragma once

class CApplication
{
public:
    CApplication();

    void 화면갱신();

public:
    static CApplication* theApp;

    HINSTANCE mhInst;
    HWND      mhWnd;
};


