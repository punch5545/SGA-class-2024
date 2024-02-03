#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

#define SQUARE_IDX 0
#define Z_IDX 1
#define Z_REVERSE_IDX 2
#define L_IDX 3
#define L_REVERSE_IDX 4
#define T_IDX 5
#define I_IDX 6

#define FRAME_RATE 165

#define FRAME_PER_SECOND (1000 / FRAME_RATE)

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_ENTER 13

#define KEY_C 99
#define KEY_Z 122


#define COLOR_RED (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define COLOR_GREEN FOREGROUND_GREEN
#define COLOR_BLUE (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_CYAN (FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY)
#define COLOR_ORANGE (FOREGROUND_RED | FOREGROUND_GREEN)
#define COLOR_MAGENTA (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_PURPLE (FOREGROUND_RED | FOREGROUND_BLUE)

#define COLOR_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)



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
	HardDown = KEY_SPACE,
	Rotate = KEY_UP,
	RotateReverse = KEY_Z,
	Exit = KEY_ESC,
	Hold = KEY_C
};

typedef struct TetrisBlock
{
	int Data;
	DWORD Color;
} TetrisBlock;



#endif //PCH_H
