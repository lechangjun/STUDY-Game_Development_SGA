#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;



int main()
{
	srand(size_t(time(NULL)));

	int deck[9];
	int player[3];

	int strikeCount = 0;
	int ballCount = 0;

	int gameCount = 0;

	for (int i = 0; i < 9; i++)
	{
		deck[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int index1, index2, temp;

		index1 = rand() % 9;
		index2 = rand() % 9;

		temp = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = temp;
	}

	while (1)
	{

		strikeCount = 0;
		ballCount = 0;

		cout << "숫자 야구 게임!" << endl;
		cout << "컴퓨터 숫자" << deck[0] << " , " << deck[1] << " , " << deck[2] << endl;

		int tempNum;
		cin >> tempNum;

		if (tempNum > 999 || tempNum < 100)
		{
			cout << "잘못 입력 하셨습니다. " << endl;
		}

		player[0] = int(tempNum / 100);
		player[1] = int(tempNum / 10) - player[0] * 10;
		player[2] = tempNum - player[0] * 100 - player[1] * 10;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (deck[i] == player[j])
				{
					if (i == j)
					{
						strikeCount++;
					}
					else
					{
						ballCount++;
					}
				}
			}//for(j)
		}//for(i)

		cout << strikeCount << 'S' << ballCount << 'B' << endl;

		gameCount++;

		if (strikeCount == 3)
		{
			cout << gameCount << "번 만에 맞췄다" << endl;
			break;
		}


	}//end of While(i)

	

}