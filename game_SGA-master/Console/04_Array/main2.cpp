#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

struct Unit
{
	int Attack;
	int Hp;
	int Defense;
};


int main()
{
	srand(size_t(time(NULL)));

	Unit garen[12];

	for (int i = 0; i < 12; i++)
	{
		garen[i].Attack = rand() % 10;
		garen[i].Hp = rand() % 10 + 100;
		garen[i].Defense = 5.1f;
	}

	for (int i = 0; i < 12; i++)
	{
		cout << "����[ " << i << "]" <<"���ݷ� :" << garen[i].Attack << endl;
		cout << "����[ " << i << "]" <<"ü�� : " <<garen[i].Hp << endl;
		cout << "����[ " << i << "]" <<"���� : "<< garen[i].Defense << endl;
	}



}