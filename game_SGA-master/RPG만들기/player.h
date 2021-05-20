#pragma once



class Player
{
public:
	Player();
	~Player();

	void Name(string nickname);
	
	void Damage(int val);
	void Skill1();
	void Skill2();
	void Attack(int val);
	void Amor(int val);
	void GetPM(int pm,int em);
	void GetPE(int pe, int ee);
	void LevelUp();
	void DeathM();
	void DeathE();
	void GetPi1(string str);
	void GetPi2(string str);
	void GetPi1Attack(int val);
	void GetPi2Attack(int val);
	void GetPi1Amor(int val);
	void GetPi2Amor(int val);
	void GetEquipType1(int val);
	void GetEquipType2(int val);
	void UseHp();
	void UseMp();
	void HpMpFull();
	

	int GetExe1() { return exe1; }
	int GetExe2() { return exe2; }
	int GetLevel() { return level; }
	int GetHP() { return hp; }
	int GetHP1() { return maxhp; }
	int GetAttack() { return attack; }
	int GetDeffense() { return def; }
	string GetName() { return name; }
	string GetItem1() { return item1; }
	string GetItem2() { return item2; }
	int GetMoney() { return money; }
	int GetSkill() { return skill; }
	int GetMana1() { return mp; }
	int GetMana2() { return maxmp; }
	int GetPlayerItem() { return playerItem; }
	string ItemName() { return itemName; }
	int GetHpPotion() { return hpPotion; }
	int GetMpPotion() { return mpPotion; }
	string GetInven1() { return inven1; }
	string GetInven2() { return inven2; }
	string GetInven3() { return inven3; }
	string GetInven4() { return inven4; }
	int GetItem1Attack() { return item1Attack; }
	int GetItem2Attack() { return item2Attack; }
	int GetItem1Amor() { return item1Amor; }
	int GetItem2Amor() { return item2Amor; }
	int GetItem1EquipType() { return item1EquipType; }
	int GetItem2EquipType() { return item2EquipType; }

private:
	int exe1;
	int exe2;
	int level;
	int hp;
	int maxhp;
	int attack;
	int def;
	string name;
	string item1;
	string item2;
	int money;
	int skill;
	int mp;
	int maxmp;
	int playerItem;
	string itemName;
	int hpPotion;
	int mpPotion;
	string inven1;
	string inven2;
	string inven3;
	string inven4;
	int item1Attack;
	int item2Attack;
	int item1Amor;
	int item2Amor;
	int item1EquipType;
	int item2EquipType;
};

