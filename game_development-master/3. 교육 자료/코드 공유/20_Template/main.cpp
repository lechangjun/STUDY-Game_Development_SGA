#include <iostream>
#include <string>
#include "Template.h"

using namespace std;

int main()
{
	Template<string> myStringTemp("StringType");

	Template<int> myIntTemp(1234);

	Template<float> myFloatTemp(myIntTemp);
}