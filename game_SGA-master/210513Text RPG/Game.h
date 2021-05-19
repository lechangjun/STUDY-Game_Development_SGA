#pragma once
#include "stdafx.h"
#include "Character.h"
#include "Enemy.h"

class Game : public Character
{
protected:


public:
	Game();
	~Game();

	string P_Name = "1";
	int select = 0;

	virtual void GameStart();

};
