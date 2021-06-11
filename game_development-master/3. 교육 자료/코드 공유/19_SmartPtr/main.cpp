#include "stdafx.h"
#include "Character.h"

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

	char board[3][3];
	board[0][0] = 'X'; //0,0 위치에 X표시
	board[2][1] = 'O';

	//char** board = new char[3][3];

	int yDimension = 5, xDimension = 5;

	char** myArray = new char*[yDimension];
	for (size_t i = 0; i < yDimension; i++)
		myArray[i] = new char[xDimension];

}



