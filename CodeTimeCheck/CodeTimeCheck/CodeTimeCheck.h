
// CodeTimeCheck.h : CodeTimeCheck ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCodeTimeCheckApp:
// �� Ŭ������ ������ ���ؼ��� CodeTimeCheck.cpp�� �����Ͻʽÿ�.
//

class CCodeTimeCheckApp : public CWinAppEx
{
public:
	CCodeTimeCheckApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCodeTimeCheckApp theApp;
