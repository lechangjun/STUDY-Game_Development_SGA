#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	hp = 100;
	attack = 10;
	deffense = 10;
	name = "Monster";
}

Enemy::~Enemy()
{

}

void Enemy::Damage(int val)
{
	hp -= val;
	cout << val << "�� �������� �Ծ���" << endl;
}

void Enemy::Phase1()
{
	attack *= 2;
	hp *= 2;
}
