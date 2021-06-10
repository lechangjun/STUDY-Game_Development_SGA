#pragma once
#include "Character.h"

class Dungeon
{
public:
	Dungeon(class Character& player);
	~Dungeon();

public:
	void PrintPlayerStat();

private:
	Character& player;
};