
// DrangAndDropWindow.h : DrangAndDropWindow ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrangAndDropWindowApp:
// �� Ŭ������ ������ ���ؼ��� DrangAndDropWindow.cpp�� �����Ͻʽÿ�.
//

class CDrangAndDropWindowApp : public CWinApp
{
public:
	CDrangAndDropWindowApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrangAndDropWindowApp theApp;
