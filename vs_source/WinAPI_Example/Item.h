#pragma once



class ItemBase
{
public:
    ItemBase();
    ItemBase(int Index, std::wstring Name, int Price);
    ~ItemBase();

    virtual bool Buy() = 0;
    virtual bool Sell() = 0;

    virtual int GetSubCount();
    virtual bool hasSubItem(int idx);
    virtual void SetSubItems(std::vector<int> SubItems);
    virtual std::vector<int> GetSubItems();

    std::wstring GetItemInfo();

    int GetIndex() { return this->Index; }

    int Price;
    double sellRatio;
    std::wstring Name;
    Gdiplus::Image* Image;
    ItemGrade Grade;

protected:
    int Index;
    std::vector<int> SubItems;
};