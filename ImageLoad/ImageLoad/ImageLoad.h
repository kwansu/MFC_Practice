
// ImageLoad.h : ImageLoad ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CImageLoadApp:
// �� Ŭ������ ������ ���ؼ��� ImageLoad.cpp�� �����Ͻʽÿ�.
//

class CImageLoadApp : public CWinApp
{
public:
	CImageLoadApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImageLoadApp theApp;
