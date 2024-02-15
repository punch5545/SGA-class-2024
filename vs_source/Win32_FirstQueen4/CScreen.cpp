#include "pch.h"
#include "CScreen.h"

void CScreen::Draw(HDC hdc)
{
	BitBlt(hdc,
		0, 0,
		getWidth(), getHeight(),
		m_HDC,
		0, 0, SRCCOPY
	);
}
