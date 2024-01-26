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
	void f_��ũ���ʱ�ȭ()
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

	void f_��ũ���׸���()
	{
		for (int y = 0; y < SCREEN_MAX_Y; y++)
		{
			for (int x = 0; x < SCREEN_MAX_X; x++)
			{
				char color = m_Screen[y][x].color;

				switch (color)
				{
				case 0: printf(".."); break;
				case 8: printf("��"); break;
				default: printf("  "); break;
				}
			}

			printf("\n");
		}
	}
};


void f_��_�׸���(Screen* scrn)
{
	// ���Ʒ�
	for (int x = 0; x < SCREEN_MAX_X; x++)
	{
		// ����
		scrn->m_Screen[0][x].color = 8;
		scrn->m_Screen[0][x].objNo = 100;

		// �ǾƷ�
		scrn->m_Screen[SCREEN_MAX_Y - 1][x].color = 8;
		scrn->m_Screen[SCREEN_MAX_Y - 1][x].objNo = 100;
	}

	// �¿�
	for (int y = 0; y < SCREEN_MAX_Y; y++)
	{
		// ����
		scrn->m_Screen[y][0].color = 8;
		scrn->m_Screen[y][0].objNo = 100;

		// ������
		scrn->m_Screen[y][SCREEN_MAX_X - 1].color = 8;
		scrn->m_Screen[y][SCREEN_MAX_X - 1].objNo = 100;
	}

}
