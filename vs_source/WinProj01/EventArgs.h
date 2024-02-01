#pragma once
namespace Form
{
	class EventArgs
	{
	public:
		EventArgs(HWND* hWnd, WPARAM* wParam, LPARAM* lParam)
			:hWnd(hWnd), wParam(wParam), lParam(lParam)
		{}

		HWND* hWnd;
		WPARAM* wParam;
		LPARAM* lParam;
	};
	extern EventArgs eventArgs;
}
