// ConGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Functions.h"


int main()
{
	int cnt = 0;
	int sleepTime = 300;
	int kbHit = 0;
	bool isLoop = false;

	while(true)
	{
		if (_kbhit())
		{
			int key = _getch();
			printf("Key Hitted: %c | %d", key, key);
			if (isLoop) StartGame();
		}

		MoveCursor(0, 0);

		PrintBackground();
		if (!isStart)
		{
			printAnimation(cnt);
			printFoot(isLoop);
		}

		cnt++;
		Sleep(sleepTime);
		
		if(cnt > 7) isLoop = true;
		if (cnt > 15) cnt = 0;
	}
}





/*
■■
■■

■■■■

■
■
■
■

■■
  ■■

  ■
■■
■

■
■■
  ■

  ■■
■■

■■■
■

■■
  ■
  ■

	■
■■■

■
■
■■

■
■■■

■■
■
■

■■■
	■

  ■
  ■
■■

■■■
  ■

  ■
■■
  ■

  ■
■■■

  ■
  ■■
  ■
*/