#include <iostream>

using namespace std;

/*
	if(���ǽ�)
	{
		����
	}
	else if(����)
	{}
	else if
	else
	{
	}
*/

enum class Job
{
	Knight, Mage,
	Thief, Monk
};



int main()
{
	//���迬����
	// < , <= , >, >=, != , ==
	
	//int val1 = 10, val2 = 20, val3 = 30, val4 = 10;

	//if (val1 > val2)
	//{
	//	cout << "val1 �� val2 ���� ũ��" << endl;
	//}
	//else if (val1 < val2)
	//{
	//	cout << "val1 �� val2 ���� �۴�" << endl;
	//}
	//else
	//{
	//	cout << "val1 �� val2���� ũ���� ������ �ʴ�." << endl;
	//}

	//if (val1 != val4)
	//{
	//	cout << "val1 �� val4�� ���� �ʴ�" << endl;
	//}
	//else if (val1 == val4)
	//{
	//	cout << "val1 �� val4�� ����" << endl;
	//}

	//if (val1 < val2 && val1 == val4)
	//{
	//	cout << "1" << endl;
	//}

	//if (val3 > val4 || val3 == val2)
	//{
	//	cout << "2" << endl;
	//}

	int num; //0���� ���� 1���� ����
	cout << "������ �Է��� �ּ��� (0 ~ 1��) : ";
	cin >> num;

	switch (num)
	{
		case 0:
		{
			cout << "0�� ���� ����" << endl;
		}
		break;

		case 1:
		{
			cout << "1�� ���� ����" << endl;
		}
		break;

		default:
			cout << "0���� 1���� �ƴ�" << endl;
			break;
	}

	Job jobs;

	switch (jobs)
	{
		case Job::Knight:

			break;
		case Job::Mage:
			break;
		case Job::Thief:
			break;
		case Job::Monk:
			break;
		default:
			break;
	}

	switch (jobs)
	{
		case Job::Knight:
			break;
		case Job::Mage:
			break;
		case Job::Thief:
			break;
		case Job::Monk:

			break;
		default:
			break;
	}

	if (jobs == Job::Knight)
	{

	}
	else if (jobs == Job::Mage)
	{

	}

}