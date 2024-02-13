#pragma once
#include "IPostProcess.h"
class IGaussianBlur : public IPostProcess
{
	UINT32** m_pTmpColors;
	int m_blurSize;
	int m_width;
	int m_height;

	double m_topHeight;
	double m_pixelAverage;
	int m_sigma;

protected:
	IGaussianBlur(UINT32* Colors, UINT width, UINT height, UINT blurSize, UINT sigma);
	~IGaussianBlur();

public:
	virtual void Execute() override;
};

