#include "stdafx.h"
#include "Dungeon.h"
#include "Character.h"

Dungeon::Dungeon(Character& player)
	:player(player)
{

}

Dungeon::~Dungeon()
{
}

void Dungeon::PrintPlayerStat()
{
	cout << player.GetName() << endl;
	cout << player.GetAttack() << endl;
	cout << player.GetHp() << endl;


}
