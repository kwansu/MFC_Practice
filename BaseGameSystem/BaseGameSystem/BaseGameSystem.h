
// BaseGameSystem.h : BaseGameSystem ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CBaseGameSystemApp:
// �� Ŭ������ ������ ���ؼ��� BaseGameSystem.cpp�� �����Ͻʽÿ�.
//

class CBaseGameSystemApp : public CWinApp
{
public:
	CBaseGameSystemApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBaseGameSystemApp theApp;
