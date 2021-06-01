#include "stdafx.h"
#include "Store.h"
#include "Item.h"
#include "WeaponType.h"

Store::Store(Character& player)
	:player(player)
{
	itemList.push_back(new WeaponType());
	itemList.push_back(new Item(20, 20000));
	itemList.push_back(new Item(30, 30000));
	itemList.push_back(new Item(40, 40000));
	itemList.push_back(new Item(50, 50000));
	itemList.push_back(new Item(60, 60000));
	itemList.push_back(new Item(70, 70000));

	ShowItemList();

}

Store::~Store()
{
}

void Store::ShowItemList()
{
	for (auto& item : itemList)
	{
		item->ItemInfo();
	}

}

void Store::Buy(int index)
{

	player.GetInven().GetInven().push_back(itemList[index]);

}
