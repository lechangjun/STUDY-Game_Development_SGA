#include "stdafx.h"
#include "enemy.h"


Enemy::Enemy()
{
	hp = 0;
	hpmax = 0;
	attack = 0;
	def = 0;
	name = "이름";
	exe = 0;
	money = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Slime()
{
	hp = 50;
	hpmax = 50;
	attack = 6;
	def = 3;
	name = "슬라임";
	exe = 30;
	money = 50;
}

void Enemy::Goblin()
{
	hp = 120;
	hpmax = 120;
	attack = 12;
	def = 6;
	name = "고블린";
	exe = 50;
	money = 80;
}

void Enemy::Orc()
{
	hp = 220;
	hpmax = 220;
	attack = 17;
	def = 9;
	name = "오크";
	exe = 90;
	money = 130;
}

void Enemy::Vampire()
{
	hp = 400;
	hpmax = 400;
	attack = 500;
	def = 15;
	name = "뱀파이어";

}

void Enemy::Damage(int val)
{
	hp -= val;
	cout << name <<"은 " << val << "의 데미지를 입었다."<<endl;

}

void Enemy::Ui()
{
	cout << "\t\t\t********상태창********" << endl << endl;
	cout << "\t\t\t이름 : " << name << endl;
	cout << "\t\t\t체력 : " << hp <<"/"<< hpmax << endl;
	cout << "\t\t\t공격력 : " << attack << endl;
	cout << "\t\t\t방어력 : " << def << endl;
	cout << "\t\t\t*********************" << endl << endl;
	
}

void Enemy::HpFull()
{
	hp = hpmax;
}




