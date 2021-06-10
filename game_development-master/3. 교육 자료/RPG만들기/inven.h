#pragma once

class Inven
{
public:
	Inven();
	~Inven();


	void equip(int val, string equipName, int Attack,int Amor,int EquipType);
	void InvenCount();
	void InvenName1(string str);
	void InvenName2(string str);
	void InvenName3(string str);
	void InvenName4(string str);
	void InvenAttack1(int val);
	void InvenAttack2(int val);
	void InvenAttack3(int val);
	void InvenAttack4(int val);
	void InvenAmor1(int val);
	void InvenAmor2(int val);
	void InvenAmor3(int val);
	void InvenAmor4(int val);
	void InvenEquipType1(int val);
	void InvenEquipType2(int val);
	void InvenEquipType3(int val);
	void InvenEquipType4(int val);
	void InvenEmty();

	string GetName1() { return name1; }
	string GetName2() { return name2; }
	string GetName3() { return name3; }
	string GetName4() { return name4; }
	int GetEquipType1() { return equipType[0]; }
	int GetEquipType2() { return equipType[1]; }
	int GetEquipType3() { return equipType[2]; }
	int GetEquipType4() { return equipType[3]; }
	int GetAttack1() { return attack[0]; }
	int GetAttack2() { return attack[1]; }
	int GetAttack3() { return attack[2]; }
	int GetAttack4() { return attack[3]; }
	int GetAmor1() { return amor[0]; }
	int GetAmor2() { return amor[1]; }
	int GetAmor3() { return amor[2]; }
	int GetAmor4() { return amor[3]; }
	int GetInvenCount() { return invenCount; }
	


private:
	string name;
	string name1;
	string name2;
	string name3;
	string name4;
	//string name[4];
	int equipType[4];
	int attack[4];
	int amor[4];
	int invenCount;
	

	
};
