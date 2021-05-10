#include "stdafx.h"

char* CopyString(const char* str)
{
	char* result = new char[strlen(str)];
	
	strcpy(result, str);
	
	return result;
}

char* AppendString(const char* str1, const char* str2, const char* str3)
{
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
	strcpy(result, str1);
	strcpy(result, str2);
	strcpy(result, str3);
	
	return result;

}


int main()
{
	//char text1[] = "abcdef";
	//int s1 = sizeof(text1);
	//int s2 = strlen(text1);
	//
	//const char* text2 = "abcdef";
	//int s3 = sizeof(text2);
	//int s4 = strlen(text2);

	//int a = 10;
	//
	//char* ptr = "hello";

	////ptr = ptr + 1;

	////ptr[1] = 'a';

	//const char* ptr2 = "hello";
	////ptr2[1] = 'a';

	//char arr[] = "hello";
	//arr[1] = 'a';

	//cout << ptr << endl;

	string A("12");
	string B("34");
	string C;

	C = A + B;
	A += B;

	cout << C << endl;

	char* a = "12";
	char b[] = "12";

	//if (a == b)
	//{

	//}

	//if (strcmp(a, b) == 0)
	//{

	//}

	string myString = "hello";
	myString == ", there";
	string myOtherString = myString;
	if (myString == myOtherString)
	{
		myOtherString[0] = 'H';
	}


	string str = "Hello \"World\" !";
	//string str2 = R"(Hello)" World"!)";
	string str3 = R"-(Hello)"() )-";



}



