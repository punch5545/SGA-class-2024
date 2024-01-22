#pragma once

class Heart
{
public:
	int posX;
	int posY;
	int objNo;
	int dirX;
	int dirY;

	void f_그리기(Screen* scrn)
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 13; x++)
			{
				char color = heart[y][x];

				if (color == 0) {}
				else
				{
					scrn->m_Screen[posY + y][posX + x].color = color;
					scrn->m_Screen[posY + y][posX + x].objNo = this->objNo;
				}
			}
		}
	}
	void f_이동하기()
	{
		int old_x = posX;
		int old_y = posY;

		posX += dirX;
		posY += dirY;

		if (posX + 13 >= SCREEN_MAX_X - 1)
		{
			if (posY + 10 < SCREEN_MAX_Y - 1)
			{
				dirY = 1;
				dirX = 0;
			}
			else
			{
				dirY = 0;
				dirX = -1;
			}
		}
		else if (posX <= 1)
		{
			if (posY <= 1)
			{
				dirY = 0;
				dirX = 1;
			}
			else
			{
				dirY = -1;
				dirX = 0;
			}
		}
	}
};
