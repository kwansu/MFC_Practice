
#pragma once

#include <Windows.h>

class CStopWatch
{
public:
	LARGE_INTEGER m_inFreq, m_inSert, m_inEnd;
	LONGLONG m_llResult;

public:
	CStopWatch()
	{
		QueryPerformanceFrequency(&m_inFreq);
		QueryPerformanceCounter(&m_inSert);
	}

	~CStopWatch()
	{
	}

	inline void ResetTime()
	{
		QueryPerformanceCounter(&m_inSert);
	}

	inline LONGLONG GetTime()
	{
		QueryPerformanceCounter(&m_inEnd);

		return (m_inEnd.QuadPart - m_inSert.QuadPart)
			* 100000 / m_inFreq.QuadPart;
	}
};

