#include <iostream>

using namespace std;

/*
	if(조건식)
	{
		내용
	}
	else if(조건)
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
	//관계연산자
	// < , <= , >, >=, != , ==
	
	//int val1 = 10, val2 = 20, val3 = 30, val4 = 10;

	//if (val1 > val2)
	//{
	//	cout << "val1 은 val2 보다 크다" << endl;
	//}
	//else if (val1 < val2)
	//{
	//	cout << "val1 은 val2 보다 작다" << endl;
	//}
	//else
	//{
	//	cout << "val1 은 val2보다 크지도 작지도 않다." << endl;
	//}

	//if (val1 != val4)
	//{
	//	cout << "val1 과 val4는 같지 않다" << endl;
	//}
	//else if (val1 == val4)
	//{
	//	cout << "val1 과 val4는 같다" << endl;
	//}

	//if (val1 < val2 && val1 == val4)
	//{
	//	cout << "1" << endl;
	//}

	//if (val3 > val4 || val3 == val2)
	//{
	//	cout << "2" << endl;
	//}

	int num; //0번은 남자 1번은 여자
	cout << "성별을 입력해 주세요 (0 ~ 1번) : ";
	cin >> num;

	switch (num)
	{
		case 0:
		{
			cout << "0번 남자 선택" << endl;
		}
		break;

		case 1:
		{
			cout << "1번 여자 선택" << endl;
		}
		break;

		default:
			cout << "0번도 1번도 아닌" << endl;
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