#include "pch.h"
#include "BasicItem.h"

BasicItem::BasicItem()
{
}

BasicItem::BasicItem(int Index, std::wstring Name, int Price)
	: ItemBase(Index, Name, Price)
{
	this->Grade = ItemGrade::BASIC;
	this->sellRatio = 0.5;
	this->SubItems = { 0 };
}

BasicItem::~BasicItem()
{
}

bool BasicItem::Buy()
{
	return false;
}

bool BasicItem::Sell()
{
	return false;
}
