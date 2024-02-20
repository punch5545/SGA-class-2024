// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "framework.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define WINDOW_WIDTH 667
#define WINDOW_HEIGHT 559

#define WINDOW_SCREEN_CENTER_X ((SCREEN_WIDTH / 2) - (WINDOW_WIDTH / 2))
#define WINDOW_SCREEN_CENTER_Y ((SCREEN_HEIGHT / 2) - (WINDOW_HEIGHT / 2))

#define WINDOW_INTERNAL_CENTER_X (WINDOW_WIDTH / 2)
#define WINDOW_INTERNAL_CENTER_Y (WINDOW_HEIGHT / 2)

#define PI 3.14159265

struct RGBA {
	BYTE B, G, R, A;
	RGBA() : R(0), G(0), B(0), A(0) {}
	RGBA(BYTE r, BYTE g, BYTE b, BYTE a) : R(r), G(g), B(b), A(a) {}

	RGBA operator+(RGBA right)
	{
		R += right.R;
		G += right.G;
		B += right.B;
		A += right.A;

		return *this;
	}
};

union Color
{
	UINT32 color;
	RGBA argb;
	Color() : color(0) {}
	Color(UINT32 color) :color(color) {}
	Color(RGBA argb) : argb(argb) {}
	Color(BYTE r, BYTE g, BYTE b, BYTE a) : argb(RGBA(r, g, b, a)) {}
};

struct Vector2
{
	Vector2(int x, int y) : X(x), Y(y) {}
	Vector2() : X(0), Y(0) {}
	int X;
	int Y;
};

struct Vector3
{
	Vector3() 
		: X(0), Y(0), Z(0) {}
	Vector3(double X, double Y, double Z)
		: X(X), Y(Y), Z(Z) {}

	double X;
	double Y;
	double Z;
};

struct RectTransform
{
	RectTransform()
		: Left(0), Right(0), Top(0), Bottom(0) {}
	RectTransform(double left, double right, double top, double bottom) 
		: Left(left), Right(right), Top(top), Bottom(bottom) {}

	double Left;
	double Right;
	double Top;
	double Bottom;
};


typedef std::function<void()> CALLBACK_FUNC;

#endif //PCH_H
