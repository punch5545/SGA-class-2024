#pragma once
class IPostProcess
{

protected:
	IPostProcess(UINT32* Colors, int width, int height);
	~IPostProcess();

	UINT32** m_pColors;
public:
	virtual void Execute() = 0;
};

