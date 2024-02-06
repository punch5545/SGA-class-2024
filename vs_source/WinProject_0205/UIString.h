#pragma once
#include "IUserInterface.h"
#include <vector>

class UIString : public IUserInterface
{
public:
	UIString();

	virtual void Draw() override;

	LPCWSTR CurrentString;
	std::vector<LPCWSTR> StringList;

	HFONT font = NULL;
};

