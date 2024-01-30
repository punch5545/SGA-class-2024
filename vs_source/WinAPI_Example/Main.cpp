#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "pch.h"
#include "Data.h"


const LPCWSTR WINDOWS_CLASS_NAME = L"WinAPI Example";

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void DrawPNG(HDC hdc, int x, int y, int width, int height, std::wstring Path);
void DrawPNG(HDC hdc, int x, int y, int width, int height, Gdiplus::Image* image);
void DrawImageWithOpacity(HDC hdc, Gdiplus::Image* image, int x, int y, int width, int height, float opacity);
void DrawSubItems(HDC hdc, ItemBase* itemBase, int x, int y, ItemGrade grade = LEGENDARY);

Data *data;

int hoverKey = -1;
int currentClick = -1;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpszCmdParam, int nCmdShow)
{

	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(lpszCmdParam);

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	data = new Data();
	data->InitItems();

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wndClass.hCursor = LoadIcon(hInstance, IDC_CROSS);
	wndClass.hIcon = LoadIcon(hInstance, IDI_ERROR);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	wndClass.lpszClassName = WINDOWS_CLASS_NAME;
	wndClass.lpszMenuName = nullptr;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndClass);

	HWND hwnd = CreateWindow
	(
		WINDOWS_CLASS_NAME,
		L"This is a WinAPI Example",
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG message;
	ZeroMemory(&message, sizeof(MSG));

	while (true)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	DestroyWindow(hwnd);
	UnregisterClass(WINDOWS_CLASS_NAME, hInstance);

	Gdiplus::GdiplusShutdown(gdiplusToken);

	delete(data);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;


	case WM_PAINT: {
		PAINTSTRUCT ps;
		/** 더블버퍼링 시작처리입니다. **/
		static HDC hdc, MemDC, tmpDC;
		static HBITMAP BackBit, oldBackBit;
		static RECT bufferRT;
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &bufferRT);
		MemDC = CreateCompatibleDC(hdc);
		BackBit = CreateCompatibleBitmap(hdc, bufferRT.right, bufferRT.bottom);
		oldBackBit = (HBITMAP)SelectObject(MemDC, BackBit);
		PatBlt(MemDC, 0, 0, bufferRT.right, bufferRT.bottom, WHITENESS);
		tmpDC = hdc;
		hdc = MemDC;
		MemDC = tmpDC;

		// TODO: 여기에 그리기 코드를 추가합니다.
		int padding = 10;
		int i = 0;

		for (const auto& item : data->LegendaryItems) {
			int key = item.first;
			LegendaryItem* value = item.second;

			int x = padding;
			int y = padding + (i++ * 80);

			Rectangle(hdc, x, y, x + 64, y + 64);

			if (hoverKey == key)
			{
				DrawImageWithOpacity(hdc, value->Image, x, y, 64, 64, 0.5f);
			}
			else
				DrawPNG(hdc, x, y, 64, 64, value->Image);

			if (currentClick == key)
				DrawSubItems(hdc, value, 100, y, LEGENDARY);
		}

		/** 더블버퍼링 끝처리 입니다. **/
		tmpDC = hdc;
		hdc = MemDC;
		MemDC = tmpDC;
		GetClientRect(hwnd, &bufferRT);
		BitBlt(hdc, 0, 0, bufferRT.right, bufferRT.bottom, MemDC, 0, 0, SRCCOPY);
		SelectObject(MemDC, oldBackBit);
		DeleteObject(BackBit);
		DeleteDC(MemDC);
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_MOUSEMOVE:
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hwnd, &pt);

		int padding = 10;
		int i = 0;
		for (const auto& item : data->LegendaryItems) {
			int key = item.first;
			LegendaryItem* value = item.second;

			int x = padding;
			int y = padding + (i++ * 80);

			if (pt.x >= x && pt.x <= x + 64 && pt.y >= y && pt.y <= y + 64) {
				if (hoverKey != key) {
					hoverKey = key;
				}
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else
			{
				if (hoverKey == key) {
					hoverKey = -1;
				}
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}

		if (hoverKey != -1)
			SetCursor(LoadCursor(NULL, IDC_HAND));
		else
			SetCursor(LoadCursor(NULL, IDC_ARROW));

		break;
	}
	case WM_ERASEBKGND:
		return 1;

	case WM_LBUTTONDOWN:
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hwnd, &pt);

		int padding = 10;
		int i = 0;
		for (const auto& item : data->LegendaryItems) {
			int key = item.first;
			LegendaryItem* value = item.second;

			int x = padding;
			int y = padding + (i++ * 80);

			if (pt.x >= x && pt.x <= x + 64 && pt.y >= y && pt.y <= y + 64) {
				currentClick = key;
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}
		break;
	}
	return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void DrawPNG(HDC hdc, int x, int y, int width, int height, std::wstring Path)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Image image(Path.c_str());

	graphics.DrawImage(&image, x, y, width, height);
}

void DrawPNG(HDC hdc, int x, int y, int width, int height, Gdiplus::Image* image)
{
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(image, x, y, width, height);
}

void DrawImageWithOpacity(HDC hdc, Gdiplus::Image* image, int x, int y, int width, int height, float opacity)
{
	Gdiplus::Graphics graphics(hdc);

	// 색상 매트릭스를 사용하여 불투명도 설정
	Gdiplus::ColorMatrix colorMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, opacity, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	Gdiplus::ImageAttributes imageAttributes;
	imageAttributes.SetColorMatrix(&colorMatrix);

	// 이미지 그리기
	graphics.DrawImage(image, Gdiplus::Rect(x, y, width, height), 0, 0, image->GetWidth(), image->GetHeight(), Gdiplus::UnitPixel, &imageAttributes);
}

void DrawSubItems(HDC hdc, ItemBase* itemBase, int x, int y, ItemGrade grade)
{
	int i = 1;
	int padding = 10;

	for (const auto& item : itemBase->GetSubItems())
	{
		switch (grade)
		{
		case BASIC: break;
		case ADVANCED:
			for (const auto& sub1 : data->BasicItems)
			{
				if (item == sub1.second->GetIndex())
					DrawPNG(hdc, x + (64 * i) + (padding * i), y, 64, 64, sub1.second->Image);
				i++;
			}
			break;
		case LEGENDARY: 
			for (const auto& sub1 : data->BasicItems)
			{
				if (item == sub1.second->GetIndex())
				{
					DrawPNG(hdc, x + (64 * i) + (padding * i), y, 64, 64, sub1.second->Image);
					i++;
				}
			}
			for (const auto& sub1 : data->AdvancedItems)
			{
				if (item == sub1.second->GetIndex())
				{
					DrawPNG(hdc, x + (64 * i) + (padding * i), y, 64, 64, sub1.second->Image);
					i++;
				}
			}

			break;
		default:break;
		}
	}
}