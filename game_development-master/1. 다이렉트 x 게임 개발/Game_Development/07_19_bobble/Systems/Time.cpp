#include "stdafx.h"
#include "Time.h"

Time::Time()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&tick);
	//타이머의 주파수를 알 수 있다.
	QueryPerformanceCounter((LARGE_INTEGER *)&start);
	//시작 시점의 CPU 클릭 수
	//LARGE_INTEGER: 크기가 큰 정수형 데이터를 저장하기 위해 선언된 자료형
	last = 0;
}

Time::~Time()
{

}

void Time::Update()
{
	__int64 current;
	//현재 시간
	QueryPerformanceCounter((LARGE_INTEGER *)&current);
	//현재시간 갱신
	elapsed = current - last;
	//걸린 시간 
	last = current;
	//마지막시간에 현재시간 대입
}

float Time::Running()
{
	__int64 current;
	QueryPerformanceCounter((LARGE_INTEGER *)&current);
	//현재시간 갱신
	return (float)((double)(current - start) / tick);
	//현재시간에서 시작시간을 틱으로 나눈 값
}

float Time::Elapsed()
{
	return (float)elapsed / tick;
}