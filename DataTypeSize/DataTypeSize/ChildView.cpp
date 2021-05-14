
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "DataTypeSize.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_str = _T("");
	m_len = 24;

	m_pData = new DataType[m_len];

	int i = 0;

	m_pData[i].SetData<int>(_T("int")); i++;
	m_pData[i].SetData<char>(_T("char")); i++;
	m_pData[i].SetData<short>(_T("short")); i++;
	m_pData[i].SetData<long>(_T("long")); i++;
	m_pData[i].SetData<bool>(_T("bool")); i++;
	m_pData[i].SetData<float>(_T("float")); i++;
	m_pData[i].SetData<double>(_T("double")); i++;
	m_pData[i].SetData<unsigned>(_T("unsigned")); i++;
	m_pData[i].SetData<CString>(_T("CString")); i++;
	m_pData[i].SetData<int*>(_T("pointer")); i++;
	m_pData[i].SetData<TCHAR>(_T("TCHAR")); i++;
	m_pData[i].SetData<WCHAR>(_T("WCHAR")); i++;
	m_pData[i].SetData<HANDLE>(_T("HANDLE")); i++;
	m_pData[i].SetData<UINT>(_T("UINT")); i++;
	m_pData[i].SetData<WORD>(_T("WORD")); i++;
	m_pData[i].SetData<DWORD>(_T("DWORD")); i++;
	m_pData[i].SetData<LONG>(_T("LONG")); i++;
	m_pData[i].SetData<LONG_PTR>(_T("LONG_PTR")); i++;
	m_pData[i].SetData<SHORT>(_T("SHORT")); i++;
	m_pData[i].SetData<FLOAT>(_T("FLOAT")); i++;
	m_pData[i].SetData<DOUBLE>(_T("DOUBLE")); i++;
	m_pData[i].SetData<BOOL>(_T("BOOL")); i++;
	m_pData[i].SetData<BOOLEAN>(_T("BOOLEAN")); i++;
	m_pData[i].SetData<LPVOID>(_T("LPVOID")); i++;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	for (int i = 0; i < m_len; i++)
	{
		m_str.Format(_T("%s size"), m_pData[i].name);
		dc.TextOut(100, 50 + 25 * i, m_str);

		dc.MoveTo(95, 70 + 25 * i);
		dc.LineTo(300, 70 + 25 * i);

		m_str.Format(_T("=   %d byte"), m_pData[i].size);
		dc.TextOut(230, 50 + 25 * i, m_str);
	}
}

