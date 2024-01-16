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

#define FRAME_RATE 30

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


typedef struct Tetrimino {
	int index;
	int bricks[4][4];
	int rotateState;
	int maxRotate;
	int x, y;

} Tetrimino;


#endif //PCH_H
