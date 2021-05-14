#pragma once
#include <Windows.h>

//코드의 걸리는 시간을 확인하기 위한 클래스.
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

	//생성자로부터 다시 함수 설정전까지의 시간을 리턴함.
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

