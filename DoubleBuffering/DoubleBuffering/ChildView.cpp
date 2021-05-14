
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "DoubleBuffering.h"
#include "ChildView.h"

#include "CBufferDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
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
	CBufferDC dc(this);

	dc.Rectangle(100, 100, 200, 200);

	dc.SelectStockObject(GRAY_BRUSH);

	CRect rcEll;
	rcEll.SetRect(m_ptMouse, m_ptMouse);
	rcEll.InflateRect(50, 50);

	dc.Ellipse(&rcEll);
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
//	InvalidateRect(NULL, FALSE);
	RedrawWindow();
	
	CWnd::OnMouseMove(nFlags, point);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
	
//	return CWnd::OnEraseBkgnd(pDC);
}
