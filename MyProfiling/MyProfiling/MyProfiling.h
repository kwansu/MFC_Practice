#pragma once
#include <Windows.h>


//사용시 파생클래스를 만든뒤, ShowCheckNode를 재정의해서 사용.
class CMyProfiling
{
protected:
	struct CheckNode
	{
		LARGE_INTEGER tInsert, tInEnd, tInResult;
		LPTSTR strName;
		inline void SetTime()
		{
			tInResult.QuadPart = tInEnd.QuadPart - tInsert.QuadPart;
		}
	};
	CheckNode	m_checkNode[10];
	LARGE_INTEGER m_tFreq;

public:

	CMyProfiling()
	{
		QueryPerformanceFrequency(&m_tFreq);
	}

	~CMyProfiling()
	{
	}

	void SetCheckNodeName(int index, LPTSTR str)
	{
		m_checkNode[index].strName = str;
	}

	void StartCheckNode(int index)
	{
		QueryPerformanceCounter(&m_checkNode[index].tInsert);
	}

	void EndCheckNode(int index)
	{
		QueryPerformanceCounter(&m_checkNode[index].tInEnd);
		m_checkNode[index].SetTime();
	}

	//기록된 시간들을 확인하기 위한 함수.
	virtual void ShowCheckNode() = 0;
};

