#include "stdafx.h"
#include "enemy.h"


Enemy::Enemy()
{
	hp = 0;
	hpmax = 0;
	attack = 0;
	def = 0;
	name = "�̸�";
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
	name = "������";
	exe = 30;
	money = 50;
}

void Enemy::Goblin()
{
	hp = 120;
	hpmax = 120;
	attack = 12;
	def = 6;
	name = "���";
	exe = 50;
	money = 80;
}

void Enemy::Orc()
{
	hp = 220;
	hpmax = 220;
	attack = 17;
	def = 9;
	name = "��ũ";
	exe = 90;
	money = 130;
}

void Enemy::Vampire()
{
	hp = 400;
	hpmax = 400;
	attack = 500;
	def = 15;
	name = "�����̾�";

}

void Enemy::Damage(int val)
{
	hp -= val;
	cout << name <<"�� " << val << "�� �������� �Ծ���."<<endl;

}

void Enemy::Ui()
{
	cout << "\t\t\t********����â********" << endl << endl;
	cout << "\t\t\t�̸� : " << name << endl;
	cout << "\t\t\tü�� : " << hp <<"/"<< hpmax << endl;
	cout << "\t\t\t���ݷ� : " << attack << endl;
	cout << "\t\t\t���� : " << def << endl;
	cout << "\t\t\t*********************" << endl << endl;
	
}

void Enemy::HpFull()
{
	hp = hpmax;
}




