#include <iostream>
#include <string>

using namespace std;

void CallByValue(int value1, int value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;

	cout << value1 << " , " << value2 << endl;
}
void CallByAddress(int* value1, int* value2)
{
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

void CallByRef(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}


int main()
{
	int a = 20, b = 60;

	CallByRef(a, b);
	//CallByValue(a, b);
	//CallByAddress(&a, &b);
	
	cout << a << " , " << b << endl;

	


}



