
// GDIPlusTem.h : GDIPlusTem ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CGDIPlusTemApp:
// �� Ŭ������ ������ ���ؼ��� GDIPlusTem.cpp�� �����Ͻʽÿ�.
//

class CGDIPlusTemApp : public CWinAppEx
{
public:
	CGDIPlusTemApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGDIPlusTemApp theApp;
