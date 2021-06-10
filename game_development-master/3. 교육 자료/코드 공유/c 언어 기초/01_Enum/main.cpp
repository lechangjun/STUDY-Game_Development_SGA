#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

enum PieceType
{
	PieceTypeKing, PieceTypeQueen,
	PieceTypeRook, PieceTypePawn
};

//enum PieceType
//{
//	PieceTypeKing = 1, PieceTypeQueen,
//	PieceTypeRook = 10, PieceTypePawn
//};

enum Fruits
{
	Banana, Apple,
	Grapes, Peach
};

enum class MyEnum
{
	EnumValue1,
	EnumValue2 = 10,
	EnumValue3
};

enum class MyEnumUint : unsigned char
{

};



int main()
{
	//const int PieceTypeKing = 0;
	//const int PieceTypeQueen = 1;
	//const int PieceTypeRook = 2;
	//const int PieceTypePawn = 3;

	//int myPiece = PieceTypeKing;

	PieceType myPiece;
	myPiece = PieceTypeKing;

	if (PieceTypeKing == Banana)
	{
		cout << "Same" << endl;
	}

	if (PieceTypeKing == 0)
	{
		cout << "Same" << endl;
	}

	MyEnum value1 = MyEnum::EnumValue1;

	//if(MyEnum::EnumValue3 == 11)

}