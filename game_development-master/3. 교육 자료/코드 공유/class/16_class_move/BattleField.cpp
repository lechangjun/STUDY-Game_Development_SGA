#include "stdafx.h"
#include "BattleField.h"
#include "Character.h"
#include "Enemy.h"


BattleField::BattleField()
{
	GameStart();

	
	///player.


	
}

BattleField::~BattleField()
{

}

void BattleField::GameStart()
{
	//player
	
	cout << "������" << endl;

	cout << "1.����" << endl;
	cout << "2.�ʵ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;

	cin >> select;

	switch (select)
	{
		case 1 :
			Store();
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
	
	player.AddHp(temp);

	Dungeon dungeon(player);

	dungeon.PrintPlayerStat();
	
	int a = 10;
}

void BattleField::Store()
{
	cout << "����";
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
