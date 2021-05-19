#include "stdafx.h"
#include "Game.h"

	Character Player;
Game::Game()
{
	Player.NickName(P_Name);
	Player.Choose_Job(select);
	Player.Profile();
	//GameStart();
}

Game::~Game()
{
}
//=================================
void Game::GameStart()
{
}
