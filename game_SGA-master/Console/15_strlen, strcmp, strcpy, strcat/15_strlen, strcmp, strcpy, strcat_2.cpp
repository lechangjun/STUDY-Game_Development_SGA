#include <iostream>
#include <string>

using namespace std;

int main()
{
	string MyString1 = "Hello ";
	string MyString2 = "World!";

	cout << "MyString1: Hello " << endl;
	cout << "MyString2: World!" << endl;
	cout << endl;
	cout << "�� �ձ���-> MyString1.front(): "<< MyString1.front() << endl;

	cout << "�� �ޱ���-> MyString2.back(): " << MyString2.back() << endl;

	cout << "�޸� ũ��-> MyString1.capacity(): " << MyString1.capacity() << endl;
	cout << "�޸� ũ��-> MyString2.capacity(): " << MyString2.capacity() << endl;

	cout << "n��° �ڸ����� ������ ���ڿ� ��ȯ-> MyString1.substr(n) : n = 2, " << MyString1.substr(2) << endl;
	cout << "n��° �ڸ����� m��ŭ ���ڿ� ��ȯ-> MyString1.substr(n, m) : n = 3, m = 2, " << MyString1.substr(3, 2) << endl;

	cout << "����-> swap(MyString1, MyString2)->> ";
	swap(MyString1, MyString2);
	cout << "MyString1: " << MyString1 << " ";
	cout << "MyString2: " << MyString2 << endl;

	swap(MyString1, MyString2);

	cout << "string�� ũ�� �ٲٱ�-> MyString1.resize(n): ";
	cout << "n = 2";
	MyString1.resize(2);
	cout << ", " << MyString1 << endl;
}