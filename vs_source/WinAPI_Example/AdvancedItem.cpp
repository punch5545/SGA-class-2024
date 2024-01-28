#include "pch.h"
#include "AdvancedItem.h"

AdvancedItem::AdvancedItem()
{
}

AdvancedItem::AdvancedItem(int Index, std::wstring Name, int Price)
	: ItemBase(Index, Name, Price)
{
	this->Grade = ItemGrade::ADVANCED;
	this->sellRatio = 0.6;
	this->SubItems = { 0 };
}

AdvancedItem::~AdvancedItem()
{
}

bool AdvancedItem::Buy()
{
	return false;
}

bool AdvancedItem::Sell()
{
	return false;
}

int AdvancedItem::GetSubCount()
{
	return 0;
}

bool AdvancedItem::hasSubItem(int idx)
{
	return false;
}
