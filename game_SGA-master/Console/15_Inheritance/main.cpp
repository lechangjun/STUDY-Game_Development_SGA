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
//////////////////////////////////////////////////////////////////////////////

class Book
{
public:
	virtual ~Book(){}
	virtual string GetDescription() const { return "Book"; }
	virtual int GetHeight() const { return 120; }
};
class Paperback : public Book
{
public:
	virtual string GetDescription() const override
	{
		return "Paperback " + Book::GetDescription();
	}
};
class Romance : public Paperback
{
public:
	virtual string GetDescription() const override
	{
		return "Romance " + Paperback::GetDescription();
	}
	virtual int GetHeight() const override
	{
		return Paperback::GetHeight() / 2;
	}
};

class Technical : public Book
{
public:
	virtual string GetDescription() const override
	{
		return "Thechnical " + Book::GetDescription();
	}
};



int main()
{
	////Child myChild;

	//Parent* ptr = new Child();

	//delete ptr;

	Romance novel;
	Book book;

	cout << novel.GetDescription() << endl;
	cout << book.GetDescription() << endl;
	cout << novel.GetHeight() << endl;
	cout << book.GetHeight() << endl;


}



