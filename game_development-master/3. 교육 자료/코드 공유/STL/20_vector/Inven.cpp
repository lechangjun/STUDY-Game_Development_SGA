#include "stdafx.h"
#include "Inven.h"

Inven::Inven()
{
	cout << "inven Constructor" << endl;

	Itemlist.push_back(new Item(100, 10000));
	Itemlist.push_back(new Item(200, 20000));
	Itemlist.push_back(new Item(300, 30000));
	Itemlist.push_back(new Item(400, 40000));
	Itemlist.push_back(new Item(500, 50000));
	Itemlist.push_back(new Item(600, 60000));
	Itemlist.push_back(new Item(700, 70000));

}

Inven::~Inven()
{
	cout << "inven Destructor" << endl;

}

void Inven::ShowItemList()
{
	for (int i = 0; i < Itemlist.size(); i++)
	{
		Itemlist[i]->ItemInfo();
	}

}

void Inven::Push(int index)
{
	
	Itemlist.push_back(new Item(800, 80000));

}
