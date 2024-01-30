#include "pch.h"
#include "LegendaryItem.h"

LegendaryItem::LegendaryItem()
{
}

LegendaryItem::LegendaryItem(int Index, std::wstring Name, int Price)
	: ItemBase(Index, Name, Price)
{
	this->Grade = ItemGrade::LEGENDARY;
	this->sellRatio = 0.75;
	this->SubItems = { 0 };
}

LegendaryItem::~LegendaryItem()
{
}

bool LegendaryItem::Buy()
{
	return false;
}

bool LegendaryItem::Sell()
{
	return false;
}

bool LegendaryItem::hasSubItem(int idx)
{
	return false;
}
