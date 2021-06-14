#include "stdafx.h"
#include "Character.h"

using MatchFunc = bool(*)(int, int);
//typedef bool(*MatchFunc)(int, int);

void FindMatches(int values1[], int values2[], size_t numValues, MatchFunc intFunc)
{
	for (size_t i = 0; i < numValues; i++)
	{
		if (intFunc(values1[i], values2[i]))
		{
			cout << "Match found at position " << i <<
				" ( " << values1[i] << ", " << values2[i] << ")" << endl;
		}
	}
}

bool IntEqual(int intItem1, int intItem2)
{
	return intItem1 == intItem2;
}

bool BothOdd(int intItem1, int intItem2)
{
	return intItem1 % 2 == 1 && intItem2 % 2 == 1;
}



int main()
{
	//int i = 7;

	//int* ptr;
	//ptr = new int;


	//int** handle;
	//handle = new int*;
	//*handle = new int;


	//new int;

	////malloc()

	//Character* myChar = (Character*)malloc(sizeof(Character));
	//Character* myOtherChar = new Character;

	//free(myChar);
	//delete myOtherChar;

	//int myArray[5];

	//int* myArrayPtr = new int[5];

	//delete[] myArrayPtr;

	//Character* myCharArray = new Character[5];

	//delete[] myCharArray;
	//myCharArray = nullptr;

	//char board[3][3];
	//board[0][0] = 'X'; //0,0 위치에 X표시
	//board[2][1] = 'O';

	////char** board = new char[3][3];

	//int yDimension = 5, xDimension = 5;

	//char** myArray = new char*[yDimension];
	//for (size_t i = 0; i < yDimension; i++)
	//	myArray[i] = new char[xDimension];

	//for (size_t i = 0; i < yDimension; i++)
	//{
	//	delete[] myArray[i];
	//}
	//delete[] myArray;

	////vector<vector<Character*>> test;

	//Character* myChar = new Character;

	//char* charPtr = (char*)myChar;

	//char* charPtr = static_cast<char*>(myChar);

	//char* charPtr2 = reinterpret_cast<char*>(myChar);

	//int myIntArray[10];
	//int* myIntPtr = myIntArray;

	//myIntPtr[4] = 5;


	int arr1[] = { 2,5,6,9,10,1,1 };
	int arr2[] = { 4,4,2,9,0,3,4 };

	int arrSize = sizeof(arr1) / sizeof(arr1[0]);

	cout << "CAlling FindMatches() using intEqual():" << endl;
	FindMatches(arr1, arr2, arrSize, IntEqual);

	cout << "Calling FindMatches() using BothOdd():" << endl;
	FindMatches(arr1, arr2, arrSize, BothOdd);



}



