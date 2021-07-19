#include "stdafx.h"
#include "Time.h"

Time::Time()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&tick);
	//Ÿ�̸��� ���ļ��� �� �� �ִ�.
	QueryPerformanceCounter((LARGE_INTEGER *)&start);
	//���� ������ CPU Ŭ�� ��
	//LARGE_INTEGER: ũ�Ⱑ ū ������ �����͸� �����ϱ� ���� ����� �ڷ���
	last = 0;
}

Time::~Time()
{

}

void Time::Update()
{
	__int64 current;
	//���� �ð�
	QueryPerformanceCounter((LARGE_INTEGER *)&current);
	//����ð� ����
	elapsed = current - last;
	//�ɸ� �ð� 
	last = current;
	//�������ð��� ����ð� ����
}

float Time::Running()
{
	__int64 current;
	QueryPerformanceCounter((LARGE_INTEGER *)&current);
	//����ð� ����
	return (float)((double)(current - start) / tick);
	//����ð����� ���۽ð��� ƽ���� ���� ��
}

float Time::Elapsed()
{
	return (float)elapsed / tick;
}