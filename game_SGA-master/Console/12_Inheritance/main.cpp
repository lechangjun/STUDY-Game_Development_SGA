#include "stdafx.h"
#include "Super.h"
#include "Sub.h"

//extern void ThirdPartyLibraryMethod(char* str);
//
//void Func(const char* str)
//{
//	ThirdPartyLibraryMethod(const_cast<char*>(str));
//}


int main()
{
	//typedef int* IntPtr;
	//
	//IntPtr p1;
	//int* p2;

	////size_t

	//p1 = p2;
	//p2 = p1;

	//typedef int MyInt;
	//using MyInt = int;


	////Casting

	////static_cast<>

	//float temp = 3.141592;
	//int temp2 = (int)temp;
	//int temp3 = static_cast<int>(temp);
	//
	////const_cast<>

	////const int pi = 3.14f;
	////pi = 10;

	////reinterpret_cast
	//class X{};
	//class Y{};

	//X x;
	//Y y;
	//X* xp = &x;
	//Y* yp = &y;

	////xp = static_cast<X*>(yp);
	//xp = reinterpret_cast<X*>(yp);

	////dynamic_cast

	//Super mySuper;
	//mySuper.SomeMethod();
	//
	//Sub mySub;
	//mySub.SomeMethod();
	//mySub.SomeOtherMethod();
	
	Sub mySub;

	Super mySuper = mySub;
	mySuper.SomeMethod();

	Super& mySuper2 = mySub;
	mySuper2.SomeMethod();


}



