#include <iostream>
#include <string>

using namespace std;

int _strlen(char* str)
{
	int len = 0;
	while (str[++len]);
	return len;
}

int _strcmp(char* str, char* str2)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			break;
		i++;
	}
	return str[i] - str2[i];
}

void _strcat(char* str, char* str2)
{
	while (*str)
	{
		str++;
	}
	while (*str = *str2)
	{
		str++;
		str2++;
	}
}

void _strcpy(char* str, char* str2)
{
	int i = 0;
	while (str2[i] = str[i++]);
}

//========================================
int main()
{
	char str[100] = "ABCDEF";
	char str2[100] = "ABB";

	cout << "str: " << str << endl;
	cout << "str2: " << str2 << endl;
	cout << endl;

	cout << "_strlen: " << _strlen(str) << endl;

	cout << "_strcmp: " << _strcmp(str, str2) << endl;
	
	_strcpy(str, str2);
	cout << "_strcpy ÈÄ str2: " << str2 << endl;

	cout << endl;

	char arr1[10] = "ABC";
	char arr2[] = "de";

	cout << "arr1: " << arr1 << endl;
	cout << "arr2: " << arr2 << endl;
	cout << endl;

	_strcat(arr1, arr2);
	cout << "_strcat: " << arr1 << endl;

}

