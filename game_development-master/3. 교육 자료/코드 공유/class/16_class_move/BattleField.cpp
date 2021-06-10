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
	
	cout << "선택해" << endl;

	cout << "1.상점" << endl;
	cout << "2.필드" << endl;
	cout << "3.병원" << endl;
	cout << "4.던전" << endl;

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
	cout << "상점";
}

void BattleField::Field()
{
	cout << "필드";

	EnterDungeon();

	//enemy.Damage(player.GetAttack());
}

void BattleField::Hospital()
{
	cout << "병원";
}
