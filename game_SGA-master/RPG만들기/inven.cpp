#include "stdafx.h"
#include "inven.h"
#include "item.h"

Inven::Inven()
{
	//for (int i = 0; i < 5; i++)
	//{
	//	name[i] = "없음";
	//}
	
	name = "없음";
	name1 = "없음";
	name2 = "없음";
	name3 = "없음";
	name4 = "없음";
	invenCount = 1;
	
	for (int i = 0; i < 4; i++)
	{
		attack[i] = 1;
		amor[i] = 2;
		equipType[i] = 0;
	}
	
	
}

Inven::~Inven()
{
}

void Inven::equip(int val, string equipName, int Attack,int Amor,int EquipType)
{

	if (val == 1)
	{
		name1 = equipName;
		attack[0] = Attack;
		amor[0] = Amor;
		equipType[0] = EquipType;
	}
	else if (val == 2)
	{
		name2 = equipName;
		attack[1] = Attack;
		amor[1] = Amor;
		equipType[1] = EquipType;
	}
	else if (val == 3)
	{
		name3 = equipName;
		attack[2] = Attack;
		amor[2] = Amor;
		equipType[2] = EquipType;
	}
	else
	{
		name4 = equipName;
		attack[3] = Attack;
		amor[3] = Amor;
		equipType[3] = EquipType;
	}
}
//void Inven::equip(int val, string equipName)
//{
//	for (int i = 1; i < 5; i++)
//	{
//		if (val == i)
//		{
//			name[i] = equipName;
//		}
//	}
//}


void Inven::InvenCount()
{
		invenCount += 1;
}



void Inven::InvenName1(string str)
{
	name1 = str;
}
void Inven::InvenName2(string str)
{
	name2 = str;
}

void Inven::InvenName3(string str)
{
	name3 = str;
}

void Inven::InvenName4(string str)
{
	name4 = str;
}


void Inven::InvenAttack1(int val)
{
	attack[0] = val;
}

void Inven::InvenAttack2(int val)
{
	attack[1] = val;
}
void Inven::InvenAttack3(int val)
{
	attack[2] = val;
}
void Inven::InvenAttack4(int val)
{
	attack[3] = val;
}

void Inven::InvenAmor1(int val)
{
	amor[0] = val;
}
void Inven::InvenAmor2(int val)
{
	amor[1] = val;
}
void Inven::InvenAmor3(int val)
{
	amor[2] = val;
}
void Inven::InvenAmor4(int val)
{
	amor[3] = val;
}

void Inven::InvenEquipType1(int val)
{
	equipType[0] = val;
}

void Inven::InvenEquipType2(int val)
{
	equipType[1] = val;
}

void Inven::InvenEquipType3(int val)
{
	equipType[2] = val;
}

void Inven::InvenEquipType4(int val)
{
	equipType[3] = val;
}

void Inven::InvenEmty()
{
	if (equipType[0] == 0)
	{
		invenCount = 1;
	}
	else if (equipType[1] == 0)
	{
		invenCount = 2;
	}
	else if (equipType[2] == 0)
	{
		invenCount = 3;
	}
	else if (equipType[3] == 0)
	{
		invenCount = 4;
	}
}



