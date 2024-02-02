#include "pch.h"
#include "Control.h"
#include "Button.h"

Form::Button::Button(HWND& hWnd, LPCWSTR Text, Coordinate Position, DWORD Style)
    :Control(ClassName, Text, Position, true, true)
{
    HWND hwndButton = CreateWindow(
        ClassName,          // Predefined class; Unicode assumed 
        Text,               // Button text 
        Style,              // Styles 
        Position.x,         // x position 
        Position.y,         // y position 
        Position.width,     // Button width
        Position.height,    // Button height
        hWnd,               // Parent window
        NULL,               // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);              // Pointer not needed.

    __super::mHandle = hwndButton;
}

//WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON

Form::Button::Button(HWND& hWnd, LPCWSTR Text, int cx, int cy, int width, int height, DWORD Style)
{
    HWND hwndButton = CreateWindow(
        ClassName,          // Predefined class; Unicode assumed 
        Text,               // Button text 
        Style,              // Styles 
        cx,                 // x position 
        cy,                 // y position 
        width,              // Button width
        height,             // Button height
        hWnd,               // Parent window
        NULL,               // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);              // Pointer not needed.

    __super::mHandle = hwndButton;
}


Form::Button::Button(HWND& hWnd, LPCWSTR Text, Coordinate Position)
{
    HWND hwndButton = CreateWindow(
        ClassName,          // Predefined class; Unicode assumed 
        Text,               // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
        Position.x,         // x position 
        Position.y,         // y position 
        Position.width,     // Button width
        Position.height,    // Button height
        hWnd,               // Parent window
        NULL,               // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);              // Pointer not needed.

    __super::mHandle = hwndButton;
}

Form::Button::Button(HWND& hWnd, LPCWSTR Text, int cx, int cy, int width, int height)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);

    HWND hwndButton = CreateWindow(
        ClassName,          // Predefined class; Unicode assumed 
        Text,               // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
        cx,                 // x position 
        cy,                 // y position 
        width,              // Button width
        height,             // Button height
        hWnd,               // Parent window
        NULL,               // No menu.
        hInstance,
        NULL);              // Pointer not needed.

    __super::mHandle = hwndButton;
}



