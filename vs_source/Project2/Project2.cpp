// Project2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

#define X_LENGTH 121
#define Y_LENGTH 29
#define X_WALL ( X_LENGTH - 3 )
#define Y_WALL ( Y_LENGTH - 1 )

void MoveCursor(int x, int y);


void PrintBackground();
void PrintHeart(int x, int y);

char screen1[Y_LENGTH][X_LENGTH] = { 0 };
const unsigned char Sqr1 = -95;
const unsigned char Sqr2 = -31;

int x = 0;
int yc = 0;
int x_direction = 0;
int y_direction = 0;

int main()
{
    ZeroMemory(screen1, 121 * 30);
    while (true)
    {
        MoveCursor(0, 0);

        for (int y = 0; y < Y_LENGTH; y++)
        {
            PrintBackground();
            PrintHeart(x + 1, yc);
            printf("%s\n", screen1[y]);
        }

        
        if (x_direction == 0) x++;
        else x--;

        if (y_direction == 0) yc++;
        else yc--;

        if (x > 90 && x_direction == 0) x_direction = 1;
        if (x < 1 && x_direction == 1) x_direction = 0;

        if (yc > 17 && y_direction == 0) y_direction = 1;
        if (yc < 3 && y_direction == 1) y_direction = 0;


        Sleep(10);
    }

}

void PrintBackground()
{
    for (int y = 0; y < Y_LENGTH; y++)
    {
        for (int x = 0; x < X_LENGTH - 1; x += 2)
        {
            if (x == 0 || x == X_WALL || y == 0 || y == Y_WALL)
            {
                screen1[y][x] = Sqr1;
                screen1[y][x + 1] = Sqr2;
            }
            else {
                screen1[y][x] = ' ';
                screen1[y][x + 1] = ' ';
            }
            int a = 0;
        }
        screen1[y][X_LENGTH - 1] = 0;
    }
}

void PrintHeart(int xc, int yc)
{
    int coord[10][4] = {
        { 3, 4, 8, 9 },
        { 2, 5, 7, 10 },
        { 1, 6, 11, -1 },
        { 1, 11, -1, -1 },
        { 1, 11, -1, -1 },
        { 2, 10, -1, -1 },
        { 3, 9, -1, -1 },
        { 4, 8, -1, -1 },
        { 5, 7, -1, -1 },
        { 6, -1, -1, -1 }
    };

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (coord[y][x] < 0) break;

            int x_coord = (coord[y][x] * 2) + xc;

            screen1[y + yc][x_coord] = Sqr1;
            screen1[y + yc][x_coord + 1] = Sqr2;
        }
    }
}


void MoveCursor(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

/*
15 16 20 21
14 17 19 22
13 18 23 x 3
14 22
15 21
16 20
17 19
18

*/




// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
