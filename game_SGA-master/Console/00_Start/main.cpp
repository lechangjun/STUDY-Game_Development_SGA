#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

#define PI 3.141592

int main()
{
	//cout << "Hello World" << endl;

	//printf("Hello C World \n");
	//printf("\t Hello C! \n Hello World! \n");
	//printf("ū����ǥ : \"\"\n");
	//printf("�������� : \\ \n");
	//
	//printf("%d", 3 + 5);
	//printf("%d %d", 3 + 5, 8);
	//printf("%x ", 3 + 5);
	//printf("%o", 3 + 5);

	//printf("%d ���ϱ� %d �� %i �Դϴ�.\n", 3, 5, 3 + 5);

	//printf("%d - %d = %d�Դϴ�.\n", 3, 5, 3 - 5);

	//printf("10���� : %d �� 16���� : %x, 8���� : %o�Դϴ�. \n", 50, 50, 50);

	//Variable - ����

	//integer
	//char,short,int

	//RealNumber
	//float, double

	 //int a = 0;
	 //int b = 0;

	 //a = a + 10;
	 //b = b + 10;

	 //printf("%d", a);
	 //printf("%d", b);

	 //int width;
	 //width = 200;

	 //int height2;
	 //int he2ight;
	 //int _temp;
	 //int m_temp;
	 //int M_temp;
	 //int _;

	 //int appleCider;

	 //int m_number;

	 //boolean
	 //bool ��/����  0 == ����(false), 1 == ��(true); 

	//printf("char size : %d\n", sizeof(char));
	//printf("signed char size : %d\n", sizeof(signed char));
	//printf("unsigned char size : %d\n", sizeof(unsigned char));

	//printf("char���� ���� : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	//printf("unsigned char���� ���� : %d ~ %d\n", 0, UCHAR_MAX);


	//int age;
	//printf("What is your age? : ");
	//scanf("%d", &age);
	//printf("Wow! Really? Are you %d years old? \n", age);

	//cin >> age;

	//���ͷ� ��� const ���

	//������ ���ͷ� : 123
	//8���� ���ͷ� : 0173
	//16���� ���ͷ� : 0x7B
	//������ ���ͷ� : 0b1111011
	//�ε��Ҽ��� : 3.14f
	//���� �ϳ� : 'a';

	//int number1 = 23'456'789;
	//float number2 = 0.123'456f;

	//int temp = 10;

	//temp = temp + 5;
	//temp = 15;
	//
	//const int temp2 = 20;
	//const int temp3 = 30;

	//const int pi = 3.141592;

	//temp2 = temp2 + 10;

	//PI

	//char->int->float->double

	//int num1 = 100;
	//double num2 = 3.14;
	//printf("%f \n", num1 + num2);

	//char num1 = 97;
	//printf("%d", num1);

	//cout << num1;

	//int num2 = 3.14;

	//cout << num2;

	//double num3 = 3;

	//cout << num3;

	//int num1 = 2;
	//(double)num1;

	int num1 = 10;
	int num2 = 3;

	double result;

	result = num1 / num2;
	printf("��� : %f \n", result);

	result = (double)num1 / num2;
	printf("��� : %f \n", result);

	result = num1 / (double)num2;
	printf("��� : %f \n", result);

	result = (double)num1 / (double)num2;
	printf("��� : %f \n", result);

	char ascii = 97;

	cout << ascii << endl;
	
	int ascii2 = 'A';

	cout << ascii2 << endl;


	return 0;
}