#include <iostream>
#include <Windows.h>
using namespace std;


void main()
{
	LARGE_INTEGER startTime, endTime;
	LARGE_INTEGER allTime, forTime, asmTime;
	unsigned i;
	const unsigned counter = 100000000;
	int data = 99999;

	//all code time measure.
	QueryPerformanceCounter(&startTime);
	
	for (i = 0; i < counter; ++i)
	{
		data /= 3;
	}

	QueryPerformanceCounter(&endTime);
	allTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
	cout << "all\tcode\t=\t" << allTime.QuadPart << endl << endl;


	//for code time measure.
	QueryPerformanceCounter(&startTime);

	for (i = 0; i < counter; ++i)
	{
	}

	QueryPerformanceCounter(&endTime);
	forTime.QuadPart = endTime.QuadPart - startTime.QuadPart;
	cout << "for\tcode\t=\t" << forTime.QuadPart << endl << endl;

	cout << "all-for code\t=\t" << allTime.QuadPart - forTime.QuadPart << endl << endl;


	//asm code time measure.
	asmTime.QuadPart = 0;

	for (i = 0; i < counter; ++i)
	{
		QueryPerformanceCounter(&startTime);

		data /= 3;

		QueryPerformanceCounter(&endTime);
		asmTime.QuadPart += endTime.QuadPart - startTime.QuadPart;
	}

	cout << "asm\tcode\t=\t" << asmTime.QuadPart << endl << endl;
}