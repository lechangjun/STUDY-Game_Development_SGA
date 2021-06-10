#include "stdafx.h"

void PrintVector(vector<int>& intVectors)
{
	for (auto& vec : intVectors)
		cout << vec << " , ";
	cout << endl;
}

int main()
{
	//vector<double> doubleVector(10);

	//double max = -numeric_limits<double>::infinity();

	//for (size_t i = 0; i < doubleVector.size(); i++)
	//{
	//	cout << "Enter score " << i + 1 << ": ";
	//	cin >> doubleVector[i];
	//	if (doubleVector[i] > max)
	//	{
	//		max = doubleVector[i];
	//	}
	//}
	//max /= 100.0f;
	//for (auto& element : doubleVector)
	//{
	//	element /= max;

	//	cout << element << " ";
	//}

	//vector<double> doubleVector;
	//double max = -numeric_limits<double>::infinity();

	//for (size_t i = 1; true; i++)
	//{
	//	double temp;
	//	cout << "Enter score " << i << "(-1 to stop): ";
	//	cin >> temp;
	//	if (temp == -1)
	//	{
	//		break;
	//	}
	//	doubleVector.push_back(temp);
	//	if (temp > max)
	//	{
	//		max = temp;
	//	}
	//}
	//max /= 100.0f;
	//for (auto& element : doubleVector)
	//{
	//	element /= max;
	//	cout << element << " ";
	//}

	
	//vector<int> intVector;
	//vector<int> intVector2(10, 100);

	//for (int i = 0; i < intVector2.size(); i++)
	//	cout << intVector2[i] << endl;

	//vector<int> intVector3({ 1,2,3,4,5,6 });

	//vector<int> intVector4 = { 1,2,3,4,5,6 };
	//vector<int> intVector5{ 1,2,3,4,5,6 };

	//vector<int> intVector(10);
	//PrintVector(intVector);
	////..
	//intVector.assign(5, 100);
	//PrintVector(intVector);

	//intVector.assign({ 1,2,3,4 });
	//PrintVector(intVector);

	//vector<int> vectorOne(10, 0);
	//PrintVector(vectorOne);
	//vector<int> vectorTwo(5, 100);
	//vectorOne.swap(vectorTwo);
	//
	//PrintVector(vectorOne);

	//vector<int> vectorOne(10);
	//vector<int> vectorTwo(10);
	//if (vectorOne == vectorTwo)
	//{
	//	cout << "equal!" << endl;
	//}
	//else
	//{
	//	cout << "not equal!" << endl;
	//}
	//vectorOne[3] = 50;
	//if (vectorOne < vectorTwo)
	//{
	//	cout << "vectorOne is less than vectorTwo" << endl;
	//}
	//else
	//{
	//	cout << "vectorOne is not less than vectorTwo" << endl;
	//}


	//vector<double> doubleVector;
	//double max = -1;

	//max /= 100.0f;
	//for (vector<double>::iterator iter = doubleVector.begin();
	//	iter != doubleVector.end(); iter++)
	//{
	//	*iter /= max;
	//	cout << *iter << " , ";
	//}

	//for (auto iter = doubleVector.begin();
	//	iter != doubleVector.end(); iter++)
	//{
	//	*iter /= max;
	//	cout << *iter << " , ";
	//}

	//vector<int> intVector(10);
	//auto it = begin(intVector);
	//it += 5;
	//--it;
	//*it = 4;

	vector<int> vectorOne = { 1,2,3,5 };
	vector<int> vectorTwo;

	vectorOne.insert(vectorOne.cbegin() + 3, 4);

	for (int i = 6; i <= 10; i++)
	{
		vectorTwo.push_back(i);
	}
	PrintVector(vectorOne);
	PrintVector(vectorTwo);

	vectorOne.insert(vectorOne.cend(), vectorTwo.cbegin(), vectorTwo.cend());
	PrintVector(vectorOne);

	vectorOne.erase(vectorOne.cbegin() + 1, vectorOne.cbegin() + 5);
	PrintVector(vectorOne);

	vectorTwo.clear();
	vectorTwo.insert(vectorTwo.cbegin(), 10, 100);
	vectorTwo.pop_back();

	//vectorTwo.emplace_back


}



