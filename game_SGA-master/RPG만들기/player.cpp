#include "stdafx.h"
#include "player.h"


Player::Player()
{
	exe1 = 0;
	exe2 = 100;
	level = 1;
	hp = 100;
	maxhp = 100;
	attack = 40;
	def = 3;
	name = "지정이름";
	item1 = "없음";
	item2 = "없음";
	money = 5000;
	skill = 0;
	mp = 80;
	maxmp = 80;
	
	playerItem = 0;
	itemName = "없음";
	hpPotion = 0;
	mpPotion = 0;

	inven1 = "없음";
	inven2 = "없음";
	inven3 = "없음";
	inven4 = "없음";
	
	item1Attack = 0;
	item1Amor = 0;

	item2Attack = 0;
	item2Amor = 0;
	
	item1EquipType = 0;
	item2EquipType = 0;

}

Player::~Player()
{
}

void Player::Name(string PlayerName)
{	
	cout << "이름을 정하시오. : ";
	cin >> PlayerName;
	name = PlayerName;
	system("cls");
}



void Player::Damage(int val)
{
	hp -= val;
	cout << name << "은 " << val << "의 데미지를 입었다." << endl;
	Sleep(800);
}

void Player::Skill1()
{
	skill = attack * 2;
	mp -= 30;
}

void Player::Skill2()
{
	skill = attack * 3;
	mp -= 50;
}

void Player::GetPM(int pm,int em)
{
	money = pm + em;
}

void Player::GetPE(int pe, int ee)
{
	exe1 = pe + ee;
}

void Player::LevelUp()
{
	level += 1;
	maxhp += 150;
	hp = maxhp;
	maxmp += 100;
	mp = maxmp;
	exe2 += 200;
	attack += 5;
	def += 2;
}

void Player::DeathM()
{
	money = 0;
}

void Player::DeathE()
{
	exe1 = 0;
}

void Player::GetPi1(string str)
{
	item1 = str;
}

void Player::GetPi2(string str)
{
	item2 = str;
}

void Player::GetPi1Attack(int val)
{
	item1Attack = val;
}

void Player::GetPi2Attack(int val)
{
	item2Attack = val;
}

void Player::GetPi1Amor(int val)
{
	item1Amor = val;
}

void Player::GetPi2Amor(int val)
{
	item2Amor = val;
}

void Player::GetEquipType1(int val)
{
	item1EquipType = val;
}

void Player::GetEquipType2(int val)
{
	item2EquipType = val;
}

void Player::UseHp()
{
	hpPotion -= 1;
	hp += 100;
}

void Player::UseMp()
{
	mpPotion -= 1;
	mp += 80;
}

void Player::HpMpFull()
{
	hp = maxhp;
	mp = maxmp;
}


void Player::Attack(int val)
{
	attack += val;
}

void Player::Amor(int val)
{
	def += val;
}
