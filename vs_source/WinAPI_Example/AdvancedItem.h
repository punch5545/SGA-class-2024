#pragma once
#include "Item.h"


class AdvancedItem : public ItemBase
{
public:
    AdvancedItem();
    AdvancedItem(int Index, std::wstring Name, int Price);
    ~AdvancedItem();

    bool Buy() override;
    bool Sell() override;

    bool hasSubItem(int idx) override;
};