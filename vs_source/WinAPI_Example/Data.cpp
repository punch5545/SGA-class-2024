#include "pch.h"
#include "Data.h"

void Data::InitItems()
{
	BasicItem* �ռҵ� = new BasicItem(1, L"�ռҵ�", 350);
	BasicItem* �ܰ� = new BasicItem(2, L"�ܰ�", 300);
	BasicItem* ��� = new BasicItem(3, L"���", 875);
	BasicItem* ���� = new BasicItem(4, L"��ø���� ����", 600);
	BasicItem* BF = new BasicItem(5, L"B.F ���", 1300);

	AdvancedItem* ��� = new AdvancedItem(11, L"���", 400);
	AdvancedItem* �� = new AdvancedItem(12, L"������ ��", 550);

	LegendaryItem* ��� = new LegendaryItem(101, L"�ǹٶ��", 600);
	LegendaryItem* ���հ� = new LegendaryItem(102, L"������ ���� ��", 725);


	�ռҵ�->Image = new Gdiplus::Image(L"images/�ռҵ�.png");
	�ܰ�->Image = new Gdiplus::Image(L"images/�ܰ�.png");
	���->Image = new Gdiplus::Image(L"Images/���.png");
	����->Image = new Gdiplus::Image(L"images/����.png");
	BF->Image = new Gdiplus::Image(L"images/BF.png");

	���->Image = new Gdiplus::Image(L"images/���.png");
	��->Image = new Gdiplus::Image(L"images/��.png");

	���->Image = new Gdiplus::Image(L"images/���.png");
	���հ�->Image = new Gdiplus::Image(L"images/���հ�.png");

	�ռҵ�->SetSubItems({ 0 });
	�ܰ�->SetSubItems({ 0 });
	���->SetSubItems({ 0 });
	����->SetSubItems({ 0 });
	BF->SetSubItems({ 0 });

	���->SetSubItems({ 2, 2 });
	��->SetSubItems({ 1 });

	���->SetSubItems({ 5, 4, 12 });
	���հ�->SetSubItems({ 12, 11, 3 });


	BasicItems.insert({ 1, �ռҵ� });
	BasicItems.insert({ 2, �ܰ� });
	BasicItems.insert({ 3, ��� });
	BasicItems.insert({ 4, ���� });
	BasicItems.insert({ 5, BF });

	AdvancedItems.insert({ 11, ��� });
	AdvancedItems.insert({ 12, �� });

	LegendaryItems.insert({ 101, ��� });
	LegendaryItems.insert({ 102, ���հ� });

	myItems.insert({ 101, ��� });
	myItems.insert({ 102, ���հ� });
}

std::wstring Data::GetItemInfo(ItemBase* item)
{
	auto myItem = myItems.find(item->GetIndex());

	if (myItem == myItems.end())
		return L"N/A";
		
	return (myItem->second)->GetItemInfo();
}

void Data::RightClickMyItem(ItemBase* item)
{
	auto myItem = myItems.find(item->GetIndex());

	if (myItem == myItems.end())
		return;

	(myItem->second)->Sell();
}