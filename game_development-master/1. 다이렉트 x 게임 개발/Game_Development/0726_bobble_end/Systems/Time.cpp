#include "stdafx.h"
#include "Time.h"

Time::Time()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&tick);
	QueryPerformanceCounter((LARGE_INTEGER *)&start);

	last = 0; //������ �ð�
}

Time::~Time()
{

}

void Time::Update()
{
	__int64 current; //���� �ð�
	QueryPerformanceCounter((LARGE_INTEGER *)&current); //���� �ð� ���� CPU Ŭ�� ��

	elapsed = current - last; //����ð� = ���� �ð� - ������ �ð�
	last = current; //������ �ð��� ���� �ð��� ���� ����
}

float Time::Running()
{
	__int64 current; //���� �ð�
	QueryPerformanceCounter((LARGE_INTEGER *)&current); 

	return (float)((double)(current - start) / tick); // (current - start = ��� �ð�)/ ����ð� ������ ƽ ��
}

float Time::Elapsed() //elapsed: ���
{
	return (float)elapsed / tick; // ����ð� ������ ƽ ��
}