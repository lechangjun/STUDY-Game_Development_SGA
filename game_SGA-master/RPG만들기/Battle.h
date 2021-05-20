#pragma once
#include"player.h"
#include"enemy.h"
#include"store.h"
#include"inven.h"

class Battle
{
public:
	Battle();
	~Battle();

	void GameStart();

	void MainUi();
	void Field();
	void Store();
	void StoreUi();
	void Hospital();
	void lotto();
	void Battle1();
	void EnemyTurn();
	void InvenUi();
	void Inven();
	void StoreCase();
	void InvenFull();


private:
	class Enemy enemy;
	class Player player;
	class Store store;
	class Inven inven;

	
	string PlayerName;
	int select;

};