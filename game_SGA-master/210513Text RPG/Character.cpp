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

	cout << "�÷��̾� " << Name << "��(��) " << val << "��ŭ�� �������� �Ծ���." << endl;
	Hp -= val;
}
//================================================
void Character::NickName(string P_Name)
{
	cout << "�̸��� ���Ͻÿ�. : ";
	cin >> P_Name;
	Name = P_Name;

	system("cls");
}

void Character::Choose_Job(int val)
{
	cout << "<1>:����Ʈ\t<2>:����\t<3>:������\t<4>:Ŭ����" << endl;
	cout << "������ �����Ͻÿ�. : ";
	cin >> val;


	if (val == 1)
	{
		cout << "����Ʈ�� �����ϼ̽��ϴ�." << endl;
		Character* This;
		This = new Knight();
		This->Profile();
		Sleep(1000);
	}
	else if (val == 2)
	{
		cout << "���縦 �����ϼ̽��ϴ�." << endl;
		Character* This;
		This = new Warrior();
		This->Profile();
		Sleep(1000);

	}
	else if (val == 3)
	{
		cout << "�����縦 �����ϼ̽��ϴ�." << endl;
		Character* This;
		This = new Magician();
		This->Profile();
		Sleep(1000);
	}
	else if (val == 4)
	{
		cout << "Ŭ������ �����ϼ̽��ϴ�." << endl;
		Character* This;
		This = new Cleric();
		This->Profile();
		Sleep(1000);
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ֽʽÿ�." << endl;
		Sleep(1000);

	}
	
	system("cls");
}

void Character::Profile()
{
	cout << "=============================" << endl;
	cout << "�̸�: " << Name << endl;
	cout << "����: " << Job << endl;
	cout << "ü��: " << Max_Hp << "/" << Hp << endl;
	cout << "���� ���ݷ�: " << P_Att << endl;
	cout << "���� ���ݷ�: " << M_Att << endl;
	cout << "����: " << Def << endl;
	cout << "ġ��Ÿ: " << Critical << endl;
	cout << "ȸ��: " << Evasion << endl;
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
	//cout<<Name<<"�� ����"<<endl;
	//cout<<"���� �ݾ�: "<<Gold<<endl;
}