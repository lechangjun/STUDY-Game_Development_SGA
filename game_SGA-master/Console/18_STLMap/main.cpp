#include "stdafx.h"


int main()
{
	pair<string, int> myPair("hello", 5);
	pair<string, int> myOtherPair;
	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	pair<string, int> myThirdPair(myOtherPair);

	if (myPair < myOtherPair)
	{
		cout << "myPair is less than myOther" << endl;
	}
	else
	{
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	if (myOtherPair == myThirdPair)
	{
		cout << "myOtherPair is equal to myThirdPair" << endl;
	}
	else
	{
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

}



