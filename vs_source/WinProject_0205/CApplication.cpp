#include "pch.h"
#include "CGameFQ4.h"
#include "CApplication.h"

CApplication* CApplication::theApp = NULL;

CApplication app;

CApplication::CApplication()
{
    theApp = this;
}

void CApplication::ȭ�鰻��()
{
    InvalidateRect(mhWnd, NULL, TRUE);
}
