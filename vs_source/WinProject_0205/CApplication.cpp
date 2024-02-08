#include "pch.h"
#include "CGameFQ4.h"
#include "CApplication.h"
#include "resource.h"

CApplication* CApplication::theApp = NULL;

CApplication app;

CApplication::CApplication()
{
    theApp = this;
}

void CApplication::About()
{
    SendMessage(mhWnd, WM_COMMAND, IDM_ABOUT, 0);
}

void CApplication::화면갱신()
{
    InvalidateRect(mhWnd, NULL, TRUE);
}
