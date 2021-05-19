#include "stdafx.h"
#include "Character.h"

Character::Character()
{
	Name = "0";
	Job = "0";
	Max_Hp = 0;
	Hp = 0;
	P_Att = 0;
	M_Att = 0;
	Def = 0;
	Critical = 0;
	Evasion = 0;
}

Character::~Character()
{
}
//================================================
void Character::Damage(int val)
{
	if (val <= 0)
	{
		val = 1;
	}

	cout << "플레이어 " << Name << "은(는) " << val << "만큼의 데미지를 입었다." << endl;
	Hp -= val;
}
//================================================
void Character::NickName(string P_Name)
{
	cout << "이름을 정하시오. : ";
	cin >> P_Name;
	Name = P_Name;

	system("cls");
}

void Character::Choose_Job(int val)
{
	cout << "<1>:나이트\t<2>:전사\t<3>:마법사\t<4>:클레릭" << endl;
	cout << "직업을 선택하시오. : ";
	cin >> val;


	if (val == 1)
	{
		cout << "나이트를 선택하셨습니다." << endl;
		Character* This;
		This = new Knight();
		This->Profile();
		Sleep(1000);
	}
	else if (val == 2)
	{
		cout << "전사를 선택하셨습니다." << endl;
		Character* This;
		This = new Warrior();
		This->Profile();
		Sleep(1000);

	}
	else if (val == 3)
	{
		cout << "마법사를 선택하셨습니다." << endl;
		Character* This;
		This = new Magician();
		This->Profile();
		Sleep(1000);
	}
	else if (val == 4)
	{
		cout << "클레릭을 선택하셨습니다." << endl;
		Character* This;
		This = new Cleric();
		This->Profile();
		Sleep(1000);
	}
	else
	{
		cout << "잘못된 입력입니다. 다시 입력해주십시오." << endl;
		Sleep(1000);

	}
	
	system("cls");
}

void Character::Profile()
{
	cout << "=============================" << endl;
	cout << "이름: " << Name << endl;
	cout << "직업: " << Job << endl;
	cout << "체력: " << Max_Hp << "/" << Hp << endl;
	cout << "물리 공격력: " << P_Att << endl;
	cout << "마법 공격력: " << M_Att << endl;
	cout << "방어력: " << Def << endl;
	cout << "치명타: " << Critical << endl;
	cout << "회피: " << Evasion << endl;
	cout << "=============================" << endl;
}
//================================================
void Character::Inventory()
{
	Gold = 10000;

	int Item_Count1 = 0;
	int Item_Count2 = 0;
	int Item_Count3 = 0;

	//cout<<"============================="<<endl;
	//cout<<Name<<"의 가방"<<endl;
	//cout<<"보유 금액: "<<Gold<<endl;
}