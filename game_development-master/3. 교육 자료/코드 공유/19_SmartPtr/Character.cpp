#include "stdafx.h"
#include "Character.h"

int Character::global;

Character::Character()
	:hp(100),attack(10),def(50),name("SGA"), size(5)
{

	//slot = new Super;

	//hp = 100;
	//attack = 10;
	//def = 50;
	//name = "SGA";
	

	ptrInt = new int[size];


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

Character::Character(const Character & src)
{
	hp = src.hp;
	attack = src.attack;
	def = src.def;
	name = src.name;
	
	size = src.size;
	ptrInt = new int[size];

	for (int i = 0; i < size; i++)
		ptrInt[i] = src.ptrInt[i];

}

Character::Character(Character && src) noexcept
{
	hp = src.hp;
	attack = src.attack;
	def = src.def;
	name = src.name;
	size = src.size;
	ptrInt = src.ptrInt;

	src.name = "";
	src.hp = 0;
	src.attack = 0;
	src.def = 0;
	src.size = 0;
	src.ptrInt = nullptr;
}

Character & Character::operator=(Character && rhs) noexcept
{
	if (this == &rhs)
	{
		return *this;
	}

	delete[] ptrInt;
	ptrInt = nullptr;

	hp = rhs.hp;
	attack = rhs.attack;
	def = rhs.def;
	name = rhs.name;
	size = rhs.size;
	ptrInt = rhs.ptrInt;

	rhs.name = "";
	rhs.hp = 0;
	rhs.attack = 0;
	rhs.def = 0;
	rhs.size = 0;
	rhs.ptrInt = nullptr;

	return *this;

}

Character& Character::operator=(const Character& rhs)
{

	if (this == &rhs)
	{
		return *this;
	}

	delete[] ptrInt;
	ptrInt = nullptr;


	hp = rhs.hp;
	attack = rhs.attack;
	def = rhs.def;
	name = rhs.name;

	size = rhs.size;
	ptrInt = new int[size];

	for (int i = 0; i < size; i++)
		ptrInt[i] = rhs.ptrInt[i];

	return *this;

}

Character& Character::operator+(const string & rhs)
{
	name += rhs;

	return *this;
}

Character::~Character()
{
	delete ptrInt;

	cout << "Destructor Called" << endl;
}

void Character::Func()
{

}
