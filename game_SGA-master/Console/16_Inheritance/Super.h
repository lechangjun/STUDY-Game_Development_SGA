#pragma once

class Super
{
public:
	Super();
	Super(int i);

	~Super();
	virtual void SomeMethod() { cout << "super" << endl; }


protected:
	int protectedInt;

private:
	int privateInt;
};