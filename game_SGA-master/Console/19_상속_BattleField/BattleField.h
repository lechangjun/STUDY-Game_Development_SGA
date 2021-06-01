#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Dungeon.h"


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
	Character player;
	Enemy enemy;


	int select;

};