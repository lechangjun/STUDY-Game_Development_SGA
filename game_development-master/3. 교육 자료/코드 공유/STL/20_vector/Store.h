#pragma once
#include "Item.h"
#include "Character.h"

class Store
{
public:
	Store(class Character& player);
	~Store();

	void ShowItemList();
	void Buy(int index);



private:

	//class Character& player;

	vector<Item*> itemList;

	//vector<Item> itemlist2;

	//string temp;


	//Item weapon[10];

};