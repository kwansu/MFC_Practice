
// DataTypeSize.h : DataTypeSize ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDataTypeSizeApp:
// �� Ŭ������ ������ ���ؼ��� DataTypeSize.cpp�� �����Ͻʽÿ�.
//

class CDataTypeSizeApp : public CWinApp
{
public:
	CDataTypeSizeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDataTypeSizeApp theApp;
