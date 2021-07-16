#include "stdafx.h"
#include "Time.h"

Time::Time()
{
	//__int64 tick: 64��Ʈ ���� (C/C++ ǥ���� �ƴ϶� ����2�� �־��ذ���)

	QueryPerformanceFrequency((LARGE_INTEGER *)&tick); //Ÿ�̸��� ���ļ��� ����
	QueryPerformanceCounter((LARGE_INTEGER *)&start); //���� ������ CPU Ŭ�� ��

	last = 0;
}

Time::~Time()
{

}

void Time::Update()
{
	__int64 current; //���� �ð�
	QueryPerformanceCounter((LARGE_INTEGER *)&current); //���� ������ CPU Ŭ�� ��

	elapsed = current - last; //��� �ð� = ���� �ð� - ������ �ð�
	last = current; //������ �ð��� ����� ������
}

float Time::Running()
{
	__int64 current; //���� �ð�
	QueryPerformanceCounter((LARGE_INTEGER *)&current); //���� ������ CPU Ŭ�� ��

	return (float)((double)(current - start) / tick); //�ð� ������ ���ϴ� ����
}

float Time::Elapsed()
{
	return (float)elapsed / tick; //�ð� ������ ���ϴ� ����
}