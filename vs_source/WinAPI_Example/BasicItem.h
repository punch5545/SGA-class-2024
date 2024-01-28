#pragma once
#include "Item.h"

class BasicItem : public ItemBase
{
public:
    BasicItem();
    BasicItem(int Index, std::wstring Name, int Price);
    ~BasicItem();

    bool Buy() override;
    bool Sell() override;
};
