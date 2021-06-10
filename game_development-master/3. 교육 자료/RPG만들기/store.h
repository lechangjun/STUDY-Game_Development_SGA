#pragma once

class Store
{
public:
	Store();
	~Store();

	void Equip1();
	void Equip2();
	void Equip3();
	void Equip4();
	void Equip5();
	void Equip6();
	void HpPotion();
	void MpPotion();
	
	
	int GetMoney() { return money; }
	string GetName() { return name; }
	int GetEquipType() { return equipType; }
	int GetAttack() { return attack; }
	int GetAmor() { return amor; }

private:
	string name;
	int money;
	int equipType;
	int attack;
	int amor;

};