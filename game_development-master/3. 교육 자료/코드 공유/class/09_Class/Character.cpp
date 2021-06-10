#include "stdafx.h"
#include "Character.h"


Character::Character()
	:hp(100),attack(10),def(50),name("SGA"),temp(10)
	, temp2(def)
{
	hp = 100;
	attack = 10;
	def = 50;
	name = "SGA";

	cout << "Default Constructor Called" << endl;
}

Character::Character(int hp, int attack, int def, string name)
	: hp(hp), attack(attack), def(def), name(name)
{
	this->hp = hp;
	this->attack = attack;
	this->def = def;
	this->name = name;

	//(*this).hp = hp;
	

	cout << "Custom Ctor Called" << endl;
}

Character::~Character()
{
	cout << "Destructor Called" << endl;
}
