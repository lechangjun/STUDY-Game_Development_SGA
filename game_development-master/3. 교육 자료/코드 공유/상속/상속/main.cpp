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

		//size_t  언싸이드 인트 대신 사용

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


		//const_cast<> 상수 속성을 없에는 친구
		const char* result = "";
		const char* str = "hello world";

		result = "1"; // 대입은 가능하나 
		result = "hello";   // 배열로 수정은 불가능함

		const int pi = 3.14f;
		//pi = 10;
		const_cast<int>(pi);

		//reinterpret_cast 전혀 관계없는 포인터할때쓰임
		class X {};
		class Y {};

		X x;
		Y y;
		X* xp = &x;
		Y* yp = &y;

		//xp = static_cast<X*>(yp);
		xp = reinterpret_cast<X*>(yp);


		//dynamic_cast


		//상속
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



