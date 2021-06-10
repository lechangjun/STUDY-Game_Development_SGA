#pragma once

#include "Item.h"

class Inven
{
public:
	Inven();
	~Inven();

	void ShowItemList();

	vector<class Item*> GetInven() { return Itemlist; }


private:

	vector<class Item*> Itemlist;


};