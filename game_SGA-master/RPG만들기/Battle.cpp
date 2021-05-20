#include "stdafx.h"
#include "Battle.h"

Battle::Battle()
{
	player.Name(PlayerName);
	GameStart();
	
}

Battle::~Battle()
{
}

void Battle::MainUi()
{

	cout << endl;
	cout << "********상태창********" << endl<<endl;
	cout << "이름 : " << player.GetName() << endl;
	cout << "Lv : " << player.GetLevel() << endl;
	cout << "체력 : " << player.GetHP()<<"/"<<player.GetHP1() << endl;
	cout << "마나 : " << player.GetMana1() << "/" << player.GetMana2() << endl;
	cout << "공격력 : " << player.GetAttack() << endl;
	cout << "방어력 : " << player.GetDeffense() << endl;
	cout << "장비1 : " << player.GetItem1() << endl;
	cout << "장비2 : " << player.GetItem2() << endl;
	cout << "소지금 : " << player.GetMoney() << endl;
	cout << "경험치 : " << player.GetExe1() << "/" << player.GetExe2() << endl << endl;
	cout << "*********************" << endl << endl;
	
}


void Battle::GameStart()
{
	system("cls");
	MainUi();
	
	cout << "1.사냥터 2.상점 3.병원 4.도박장 5.가방 " << endl;
	cout << "무엇을 하시겠습니까 ?  :";
	cin >> select;

	switch (select)
	{
	case 1:
		Field();
		break;
	case 2:
		Store();
		break;
	case 3:
		Hospital();
		break;
	case 4:
		lotto();
		break;
	case 5:
		Inven();
		break;
	default:
		cout << "잘못 선택했습니다.." << endl;
		Sleep(500);
		system("cls");
		GameStart();
		break;
	}
	system("cls");
}


void Battle::Battle1()
{
	cout << "무엇을 하시겠습니까? " << endl;
	cout << "1.공격  2.스킬  3.가방  4.도망 : ";
	cin >> select;
	srand(size_t(time(NULL)));

	switch (select)
	{
	case 1:
		cout << "기본 공격을 했습니다." << endl;
		Sleep(500);
		enemy.Damage(player.GetAttack() - enemy.GetDeffense()+(rand()%2-1));
		Sleep(800);
		EnemyTurn();
		break;
	case 2:
		cout << "무슨 스킬을 사용하시겠습니까? " << endl;
		cout << "1.더블 어택(MP - 30) 2.임팩트 슬래쉬(MP - 50) : ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (player.GetMana1() < 30)
			{
				cout << "마나가 부족합니다." << endl;
				Sleep(800);
			}
			else
			{
				player.Skill1();
				cout << "스킬을 사용했습니다." << endl;
				Sleep(500);
				enemy.Damage(player.GetSkill());
				Sleep(800);
				EnemyTurn();
			}
			break;
		case 2:
			if (player.GetMana1() < 50)
			{
				cout << "마나가 부족합니다." << endl;
				Sleep(800);
			}
			else
			{
				player.Skill2();
				cout << "스킬을 사용했습니다." << endl;
				Sleep(500);
				enemy.Damage(player.GetSkill());
				Sleep(800);
				EnemyTurn();
			}
			break;
		default:
			cout << "잘못 선택했습니다." << endl;
			Sleep(800);
			Battle1();
			break;
		}
		break;
	case 3:
		cout << "********************" << endl << endl;
		cout << "1. HP물약 : x" << player.GetHpPotion()<<endl;
		cout << "2. MP물약 : x" << player.GetMpPotion() << endl<<endl;
		cout << "********************" << endl;
		cout << "물약을 선택하세요. : ";
		cin >> select;
	
		switch (select)
		{
			case 1:
				cout << "HP물약을 사용했습니다." << endl;
				Sleep(800);
				player.UseHp();
				EnemyTurn();
				break;
			case 2:
				cout << "MP물약을 사용했습니다." << endl;
				Sleep(800);
				player.UseMp();
				EnemyTurn();
				break;
			default:
				cout << "잘못 선택했습니다." << endl;
				Sleep(800);
				Battle1();
				break;
		}
		break;
	case 4:
		cout << "도망 쳤습니다." << endl;
		Sleep(800);
		enemy.HpFull();
		Field();	
		break;
	case 5:

	default:
		cout << "잘못 선택했습니다." << endl;
		Sleep(800);
		Battle1();
		break;
	}

}

