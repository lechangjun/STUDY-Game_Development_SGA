#include <iostream>

using namespace std;

#define SIZE 10

int main()
{
	int temp = 10;

	const char str[13] = "Hello World!";

	cout << str[5] << endl;

	for (int i = 0; i < 13; i++)
	{
		cout << str[i] << endl;
	}

	int student[30];

	student[0] = 90;
	student[1] = 80;
	student[2] = 70;

	cout << student << endl;

	for (int i = 0; i < 30; i++)
		cout << i << " 번째 학생의 점수 : " << student[i] << endl;

	int myNumbers[5] = { 90,80,70,60,50 };
	int myNumbers2[] = { 90,80,70,60,50 };
	int myNumbers3[5] = { 90,80 };
	int myNumbers4[5]{ 90,80,70,60,50 };
	int myNumbers5[]{ 90, };

	for (int i = 0; i < 5; i++)
		cout << myNumbers3[i] << endl;

	int arr[3] = { 87,99,80 };
	int total = 0;

	total = arr[0] + arr[1] + arr[2];
	cout << total << endl;
	float aver = total / 3;
	cout << aver << endl;

	for (int i = 0; i < 3; i++)
	{
		total += arr[i];
	}

	const int size = 10;
	int arr3[size];

	int arr4[SIZE];

}