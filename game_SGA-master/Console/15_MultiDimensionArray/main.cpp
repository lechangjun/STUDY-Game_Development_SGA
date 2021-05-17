#include "stdafx.h"


int main()
{
	//int intArr[5] = { 23, 26, 24, 31, 28 };

	//// *(intArr + i) == *&intArr[i] == intArr[i]

	//cout << *(intArr + 1) << endl;
	//cout << *&*&intArr[1] << endl;

	//int* intPtr = nullptr;// NULL;

	//intPtr = intArr;

	//cout << intPtr << " , " << intPtr + 0 << " , "  << &intPtr[0] << endl;

	//intPtr = intPtr + 1;

	//cout << intPtr[-1] << endl;


	//2차원배열

	int multiArr[4][5] =
	{
		{94,98,87,103,101}, //multiArr[0]
		{98,99,91,107,105},
		{93,91,90,101,104},
		{95,100,88,105,103},
	};

	//*(multiArr + i) == *&multiArr[i] == multiArr[i]

	//cout << *(multiArr + 1) << endl;
	//cout << *&multiArr[1] << endl;
	//cout << multiArr[1] << endl;

	//cout << &multiArr[1][0] << endl;

	cout << *(multiArr[0] + 0) << endl;
	cout << *(multiArr[0] + 1) << endl;

	cout << *(*(multiArr + 1) + 0) << *(*(multiArr + 0) + 1) << endl;

	int *ptrInt = nullptr;
	ptrInt = multiArr[0];
	ptrInt = &multiArr[0][0];

	//cout << ptrInt[0][0] << endl;

	int(*multiPtr)[5] = multiArr;

	cout << multiPtr[0][0] << endl;

	int a = 1, b = 2, c = 3;
	int* ptr[3] = { nullptr, nullptr, nullptr };

	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;

	cout << &a << &b << &c << endl;
	cout << ptr[0] << ptr[1] << ptr[2] << endl;

	cout << *ptr[0] << *ptr[1] << *ptr[2] << endl;
	cout << **(ptr + 0) << **(ptr + 1) << **(ptr + 2) << endl;

}