void Battle::Field()
{
	system("cls");
	MainUi();
	cout << "1. 슬라임(추천레벨1~3)" << endl;
	cout << "2. 고블린(추천레벨 4~6)" << endl;
	cout << "3. 오크(추천레벨 7~10)" << endl;
	cout << "4. 뱀파이어(보스, 추천레벨 11)" << endl;
	cout << "5. 처음으로 .. " << endl;
	cout << "고르시오. : ";
	cin >> select;

	switch (select)
	{
	case 1:
		enemy.Slime();
		break;
	case 2:
		enemy.Goblin();
		break;
	case 3:
		enemy.Orc();
		break;
	case 4:
		enemy.Vampire();
		break;
	case 5:
		GameStart();
		break;
	default:
		cout << "잘못 선택했습니다." << endl;
		Sleep(500);
		Field();
		break;
	}
	while (1)
	{
		system("cls");
		MainUi();
		enemy.Ui();
		Battle1();
	}
}

void Battle::EnemyTurn()
{
	if (enemy.GetHP() <= 0)
	{
		Sleep(500);
		cout << enemy.GetName() << "을 물리쳤습니다." << endl;
		Sleep(800);
		enemy.HpFull();
		player.GetPM(player.GetMoney(),enemy.GetMoney());
		player.GetPE(player.GetExe1(), enemy.GetExe());
		cout << "돈 " << enemy.GetMoney() << " 획득" << endl;
		cout << "경험치 " << enemy.GetExe() << " 획득" << endl;
		Sleep(1000);
		if (player.GetExe1() >= player.GetExe2())
		{
			cout << "축하드립니다 레벨업 하셨습니다." << endl;
			player.LevelUp();
			Sleep(800);
		}
		Field();
	}
	cout << "상대의 차례입니다..." << endl;
	Sleep(800);
	player.Damage(enemy.GetAttack()-player.GetDeffense()+(rand() % 2 - 1));
	if (player.GetHP() <= 0)
	{
		Sleep(500);
		cout << player.GetName() << "은 사망했습니다." << endl;
		Sleep(500);
		cout << "소지한 모든 돈과 경험치를 잃습니다." << endl;
		player.DeathE();
		player.DeathM();
		Sleep(800);
		player.HpMpFull();
		Field();
	}
}

void Battle::Store()
{
	system("cls");
	cout << "가진 돈 : " << player.GetMoney() << endl;
	StoreUi();
	inven.InvenEmty();
	cout << "무엇을 구매하시겠습니까 ? : ";
	cin >> select;
	

	switch (select)
	{
		case 1:
			InvenFull();
			store.Equip1();
			StoreCase();

		case 2:
			InvenFull();
			store.Equip2();
			StoreCase();
		case 3:
			InvenFull();
			store.Equip3();
			StoreCase();
		case 4:
			InvenFull();
			store.Equip4();
			StoreCase();
		case 5:
			InvenFull();
			store.Equip5();
			StoreCase();
		case 6:
			InvenFull();
			store.Equip6();
			StoreCase();
		case 7:
			InvenFull();
			store.HpPotion();
			StoreCase();
		case 8:
			InvenFull();
			store.MpPotion();
			StoreCase();
		case 9:
			GameStart();
		default:
			break;
	}
	
}

