#include <iostream>
#include <cstdio>
#include <limits>
#include <string>

using namespace std;

struct Student
{
	string Name;
	int Age;
	int Weight;
	int Height;
}student2 , student3;

struct Unit
{
	int Attack;
	int Hp;
	int Deffense;
}firebat2,zergling,marine2,scv;


int main()
{
	
	Student student;

	student2.Age = 50;

	student.Age = 25;
	student.Height = 200;
	student.Name = "ȫ�浿";
	student.Weight = 100;

	cout << "�л� ����" << student.Age << endl;
	cout << "�л� Ű" << student.Height << endl;
	cout << "�л� �̸�" << student.Name << endl;
	cout << "�л� ������" << student.Weight << endl;

	Unit marine;
	Unit fireBat;


}