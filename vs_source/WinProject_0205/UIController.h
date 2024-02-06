#pragma once
#include <map>

class IUserInterface;

class UIController
{
public:
	static UIController* instance;

	static std::map<int, IUserInterface*> UIList;

	static void onDraw(HDC hdc);
	
	static int addUI(IUserInterface* ui);
	static bool removeUI(int idx);

	static bool removeAllUIs();
};

