#pragma once
#include "Item.h"

class LegendaryItem : public ItemBase
{
public:
    LegendaryItem();
    LegendaryItem(int Index, std::wstring Name, int Price);
    ~LegendaryItem();

    bool Buy() override;
    bool Sell() override;

    int GetSubCount() override;
    bool hasSubItem(int idx) override;
};
