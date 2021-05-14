#pragma once
#include <Windows.h>

class CPerformanceTest
{
private:
	LARGE_INTEGER	m_measurementTime;
	LARGE_INTEGER	m_resultTime;
	unsigned	m_counter;

public:
	CPerformanceTest() : m_counter(10000000) {}
	~CPerformanceTest() {}

	void SetCounter(unsigned counter) { m_counter = counter; }
	LARGE_INTEGER PerformanceTest()
	{

	}
};

