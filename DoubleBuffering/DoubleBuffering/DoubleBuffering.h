
// DoubleBuffering.h : DoubleBuffering ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDoubleBufferingApp:
// �� Ŭ������ ������ ���ؼ��� DoubleBuffering.cpp�� �����Ͻʽÿ�.
//

class CDoubleBufferingApp : public CWinApp
{
public:
	CDoubleBufferingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDoubleBufferingApp theApp;
