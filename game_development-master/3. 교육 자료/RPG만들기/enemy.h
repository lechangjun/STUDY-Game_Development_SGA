#pragma once


class Enemy
{
public:
	Enemy();
	~Enemy();

	void Damage(int val);
	void Ui();
	void HpFull();
	void Slime();
	void Goblin();
	void Orc();
	void Vampire();


	int GetHP() { return hp; }
	int GetAttack() { return attack; }
	int GetDeffense() { return def; }
	string GetName() { return name; }
	int GetMoney() { return money; }
	int GetExe() { return exe; }

private:
	int hp;
	int hpmax;
	int attack;
	int def;
	int select;
	int exe;
	int money;
	string name;

	
};