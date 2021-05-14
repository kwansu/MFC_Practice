
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "ScrollWindow.h"
#include "ChildView.h"

#include "TimeCheck.h"
#include "CBufferDC.h"

IMPLEMENT_DYNCREATE(CChildView, CScrollView)

// CChildView

CChildView::CChildView()
:m_pBmp(NULL), m_iCodeTime(0), m_pCachedBmp(NULL)
{
	CSize sizeTotal;
	
	sizeTotal.cx = sizeTotal.cy = 10000;
	SetScrollSizes(MM_TEXT, sizeTotal);

	m_CImage.Load(_T("img1.jpg"));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CScrollView)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_LBUTTONUP()
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
	CTimeCheck timeCheck;
	timeCheck.ResetTime();

	int iVScrollPos = GetScrollPos(SB_VERT);
	int iHScrollPos = GetScrollPos(SB_HORZ);

	CRect rc;

	GetClientRect(&rc);

	CPaintDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC(&dc);

	HBITMAP hOldBmp = (HBITMAP)SelectObject(memDC.m_hDC, m_hBmp);

	dc.BitBlt(-iHScrollPos, -iVScrollPos, rc.right, rc.bottom, &memDC, 0, 0, SRCCOPY);

	SelectObject(memDC.m_hDC, hOldBmp);
	/*
	CBrush brush;
	brush.CreateStockObject(GRAY_BRUSH);

	dc.FillRect(&rc, &brush);

	m_CImage.BitBlt(dc.m_hDC, -iHScrollPos, -iVScrollPos);*/

	/*CPaintDC dc(this);
	
	Graphics grp(dc);
	
	if (!m_pCachedBmp)
	{
		m_pCachedBmp = new CachedBitmap(m_pBmpBkgnd, &grp);
		RedrawWindow();
	}
	else
		grp.DrawCachedBitmap(m_pCachedBmp, -iHScrollPos, -iVScrollPos);*/

	m_iCodeTime = timeCheck.GetRunTime();
}



void CChildView::OnDraw(CDC* /*pDC*/)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	//return FALSE;

	return CScrollView::OnEraseBkgnd(pDC);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pBmp = new Bitmap(_T("img1.jpg"));
	if (!m_pBmp)
	{
		AfxMessageBox(_T("image loading failed!"));
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}

	m_pBmpBkgnd = new Bitmap(10000, 10000);

	Graphics memGrp(m_pBmpBkgnd);

	SolidBrush brush_Green(Color(0, 128, 0));

	memGrp.FillRectangle(&brush_Green, 0, 0, 10000, 10000);

	memGrp.DrawImage(m_pBmp, 0, 0);

	m_pBmp->GetHBITMAP(Color(128, 128, 128), &m_hBmp);

	return 0;
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_strMessage.Format(_T("Code Time : %d"), m_iCodeTime);
	AfxMessageBox(m_strMessage);

	CScrollView::OnLButtonUp(nFlags, point);
}