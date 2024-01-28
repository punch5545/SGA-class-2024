#include "pch.h"
#include "Item.h"

ItemBase::ItemBase()
{
	Index = 0;
	Name = L"";
	Price = 0;
	Grade = ItemGrade::BASIC;
	sellRatio = 0;
	SubItems = { 0 };
}

ItemBase::ItemBase(int Index, std::wstring Name, int Price)
	:Index(Index), Name(Name), Price(Price)
{
	Grade = ItemGrade::BASIC;
	sellRatio = 50;
	SubItems = { 0 };
}

ItemBase::~ItemBase()
{
}

bool ItemBase::Buy()
{
	return false;
}

bool ItemBase::Sell()
{
	return false;
}

int ItemBase::GetSubCount()
{
	return 0;
}

bool ItemBase::hasSubItem(int idx)
{
	return false;
}

void ItemBase::SetSubItems(std::vector<int> SubItems)
{
	this->SubItems = SubItems;
}

std::wstring ItemBase::GetItemInfo()
{
	std::wstring info = L"";
	info += L"이름: " + std::wstring(Name.begin(), Name.end()) + L"\n";
	info += L"구매가: " + std::to_wstring(Price) + L"\n";
	info += L"등급: " + std::to_wstring((int)Grade) + L"\n";
	info += L"판매가: " + std::to_wstring((int)(sellRatio * Price)) + L"\n";
	
	return info;
}
