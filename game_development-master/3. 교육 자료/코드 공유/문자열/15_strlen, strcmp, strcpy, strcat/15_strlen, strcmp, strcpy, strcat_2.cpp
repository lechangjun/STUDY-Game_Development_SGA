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
	cout << "맨 앞글자-> MyString1.front(): "<< MyString1.front() << endl;

	cout << "맨 뒷글자-> MyString2.back(): " << MyString2.back() << endl;

	cout << "메모리 크기-> MyString1.capacity(): " << MyString1.capacity() << endl;
	cout << "메모리 크기-> MyString2.capacity(): " << MyString2.capacity() << endl;

	cout << "n번째 자리부터 끝까지 문자열 반환-> MyString1.substr(n) : n = 2, " << MyString1.substr(2) << endl;
	cout << "n번째 자리부터 m만큼 문자열 반환-> MyString1.substr(n, m) : n = 3, m = 2, " << MyString1.substr(3, 2) << endl;

	cout << "스왑-> swap(MyString1, MyString2)->> ";
	swap(MyString1, MyString2);
	cout << "MyString1: " << MyString1 << " ";
	cout << "MyString2: " << MyString2 << endl;

	swap(MyString1, MyString2);

	cout << "string의 크기 바꾸기-> MyString1.resize(n): ";
	cout << "n = 2";
	MyString1.resize(2);
	cout << ", " << MyString1 << endl;
}