
// DrangAndDropWindowView.cpp : CDrangAndDropWindowView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DrangAndDropWindow.h"
#endif

#include "DrangAndDropWindowDoc.h"
#include "DrangAndDropWindowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrangAndDropWindowView

IMPLEMENT_DYNCREATE(CDrangAndDropWindowView, CView)

BEGIN_MESSAGE_MAP(CDrangAndDropWindowView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCHITTEST()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDrangAndDropWindowView ����/�Ҹ�

CDrangAndDropWindowView::CDrangAndDropWindowView()
{

}

CDrangAndDropWindowView::~CDrangAndDropWindowView()
{
}

BOOL CDrangAndDropWindowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CDrangAndDropWindowView �׸���

void CDrangAndDropWindowView::OnDraw(CDC* /*pDC*/)
{
	CDrangAndDropWindowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CDrangAndDropWindowView �μ�

BOOL CDrangAndDropWindowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CDrangAndDropWindowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CDrangAndDropWindowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CDrangAndDropWindowView ����

#ifdef _DEBUG
void CDrangAndDropWindowView::AssertValid() const
{
	CView::AssertValid();
}

void CDrangAndDropWindowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrangAndDropWindowDoc* CDrangAndDropWindowView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrangAndDropWindowDoc)));
	return (CDrangAndDropWindowDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrangAndDropWindowView �޽��� ó����


void CDrangAndDropWindowView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDragFlag)
	{
		ClientToScreen(&point);
		CPoint ptNewPos = point + m_ptMousePos;
		
		CString str;
		str.Format(_T("%d, %d"), ptNewPos.x, ptNewPos.y);
		m_pFrameWnd->SetWindowText(str);

		m_pFrameWnd->SetWindowPos(&CWnd::wndTop, ptNewPos.x
			, ptNewPos.y, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER);
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrangAndDropWindowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);

	m_pFrameWnd->GetWindowRect(&m_rtFrameWnd);
	m_ptMousePos = CPoint(m_rtFrameWnd.left, m_rtFrameWnd.top) - point;

	m_bDragFlag = TRUE;

	CView::OnLButtonDown(nFlags, point);
}


void CDrangAndDropWindowView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDragFlag)
		m_bDragFlag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}


LRESULT CDrangAndDropWindowView::OnNcHitTest(CPoint point)
{

	return CView::OnNcHitTest(point);
}


int CDrangAndDropWindowView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pFrameWnd = AFXGetParentFrame(this);
	m_bDragFlag = FALSE;

	return 0;
}
