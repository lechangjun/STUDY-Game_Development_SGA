#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	attack = 0;
	price = 0;
}

Item::Item(int attack, int price)
	:attack(attack), price(price)
{

}

Item::~Item()
{
}

void Item::ItemInfo()
{
	cout << attack << endl;
	cout << price << endl;
}
