#include "stdafx.h"
#include "BattleField.h"
#include "Character.h"
#include "Enemy.h"
#include "Store.h"


BattleField::BattleField()
{
	

	player = new Character();
	
	player->GetInven()->ShowItemList();

	player->GetInven()->Push(1);
	//player->GetInven()->GetItem().push_back(new Item(800, 80000));

	player->GetInven()->ShowItemList();


	int a = 10;

	GameStart();

	
	///player.

	


}

BattleField::~BattleField()
{

}

void BattleField::GameStart()
{
	//player
	
	testlist.push_back(new Item(100, 10000));
	testlist.push_back(new Item(200, 20000));
	testlist.push_back(new Item(300, 30000));
	testlist.push_back(new Item(400, 40000));
	testlist.push_back(new Item(500, 50000));
	testlist.push_back(new Item(600, 60000));

	


	player->GetInven()->GetItem().push_back(testlist[0]);

	player->GetInven()->ShowItemList();


	int test = 10;

	cout << "������" << endl;

	cout << "1.����" << endl;
	cout << "2.�ʵ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;

	cin >> select;

	switch (select)
	{
		case 1 :
			Store2();
			break;
		case 2:
			Field();
			break;
		case 3:
			Hospital();
			break;
		case 4:
			EnterDungeon();
			break;
		default:
			break;
	}

}

void BattleField::EnterDungeon()
{
	int temp = rand() % 11 + 10;
	
	player->AddHp(temp);

	Dungeon dungeon(*player);

	dungeon.PrintPlayerStat();
	
	int a = 10;
}

void BattleField::Store2()
{
	cout << "����";

	Store store(*player);

	int a = 0;

	player->GetInven()->ShowItemList();



}

void BattleField::Field()
{
	cout << "�ʵ�";

	EnterDungeon();

	//enemy.Damage(player.GetAttack());
}

void BattleField::Hospital()
{
	cout << "����";
}
