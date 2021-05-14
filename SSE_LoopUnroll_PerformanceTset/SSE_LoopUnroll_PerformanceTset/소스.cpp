#include <iostream>
#include <Windows.h>
using namespace std;

#define _T(str)	(#str)
#define arr_size 1000000

void main()
{
	int* arrA;
	arrA = new int[arr_size];

	int i;
	for (i = 0; i < arr_size; ++i)
	{
		arrA[i] = i & 0x0000000f;
	}

	LARGE_INTEGER startTime, stopTime;

	cout << _T(--------initialize success.--------) << endl << endl;

	int nResult = 0;
	int arrResult[4] = { 0 };


	//그냥 for로 성능측정
	cout << _T(--------general performance--------) << endl;
	QueryPerformanceCounter(&startTime);
	for (i = 0; i < arr_size; ++i)
		nResult += arrA[i];

	QueryPerformanceCounter(&stopTime);

	cout << _T(result\t = \t) << nResult << endl;
	cout << _T(performance\t = \t) << stopTime.QuadPart - startTime.QuadPart << endl;

	cout << endl;


	nResult = 0;

	//SSE사용시 성능측정
	cout << _T(--------SSE performance--------) << endl;
	QueryPerformanceCounter(&startTime);
	
	__asm
	{
		pushad;

		mov	eax, arrA;
		mov	ebx, 32;
		mov ecx, arr_size*4 + 32;

		pxor xmm0, xmm0;
		pxor xmm1, xmm1;
		pxor xmm2, xmm2;
		pxor xmm3, xmm3;
		

	ADDLOOP:
		movdqu	xmm1, [eax + ebx - 32];
		paddd	xmm0, xmm1;
		movdqu	xmm2, [eax + ebx - 16];
		paddd	xmm0, xmm2;
		movdqu	xmm3, [eax + ebx];
		paddd	xmm0, xmm3;

		add	ebx, 32;
		cmp ebx, ecx;
		jne	ADDLOOP;

		movdqu	arrResult, xmm0;

		popad;
	}

	nResult += arrResult[0];
	nResult += arrResult[1];
	nResult += arrResult[2];
	nResult += arrResult[3];

	QueryPerformanceCounter(&stopTime);

	cout << _T(result\t = \t) << nResult << endl;
	cout << _T(performance\t = \t) << stopTime.QuadPart - startTime.QuadPart << endl;
	cout << endl;

	
	nResult = 0;

	//Loop_unroll사용시 성능측정.
	cout << _T(--------LoopUnroll performance--------) << endl;
	QueryPerformanceCounter(&startTime);
	for (i = 0; i < arr_size; i += 8)
	{
		nResult += arrA[i];
		nResult += arrA[i+1];
		nResult += arrA[i+2];
		nResult += arrA[i+3];
		nResult += arrA[i+4];
		nResult += arrA[i+5];
		nResult += arrA[i+6];
		nResult += arrA[i+7];
	}

	QueryPerformanceCounter(&stopTime);

	cout << _T(result\t = \t) << nResult << endl;
	cout << _T(performance\t = \t) << stopTime.QuadPart - startTime.QuadPart << endl;
	cout << endl;


	int* arrB;
	arrB = new _declspec(align(32))int[arr_size];


	for (i = 0; i < arr_size; ++i)
	{
		arrB[i] = i & 0x0000000f;
	}

	_declspec(align(32)) int anResult[4];

	nResult = 0;

	//정렬된 배열로 SSE사용시 성능측정.
	cout << _T(--------Aligned SSE performance--------) << endl;
	QueryPerformanceCounter(&startTime);

	__asm
	{
		pushad;

		mov	eax, arrB;
		mov	ebx, 0;
		mov ecx, arr_size*4;

		pxor xmm0, xmm0;

	ADLOOP:
		movdqa	xmm1, [eax + ebx];
		paddd	xmm0, xmm1;

		add	ebx, 16;
		cmp ebx, ecx;
		jne	ADLOOP;

		movdqa	anResult, xmm0;

		popad;
	}

	nResult += anResult[0];
	nResult += anResult[1];
	nResult += anResult[2];
	nResult += anResult[3];

	QueryPerformanceCounter(&stopTime);

	cout << _T(result\t = \t) << nResult << endl;
	cout << _T(performance\t = \t) << stopTime.QuadPart - startTime.QuadPart << endl;
	cout << endl;
}