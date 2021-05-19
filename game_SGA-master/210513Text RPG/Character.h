#pragma once
#include "stdafx.h"

class Character
{
protected:
	string Name;
	string Job;
	int Max_Hp;
	int Hp;
	int P_Att;
	int M_Att;
	int Def;
	int Critical;
	int Evasion;

	int Gold = 10000;

	int Item_Count1 = 0;
	int Item_Count2 = 0;
	int Item_Count3 = 0;
public:
	Character();
	virtual ~Character();

	virtual void Damage(int val);
	//virtual void Plus_Gold(int val);
	//virtual void Buy_Item_Gold(int val);
	//virtual void Sell_Item_Gold(int val);

	virtual void NickName(string P_Name);
	virtual void Choose_Job(int val);
	virtual void Profile();
	virtual void Inventory();
};
//=====================================
class Knight : virtual public Character
{

public:
	//Hp Def
	virtual void Profile() override 
	{
		Job = "Knight";
		Max_Hp = 120;
		Hp = 120;
		P_Att = 20;
		M_Att = 10;
		Def = 30;
		Critical = 20;
		Evasion = 20;
	};
};

class Warrior : virtual public Character
{
public:
	//P_Att Cri 
	virtual void Profile() override 
	{
		Job = "Warrior";
		Max_Hp = 100;
		Hp = 100;
		P_Att = 30;
		M_Att = 10;
		Def = 20;
		Critical = 30;
		Evasion = 20;
	};
};

class Magician : virtual public Character
{
public:
	//M_Att Cri
	virtual void Profile() override 
	{
		Job = "Magician";
		Max_Hp = 100;
		Hp = 100;
		P_Att = 10;
		M_Att = 30;
		Def = 20;
		Critical = 30;
		Evasion = 20;
	};
};

class Cleric : virtual public Character
{
public:
	//Cri Eva
	virtual void Profile() override 
	{
		Job = "Cleric";
		Max_Hp = 100;
		Hp = 100;
		P_Att = 20;
		M_Att = 20;
		Def = 20;
		Critical = 30;
		Evasion = 30;
	};
};
//======================================
class Inventory : virtual public Character
{
public:

};