void Battle::Inven()
{

	system("cls");
	InvenUi();
	cout << "1.장비 착용  2.장비 판매  3.나가기 " << endl;
	cout << "무엇을 하시겠습니까? :";
	cin >> select;
	
	switch (select)
	{
	case 1:
		system("cls");
		InvenUi();
		cout << "착용할 장비를 선택해주세요. :";
		cin >> select;
		Sleep(500);
		switch (select)
		{
		case 1:		
			if (inven.GetEquipType1() == 1)
			{
				cout << inven.GetName1() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem1();
				temp2 = player.GetItem1Attack();
				temp3 = player.GetItem1Amor();
				temp4 = player.GetItem1EquipType();
				player.GetPi1(inven.GetName1());
				player.GetPi1Attack(inven.GetAttack1());
				player.Attack(inven.GetAttack1());
				player.GetPi1Amor(inven.GetAmor1());
				player.Amor(inven.GetAmor1());
				player.GetEquipType1(inven.GetEquipType1());
				inven.InvenName1(temp1);
				inven.InvenAttack1(temp2);
				inven.InvenAmor1(temp3);
				inven.InvenEquipType1(temp4);
			}
			else if(inven.GetEquipType1() == 2)
			{
				cout << inven.GetName1() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem2();
				temp2 = player.GetItem2Attack();
				temp3 = player.GetItem2Amor();
				temp4 = player.GetItem2EquipType();
				player.GetPi2(inven.GetName1());
				player.GetPi2Attack(inven.GetAttack1());
				player.Attack(inven.GetAttack1());
				player.GetPi2Amor(inven.GetAmor1());
				player.GetEquipType2(inven.GetEquipType1());
				player.Amor(inven.GetAmor1());
				inven.InvenName1(temp1);
				inven.InvenAttack1(temp2);
				inven.InvenAmor1(temp3);
				inven.InvenEquipType1(temp4);
			}
			else
			{
				cout << "아이템창이 비어있습니다." << endl;
				Sleep(800);
			}
			Sleep(800);
			Inven();
			break;
		case 2:
			if (inven.GetEquipType2() == 1)
			{
				cout << inven.GetName2() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem1();
				temp2 = player.GetItem1Attack();
				temp3 = player.GetItem1Amor();
				temp4 = player.GetItem1EquipType();
				player.GetPi1(inven.GetName2());
				player.GetPi1Attack(inven.GetAttack2());
				player.Attack(inven.GetAttack2());
				player.GetPi1Amor(inven.GetAmor2());
				player.GetEquipType1(inven.GetEquipType2());
				player.Amor(inven.GetAmor2());
				inven.InvenName2(temp1);
				inven.InvenAttack2(temp2);
				inven.InvenAmor2(temp3);
				inven.InvenEquipType2(temp4);
			}
			else if (inven.GetEquipType2() == 2)
			{
				cout << inven.GetName2() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem2();
				temp2 = player.GetItem2Attack();
				temp3 = player.GetItem2Amor();
				temp4 = player.GetItem2EquipType();
				player.GetPi2(inven.GetName2());
				player.GetPi2Attack(inven.GetAttack2());
				player.Attack(inven.GetAttack2());
				player.GetPi2Amor(inven.GetAmor2());
				player.GetEquipType2(inven.GetEquipType2());
				player.Amor(inven.GetAmor2());
				inven.InvenName2(temp1);
				inven.InvenAttack2(temp2);
				inven.InvenAmor2(temp3);
				inven.InvenEquipType2(temp4);
			}
			else
			{
				cout << "아이템창이 비어있습니다." << endl;
				Sleep(800);
			}
			Sleep(800);
			Inven();
			break;
		case 3:
			if (inven.GetEquipType3() == 1)
			{
				cout << inven.GetName3() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem1();
				temp2 = player.GetItem1Attack();
				temp3 = player.GetItem1Amor();
				temp4 = player.GetItem1EquipType();
				player.GetPi1(inven.GetName3());
				player.GetPi1Attack(inven.GetAttack3());
				player.Attack(inven.GetAttack3());
				player.GetPi1Amor(inven.GetAmor3());
				player.GetEquipType1(inven.GetEquipType3());
				player.Amor(inven.GetAmor3());
				inven.InvenName3(temp1);
				inven.InvenAttack3(temp2);
				inven.InvenAmor3(temp3);
				inven.InvenEquipType3(temp4);
			}
			else if (inven.GetEquipType3() == 2)
			{
				cout << inven.GetName3() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem2();
				temp2 = player.GetItem2Attack();
				temp3 = player.GetItem2Amor();
				temp4 = player.GetItem2EquipType();
				player.GetPi2(inven.GetName3());
				player.GetPi2Attack(inven.GetAttack3());
				player.Attack(inven.GetAttack3());
				player.GetPi2Amor(inven.GetAmor3());
				player.GetEquipType2(inven.GetEquipType3());
				player.Amor(inven.GetAmor3());
				inven.InvenName3(temp1);
				inven.InvenAttack3(temp2);
				inven.InvenAmor3(temp3);
				inven.InvenEquipType3(temp4);
			}
			else
			{
				cout << "아이템창이 비어있습니다." << endl;
				Sleep(800);
			}
			Sleep(800);
			Inven();
			break;
		case 4:
			if (inven.GetEquipType4() == 1)
			{
				cout << inven.GetName4() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem1();
				temp2 = player.GetItem1Attack();
				temp3 = player.GetItem1Amor();
				temp4 = player.GetItem1EquipType();
				player.GetPi1(inven.GetName4());
				player.GetPi1Attack(inven.GetAttack4());
				player.Attack(inven.GetAttack4());
				player.GetPi1Amor(inven.GetAmor4());
				player.GetEquipType1(inven.GetEquipType4());
				player.Amor(inven.GetAmor4());
				inven.InvenName4(temp1);
				inven.InvenAttack4(temp2);
				inven.InvenAmor4(temp3);
				inven.InvenEquipType4(temp4);
			}
			else if (inven.GetEquipType4() == 2)
			{
				cout << inven.GetName4() << "을 착용했습니다." << endl;
				string temp1;
				int temp2;
				int temp3;
				int temp4;
				temp1 = player.GetItem2();
				temp2 = player.GetItem2Attack();
				temp3 = player.GetItem2Amor();
				temp4 = player.GetItem2EquipType();
				player.GetPi2(inven.GetName4());
				player.GetPi2Attack(inven.GetAttack4());
				player.Attack(inven.GetAttack4());
				player.GetPi2Amor(inven.GetAmor4());
				player.GetEquipType2(inven.GetEquipType4());
				player.Amor(inven.GetAmor4());
				inven.InvenName4(temp1);
				inven.InvenAttack4(temp2);
				inven.InvenAmor4(temp3);
				inven.InvenEquipType4(temp4);
			}
			else
			{
				cout << "아이템창이 비어있습니다." << endl;
				Sleep(800);
			}
			Sleep(800);
			Inven();
			break;
		default:
			cout << "잘못 선택했습니다." << endl;
			Sleep(800);
			Inven();
			break;
		}
	case 2:
		break;
	case 3:
		GameStart();
		break;
	default:
		break;
	}


}

