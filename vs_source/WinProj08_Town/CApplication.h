#pragma once

class CApplication
{
public:
    CApplication();

    void ȭ�鰻��();

public:
    static CApplication* theApp;

    HINSTANCE mhInst;
    HWND      mhWnd;
};


