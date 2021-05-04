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
	//printf("큰따옴표 : \"\"\n");
	//printf("역슬래시 : \\ \n");
	//
	//printf("%d", 3 + 5);
	//printf("%d %d", 3 + 5, 8);
	//printf("%x ", 3 + 5);
	//printf("%o", 3 + 5);

	//printf("%d 더하기 %d 는 %i 입니다.\n", 3, 5, 3 + 5);

	//printf("%d - %d = %d입니다.\n", 3, 5, 3 - 5);

	//printf("10진수 : %d 는 16진수 : %x, 8진수 : %o입니다. \n", 50, 50, 50);

	//Variable - 변수

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
	 //bool 참/거짓  0 == 거짓(false), 1 == 참(true); 

	//printf("char size : %d\n", sizeof(char));
	//printf("signed char size : %d\n", sizeof(signed char));
	//printf("unsigned char size : %d\n", sizeof(unsigned char));

	//printf("char형의 범위 : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	//printf("unsigned char형의 범위 : %d ~ %d\n", 0, UCHAR_MAX);


	//int age;
	//printf("What is your age? : ");
	//scanf("%d", &age);
	//printf("Wow! Really? Are you %d years old? \n", age);

	//cin >> age;

	//리터럴 상수 const 상수

	//십진수 리터럴 : 123
	//8진수 리터럴 : 0173
	//16진수 리터럴 : 0x7B
	//이진수 리터럴 : 0b1111011
	//부동소수점 : 3.14f
	//문자 하나 : 'a';

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
	printf("결과 : %f \n", result);

	result = (double)num1 / num2;
	printf("결과 : %f \n", result);

	result = num1 / (double)num2;
	printf("결과 : %f \n", result);

	result = (double)num1 / (double)num2;
	printf("결과 : %f \n", result);

	char ascii = 97;

	cout << ascii << endl;
	
	int ascii2 = 'A';

	cout << ascii2 << endl;


	return 0;
}