#include "pch.h"
#include "CApplication.h"

CApplication* CApplication::theApp = NULL;

CApplication::CApplication()
{
	theApp = this;
}
