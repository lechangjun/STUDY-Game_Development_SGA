#include "stdafx.h"
#include "Character.h"

void ThirdPartyLibraryMethod(char* str);

void Func(const char* str)
{
	ThirdPartyLibraryMethod(const_cast<char*>(str));
}

int main()
{
	//size_t

		typedef int* Intptr;
		
		Intptr p1;
		int* p2;

		//size_t  ����̵� ��Ʈ ��� ���

		p1 = p2;
		p2 = p1;

		//typedef int Myint;
		//using Myint = int;
		
		//casting
		

		//static_cast<>
		float temp = 3.141592;
		int temp2 = (int)temp;
		//int temp2 = temp;
		int temp3 = static_cast<int>(temp);


		//const_cast<> ��� �Ӽ��� ������ ģ��
		const char* result = "";
		const char* str = "hello world";

		result = "1"; // ������ �����ϳ� 
		result = "hello";   // �迭�� ������ �Ұ�����

		const int pi = 3.14f;
		//pi = 10;
		const_cast<int>(pi);

		//reinterpret_cast ���� ������� �������Ҷ�����
		class X {};
		class Y {};

		X x;
		Y y;
		X* xp = &x;
		Y* yp = &y;

		//xp = static_cast<X*>(yp);
		xp = reinterpret_cast<X*>(yp);


		//dynamic_cast


		//���
		//sub mySub;

		//mySub.SomeMethod();

		//sub mySuper;

		//mySuper.SomeMethod();



		Sub mysub;
		Super MySuper = mysub;

		mySuper.someMethod();


		Super& mySuper2 = mysub;
		mySuper2.someMEthod();

 }



