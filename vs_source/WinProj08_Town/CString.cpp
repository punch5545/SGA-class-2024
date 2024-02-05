#include "pch.h"
#include "CString.h"

#include "resource.h"

void CString::Draw(HDC hdc, LPCWSTR str)
{
	TextOut(hdc, 100, 100, str, wcslen(str));
}
