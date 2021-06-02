#pragma once

class Item
{
public:
	Item();
	Item(int attack, int price);
	~Item();

	void ItemInfo();

	int GetAttack() { return attack; }

private:
	int attack;
	int price;

};