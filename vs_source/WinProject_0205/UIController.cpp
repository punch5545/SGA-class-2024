#include "pch.h"
#include "UIController.h"



void UIController::onDraw(HDC hdc)
{
    for (auto ui : UIList)
    {
        // ui.second->Draw(hdc)
    }
}

int UIController::addUI(IUserInterface* ui)
{
    int idx = UIList.size();
    UIList.insert({ idx, ui });

    return idx;
}

bool UIController::removeUI(int idx)
{
    int size = UIList.size();
    UIList.erase(idx);

    return size > UIList.size();
}

bool UIController::removeAllUIs()
{
    for (auto& val : UIList)
    {
        UIList.erase(val.first);
    }

    return UIList.size() == 0;
}
