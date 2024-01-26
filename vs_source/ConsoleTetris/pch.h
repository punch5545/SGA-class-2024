// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <Windows.h>
#include <conio.h>

#define SQUARE_IDX 0
#define Z_IDX 1
#define Z_REVERSE_IDX 2
#define L_IDX 3
#define L_REVERSE_IDX 4
#define T_IDX 5
#define I_IDX 6

#define SCREEN_SIZE_X 60
#define SCREEN_SIZE_Y 30

#define FRAME_RATE 60

#define FRAME_PER_SECOND (1000 / FRAME_RATE)

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_ENTER 13

#define KEY_C 99
#define KEY_LEFT_CTRL 17

void MoveCursorTo(int x, int y);


enum TetriminoType
{
	Square,
	Z,
	Z_Reverse,
	L,
	L_Reverse,
	T,
	I
};

enum Direction
{
	Left = KEY_LEFT,
	Right = KEY_RIGHT,
	Down = KEY_DOWN,
	HardDown = KEY_SPACE
};

struct Pixel
{
	int Index;
	char Shape;
};


#include "Screen.h"


#endif //PCH_H
