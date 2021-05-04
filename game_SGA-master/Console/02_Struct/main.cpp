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
	student.Name = "홍길동";
	student.Weight = 100;

	cout << "학생 나이" << student.Age << endl;
	cout << "학생 키" << student.Height << endl;
	cout << "학생 이름" << student.Name << endl;
	cout << "학생 몸무게" << student.Weight << endl;

	Unit marine;
	Unit fireBat;


}