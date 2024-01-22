#pragma once

class HeartManager
{
public:
	Heart* m_Hearts[100];
	int m_HeartsCount;
	int m_objIdx;

	HeartManager()
	{
		for (int i = 0; i < 100; i++)
			m_Hearts[i] = NULL;

		m_HeartsCount = 0;
		m_objIdx = 101;
	}

	~HeartManager()
	{
		for (int i = 0; i < 100; i++)
			if (m_Hearts[i]) delete m_Hearts[i];

		m_HeartsCount = 0;
	}

	void Make(int sx, int sy)
	{
		Heart* h2 = new Heart();

		h2->objNo = ++m_objIdx;
		h2->posX = sx;
		h2->posY = sy;
		h2->dirX = 1;
		h2->dirY = 0;

		m_Hearts[m_HeartsCount] = h2;
		++m_HeartsCount;
	}

	void Draw(Screen* scrn)
	{
		for (int i = 0; i < m_HeartsCount; ++i)
		{
			if (m_Hearts[i])
				m_Hearts[i]->f_그리기(scrn);
		}
	}

	void Move(Screen* scrn)
	{
		for (int i = 0; i < m_HeartsCount; ++i)
		{
			if (m_Hearts[i]) m_Hearts[i]->f_이동하기();
		}
	}
};
