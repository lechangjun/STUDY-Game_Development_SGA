#pragma once

#include "Item.h"

class Inven
{
public:
	Inven();
	~Inven();

	void ShowItemList();

	vector<Item*>& GetItem() { return Itemlist; }

	void Push(int index);


private:

	vector<Item*> Itemlist;


};