void Battle::InvenUi()
{
	cout << "**********************" << endl << endl;
	cout << "1." << inven.GetName1() << endl;
	cout << "2." << inven.GetName2() << endl;
	cout << "3." << inven.GetName3() << endl;
	cout << "4." << inven.GetName4() << endl << endl;

	cout << "HP물약:x" << player.GetHpPotion() << endl;
	cout << "MP물약:x" << player.GetMpPotion() << endl << endl;
	cout << "**********************" << endl;
}


void Battle::StoreCase()
{

	if (store.GetMoney() > player.GetMoney())
	{
		cout << "돈이 부족합니다" << endl;
		Sleep(800);
		Store();
	}
	else
	{
		player.GetPM(player.GetMoney(), -store.GetMoney());
		cout << endl;
		cout << store.GetName() << "을 구매했습니다." << endl;
		inven.equip(inven.GetInvenCount(),store.GetName(),store.GetAttack(),store.GetAmor(),store.GetEquipType());
		inven.InvenCount();
		Sleep(1000);
		Store();
	}
}

void Battle::InvenFull()
{
	if (inven.GetInvenCount() > 4)
	{
		cout << "가방에 여유 공간이 없습니다." << endl;
		Sleep(800);
		Store();
	}
}


void Battle::StoreUi()
{
	cout << "***********************" << endl << endl;
	store.Equip1();
	cout << "1. " << store.GetName() << " " << store.GetMoney() << "G" << endl;
	store.Equip2();
	cout << "2. " << store.GetName() << " " << store.GetMoney() << "G" << endl;
	store.Equip3();
	cout << "3. " << store.GetName() << " " << store.GetMoney() << "G" << endl << endl;
	store.Equip4();
	cout << "4. " << store.GetName() << " " << store.GetMoney() << "G" << endl;
	store.Equip5();
	cout << "5. " << store.GetName() << " " << store.GetMoney() << "G" << endl;
	store.Equip6();
	cout << "6. " << store.GetName() << " " << store.GetMoney() << "G" << endl << endl;
	store.HpPotion();
	cout << "7. " << store.GetName() << " " << store.GetMoney() << "G" << endl;
	store.MpPotion();
	cout << "8. " << store.GetName() << " " << store.GetMoney() << "G" << endl<<endl;
	cout << "9. 나가기" << endl;
	cout << endl;
	cout << "***********************" << endl;

}


void Battle::Hospital()
{
}

void Battle::lotto()
{
}
