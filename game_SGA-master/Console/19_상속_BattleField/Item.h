#pragma once

class Item
{
public:
	Item();
	Item(int attack, int price);
	~Item();

	void ItemInfo();

private:
	int attack;
	int price;

};