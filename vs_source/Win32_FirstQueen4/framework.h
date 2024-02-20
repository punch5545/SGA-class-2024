#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <windowsx.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <math.h>
#include <functional>
#include <vector>
#include <map>
#include <string>




#pragma region GameMessages

#define VK_ANYKEY 0xFF

#define GM_EXIT 0x00

#define GM_NEWGAME 0xA0
#define GM_SAVE1 0xA1
#define GM_SAVE2 0xA2
#define GM_SAVE3 0xA3
#define GM_SAVE4 0xA4

#pragma endregion