#pragma once
#include "Super.h"

class Sub : public Super
{
public:
	Sub();
	~Sub();
	
	void SomeOtherMethod(){}
	virtual void SomeMethod() override { cout << "sub" << endl; }


};