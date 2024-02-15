#include "pch.h"
#include "IPostProcess.h"

IPostProcess::IPostProcess(UINT32* Colors, int width, int height)
{
	this->m_pColors = new UINT32*[height];
	for (int y = 0; y < height; y++)
	{
		m_pColors[y] = new UINT32[width];
		for (int x = 0; x < width; x++)
		{
			m_pColors[y][x] = Colors[y * width + x];
		}
	}
}

IPostProcess::~IPostProcess()
{
	delete m_pColors;
}
