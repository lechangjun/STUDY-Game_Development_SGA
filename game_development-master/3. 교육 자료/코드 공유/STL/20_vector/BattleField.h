#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Dungeon.h"
#include "Item.h"


class BattleField
{
public:
	BattleField();
	~BattleField();

	void GameStart();

	void EnterDungeon();
	void Store2();
	void Field();
	void Hospital();

private:
	vector<Item*> testlist;
	Character* player;
	Enemy enemy;


	int select;

};