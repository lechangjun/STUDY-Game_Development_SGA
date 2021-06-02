#include "stdafx.h"
#include "Store.h"
#include "Item.h"
#include "WeaponType.h"

Store::Store(Character& player)
{

	//temp = "str";

	//temp.erase();

	//itemList.size();


	//itemList.push_back(new WeaponType());


	itemList.push_back(new Item(20, 20000));
	itemList.push_back(new Item(30, 30000));
	itemList.push_back(new Item(40, 40000));
	itemList.push_back(new Item(50, 50000));
	itemList.push_back(new Item(60, 60000));
	itemList.push_back(new Item(70, 70000));

	ShowItemList();

	int temp = 0;

	cin >> temp;
	
	player.GetInven()->GetItem().push_back(itemList[temp]);

	int b = 10;

	player.GetInven()->ShowItemList();

	int a = 10;

	/*switch (temp)
	{
		case 0:
			Buy(temp);
			break;
		case 1:
			Buy(temp);
			break;
		case 2:
			Buy(temp);
			break;
		default:
			break;
	}

*/


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
	//player.GetInven().GetItem().push_back(itemList[index]);

	int a = 10;

	//itemList[1]->GetAttack();

}
