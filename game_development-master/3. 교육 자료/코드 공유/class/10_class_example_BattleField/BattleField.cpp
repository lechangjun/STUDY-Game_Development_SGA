#include "stdafx.h"
#include "BattleField.h"
#include "Character.h"
#include "Enemy.h"


BattleField::BattleField()
{
	GameStart();
}

BattleField::~BattleField()
{

}

void BattleField::GameStart()
{
	cout << "������" << endl;

	cout << "1.����" << endl;
	cout << "2.�ʵ�" << endl;
	cout << "3.����" << endl;

	cin >> select;

	switch (select)
	{
		case 1 :
			Store();
			break;
		case 2:
			Field();
			break;
		case 3:
			Hospital();
			break;

		default:
			break;
	}

}

void BattleField::Store()
{
	cout << "����";
}

void BattleField::Field()
{
	cout << "�ʵ�";
}

void BattleField::Hospital()
{
	cout << "����";
}
