#include "pch.h"
#include "Data.h"

void Data::InitItems()
{
	BasicItem* ·Õ¼Òµå = new BasicItem(1, L"·Õ¼Òµå", 350);
	BasicItem* ´Ü°Ë = new BasicItem(2, L"´Ü°Ë", 300);
	BasicItem* °î±ªÀÌ = new BasicItem(3, L"°î±ªÀÌ", 875);
	BasicItem* ¸ÁÅä = new BasicItem(4, L"¹ÎÃ¸¼ºÀÇ ¸ÁÅä", 600);
	BasicItem* BF = new BasicItem(5, L"B.F ´ë°Ë", 1300);

	AdvancedItem* °î±Ã = new AdvancedItem(11, L"°î±Ã", 400);
	AdvancedItem* Èí³´ = new AdvancedItem(12, L"ÈíÇ÷ÀÇ ³´", 550);

	LegendaryItem* ºí½á = new LegendaryItem(101, L"ÇÇ¹Ù¶ó±â", 600);
	LegendaryItem* ¸ô¿Õ°Ë = new LegendaryItem(102, L"¸ô¶ôÇÑ ¿ÕÀÇ °Ë", 725);


	·Õ¼Òµå->Image = new Gdiplus::Image(L"images/·Õ¼Òµå.png");
	´Ü°Ë->Image = new Gdiplus::Image(L"images/´Ü°Ë.png");
	°î±ªÀÌ->Image = new Gdiplus::Image(L"Images/°î±ªÀÌ.png");
	¸ÁÅä->Image = new Gdiplus::Image(L"images/¸ÁÅä.png");
	BF->Image = new Gdiplus::Image(L"images/BF.png");

	°î±Ã->Image = new Gdiplus::Image(L"images/°î±Ã.png");
	Èí³´->Image = new Gdiplus::Image(L"images/Èí³´.png");

	ºí½á->Image = new Gdiplus::Image(L"images/ºí½á.png");
	¸ô¿Õ°Ë->Image = new Gdiplus::Image(L"images/¸ô¿Õ°Ë.png");

	·Õ¼Òµå->SetSubItems({ 0 });
	´Ü°Ë->SetSubItems({ 0 });
	°î±ªÀÌ->SetSubItems({ 0 });
	¸ÁÅä->SetSubItems({ 0 });
	BF->SetSubItems({ 0 });

	°î±Ã->SetSubItems({ 2, 2 });
	Èí³´->SetSubItems({ 1 });

	ºí½á->SetSubItems({ 5, 4, 12 });
	¸ô¿Õ°Ë->SetSubItems({ 12, 11, 3 });


	BasicItems.insert({ 1, ·Õ¼Òµå });
	BasicItems.insert({ 2, ´Ü°Ë });
	BasicItems.insert({ 3, °î±ªÀÌ });
	BasicItems.insert({ 4, ¸ÁÅä });
	BasicItems.insert({ 5, BF });

	AdvancedItems.insert({ 11, °î±Ã });
	AdvancedItems.insert({ 12, Èí³´ });

	LegendaryItems.insert({ 101, ºí½á });
	LegendaryItems.insert({ 102, ¸ô¿Õ°Ë });

	myItems.insert({ 101, ºí½á });
	myItems.insert({ 102, ¸ô¿Õ°Ë });
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