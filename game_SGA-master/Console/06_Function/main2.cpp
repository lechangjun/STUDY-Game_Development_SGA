#include <iostream>
#include <string>

using namespace std;


//struct DistanceAndDirectionAndRotation
//{
//
//};

void MyFunction(int i, char c);

int AddNumbers(int number1, int number2);
float AddNumbers(float number1, float number2);
int AddNumbers(int num1, int num2, int num3);

auto Temp(int number1, int number2)
{
	return number1 + number2;
}

auto x = 123;

//auto result = GetFoo();

auto Temp(int number1, int number2) -> int
{
	return number1 + number2;
}

int test = 123;
decltype(test) y = 456;



int main()
{
	//bool bRight = false;

	MyFunction(8,'a');

	int someInt = 10;
	MyFunction(someInt, 'a');

	char someChar = 'b';

	MyFunction(8, someChar);

	int sum = AddNumbers(5, 3);
	
	AddNumbers(3.3f, 3.3f);

	
}

void MyFunction(int i, char c)
{
	cout << "the value of i is " << i << endl;
	cout << "the value of c is " << c << endl;
}

int AddNumbers(int number1, int number2)
{
	cout << "int" << endl;
	return number1 + number2;
}

float AddNumbers(float number1, float number2)
{
	cout << "float" << endl;
	return number1 + number2;
}

int AddNumbers(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
}

