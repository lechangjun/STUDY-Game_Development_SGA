#pragma once


class Character
{

public:
	Character();

	Character(int hp, int attack,int def, string name);

	~Character();


private:
	int hp;
	int attack;
	int def;
	string name;

	const int temp;
	int& temp2;


};