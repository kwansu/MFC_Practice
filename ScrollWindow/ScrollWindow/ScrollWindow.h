
// ScrollWindow.h : ScrollWindow ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CScrollWindowApp:
// �� Ŭ������ ������ ���ؼ��� ScrollWindow.cpp�� �����Ͻʽÿ�.
//

class CScrollWindowApp : public CWinApp
{
public:
	CScrollWindowApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CScrollWindowApp theApp;
