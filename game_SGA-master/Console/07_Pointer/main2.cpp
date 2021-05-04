#include <iostream>
#include <string>

using namespace std;

int main()
{
	//int donuts = 6;
	//double cups = 4.5;

	////cout << donuts << " , " << &donuts << endl;
	////cout << cups << " , " << &cups << endl;

	////cout << abs((int)(&donuts) - (int)(&cups)) << endl;

	//int a = 10;
	//int * pA = &a;

	//cout << a << endl;
	//cout << pA << endl;

	//cout << &a << endl;
	//cout << &pA << endl;

	//cout << *pA << endl;

	//*pA = *pA + 1;

	//cout << a << endl;

	///*int* p1;
	//int * p2;
	//int *p2;*/

	////int* fellow;
	////*fellow = 22332;

	//int* ptr;
	//double* ptr2;
	////ptr = 0xB80000;
	//ptr = (int*)0xB80000;

	//cout << sizeof(ptr2) << endl;

	//int ptrA = 1001;
	//int* ptrB = new int;

	//cout << &ptrA << " , " << ptrB << endl;

	//*ptrB = 10;
	//cout << *ptrB << endl;

	//delete ptrB;

	//cout << ptrB << endl;
	//cout << *ptrB << endl;

	//int jugs = 5;
	//int* pi = &jugs;
	//delete pi;

	//int* pSome = new int[10];

	//delete[] pSome;

	float* p3 = new float[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] " << p3[1] << "입니다.\n";
	p3 = p3 + 1;
	cout << "이제 p3[0]이 " << p3[0] << "이고, ";
	cout << " p3[1]이" << p3[1] << " 입니다.\n";

	p3 = p3 - 1;


	delete[] p3;

}



