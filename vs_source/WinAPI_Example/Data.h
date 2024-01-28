#pragma once
#define MAX_ITEMS_COUNT 6

#include "Item.h"
#include "BasicItem.h"
#include "AdvancedItem.h"
#include "LegendaryItem.h"

class Data
{
public:
	int MyWallet = 0;

	std::map<int, ItemBase*> myItems;
	std::map<int, BasicItem*> BasicItems;
	std::map<int, AdvancedItem*> AdvancedItems;
	std::map<int, LegendaryItem*> LegendaryItems;

	void InitItems();
	std::wstring GetItemInfo(ItemBase* item);
	void RightClickMyItem(ItemBase* item);
};