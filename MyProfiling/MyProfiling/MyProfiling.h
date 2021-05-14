#pragma once
#include <Windows.h>


//���� �Ļ�Ŭ������ �����, ShowCheckNode�� �������ؼ� ���.
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

	//��ϵ� �ð����� Ȯ���ϱ� ���� �Լ�.
	virtual void ShowCheckNode() = 0;
};

