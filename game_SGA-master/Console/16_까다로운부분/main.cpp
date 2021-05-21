#include "stdafx.h"

void Incr(int& value)
{
	cout << "increment with lvalue reference" << endl;
	++value;
}

void Incr(int&& value)
{
	cout << "increment with rvalue reference" << endl;
	++value;
}



int main()
{
	//int x = 3;
	//int& xRef = x;

	//xRef = 10;

	////int& emptyRef;

	////int& unnamedRef1 = 5;
	//const int& unnamedRef2 = 5;

	//int x = 3, y = 4;
	//int& xRef = x;
	//xRef = y;
	////xRef = &y;

	//int x = 3, z = 5;
	//int& xRef = x;
	//int& zRef = z;
	//zRef = xRef;

	//int* intP;
	//int*& ptrRef = intP;
	//ptrRef = new int;
	//*ptrRef = 5;

	//cout << *intP << endl;

	//int x = 3;
	//int& xRef = x;
	//int* xPtr = &xRef;
	//*xPtr = 100;

	////xPtr == xRef;
	//xPtr == &x;
	//xPtr == &xRef;

	int a = 10, b = 20;
	Incr(a);
	Incr(a + b);
	Incr(3);

	Incr(move(b));

	//int& i = 2;
	//int a = 2, b = 3;
	//int& j = a + b;

	//int&& i = 2;
	//int a = 2, b = 3;
	//int&& j = a + b;

}



