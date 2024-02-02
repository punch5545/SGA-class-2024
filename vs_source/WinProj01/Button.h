#pragma once
namespace Form
{
	// https://learn.microsoft.com/ko-kr/windows/win32/controls/create-a-button
	class Button : public Control
	{
	private:
	public:
		Button(HWND& hWnd, LPCWSTR Text, Coordinate Position, DWORD Style);
		Button(HWND& hWnd, LPCWSTR Text, int cx, int cy, int width, int height, DWORD Style);
		Button(HWND& hWnd, LPCWSTR Text, Coordinate Position);
		Button(HWND& hWnd, LPCWSTR Text, int cx, int cy, int width, int height);

	};
}