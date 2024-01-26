#pragma once

struct PIXEL
{
	int objNo;
	int color;
};

class Screen
{
private:

public:
	PIXEL m_Screen[SCREEN_MAX_Y][SCREEN_MAX_X];
	void f_스크린초기화()
	{
		for (int y = 0; y < SCREEN_MAX_Y; y++)
		{
			for (int x = 0; x < SCREEN_MAX_X; x++)
			{
				m_Screen[y][x].objNo = -1;
				m_Screen[y][x].color = 0;
			}
		}
	}

	void f_스크린그리기()
	{
		for (int y = 0; y < SCREEN_MAX_Y; y++)
		{
			for (int x = 0; x < SCREEN_MAX_X; x++)
			{
				char color = m_Screen[y][x].color;

				switch (color)
				{
				case 0: printf(".."); break;
				case 8: printf("■"); break;
				default: printf("  "); break;
				}
			}

			printf("\n");
		}
	}
};


void f_벽_그리기(Screen* scrn)
{
	// 위아래
	for (int x = 0; x < SCREEN_MAX_X; x++)
	{
		// 맨위
		scrn->m_Screen[0][x].color = 8;
		scrn->m_Screen[0][x].objNo = 100;

		// 맨아래
		scrn->m_Screen[SCREEN_MAX_Y - 1][x].color = 8;
		scrn->m_Screen[SCREEN_MAX_Y - 1][x].objNo = 100;
	}

	// 좌우
	for (int y = 0; y < SCREEN_MAX_Y; y++)
	{
		// 왼쪽
		scrn->m_Screen[y][0].color = 8;
		scrn->m_Screen[y][0].objNo = 100;

		// 오른쪽
		scrn->m_Screen[y][SCREEN_MAX_X - 1].color = 8;
		scrn->m_Screen[y][SCREEN_MAX_X - 1].objNo = 100;
	}

}
