#pragma once
class CText
{
public:
	CText();
	~CText();

public:
	void Out(HDC hdc, int width, int height, LPCWSTR fontName, int weight, LPCWSTR string);
	void Out(HDC hdc, int width, int height, LPCWSTR fontName, int weight, LPCWSTR string, Color color, bool italic = false, bool underline = false, bool strike = false);

public:
	static CText* instance;
};

