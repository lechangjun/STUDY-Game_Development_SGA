#include "stdafx.h"
#include "Super.h"
#include "Sub.h"

class Something
{
public:
	Something() { cout << "2"; }
	
	~Something() { cout << "2"; }
};

class Parent
{
public:
	Parent() { cout << "1"; }
	Parent(int i) { cout << i ; }

	virtual ~Parent() { cout << "1"; }
};

class Child : public Parent
{
public:
	Child()
		//:Parent(4)
	{ 
		cout << "3";
	}
	Child(int i)
		:Parent(i)
	{
		cout << i;
	}

	~Child() { cout << "3"; }


private:
	Something mDataMember;
};


int main()
{
	//Child myChild;

	Parent* ptr = new Child();

	delete ptr;
}



