#include "stdafx.h"
#include "store.h"

Store::Store()
{
	name = "ÃÊ±â°ª";
	money = 0;
	equipType = 0;
	attack = 0;
	amor = 0;
}

Store::~Store()
{

}


void Store::Equip1()
{
	name = "³ª¹« °Ë";
	money = 5;
	equipType = 1;
	attack = 10;
	amor = 0;
}

void Store::Equip2()
{
	name = "°­Ã¶ °Ë";
	money = 50;	
	equipType = 1;
	attack = 20;
	amor = 0;
}

void Store::Equip3()
{
	name = "´ÙÀÌ¾Æ °Ë";
	money = 200;
	equipType = 1;
	attack = 30;
	amor = 0;
}

void Store::Equip4()
{
	name = "³ª¹« °©¿Ê";
	money = 5;
	equipType = 2;
	amor = 10;
	attack = 0;
}

void Store::Equip5()
{
	name = "°­Ã¶ °©¿Ê";
	money = 50;
	equipType = 2;
	amor = 20;
	attack = 0;
}

void Store::Equip6()
{
	name = "´ÙÀÌ¾Æ °©¿Ê";
	money = 200;
	equipType = 2;
	amor = 30;
	attack = 0;
}

void Store::HpPotion()
{
	name = "HP¹°¾à";
	money = 40;
	equipType = 3;
}

void Store::MpPotion()
{
	name = "MP¹°¾à";
	money = 30;
	equipType = 4;
}

