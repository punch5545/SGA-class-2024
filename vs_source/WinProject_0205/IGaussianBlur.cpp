#include "pch.h"
#include "IGaussianBlur.h"

IGaussianBlur::IGaussianBlur(UINT32* Colors, UINT width, UINT height, UINT blurSize, UINT sigma)
	:IPostProcess(Colors, width, height), 
	m_blurSize(blurSize), m_width(width), m_height(height), m_sigma(sigma)
{
	this->m_pTmpColors = new UINT32 * [height];
	for (int y = 0; y < height; y++)
	{
		m_pTmpColors[y] = new UINT32[width];
	}

	this->m_topHeight = 1 / (sqrt(2 * PI) * m_sigma);
	this->m_pixelAverage = 0;
}

IGaussianBlur::~IGaussianBlur()
{
	delete m_pTmpColors;
}

void IGaussianBlur::Execute()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			for (int i = (-1 * m_blurSize / 2); i <= (m_blurSize / 2); i++)
			{
				int minNo = min(0, i + x);
				int maxNo = max(i + x, m_width);
				//__super::m_pColors[y][x];
			}
		}
	}
}
