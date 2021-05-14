#pragma once
#include <Windows.h>

//�ڵ��� �ɸ��� �ð��� Ȯ���ϱ� ���� Ŭ����.
class CTimeCheck
{
private:
	LARGE_INTEGER InFreq, InSert, InEnd, InResult;

public:
	CTimeCheck()
	{
		QueryPerformanceFrequency(&InFreq);
		QueryPerformanceCounter(&InSert);
	}
	~CTimeCheck()
	{

	}

	//�����ڷκ��� �ٽ� �Լ� ������������ �ð��� ������.
	inline UINT ResetTime()
	{
		UINT result = GetRunTime();

		QueryPerformanceCounter(&InSert);

		return result;
	}
	
	inline UINT GetRunTime()
	{
		QueryPerformanceCounter(&InEnd);

		return InResult.QuadPart = (InEnd.QuadPart - InSert.QuadPart)
			* 1000000 / InFreq.QuadPart;
	}
};

