
// DrangAndDropWindowView.cpp : CDrangAndDropWindowView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_NCHITTEST()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDrangAndDropWindowView 생성/소멸

CDrangAndDropWindowView::CDrangAndDropWindowView()
{

}

CDrangAndDropWindowView::~CDrangAndDropWindowView()
{
}

BOOL CDrangAndDropWindowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDrangAndDropWindowView 그리기

void CDrangAndDropWindowView::OnDraw(CDC* /*pDC*/)
{
	CDrangAndDropWindowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDrangAndDropWindowView 인쇄

BOOL CDrangAndDropWindowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDrangAndDropWindowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDrangAndDropWindowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDrangAndDropWindowView 진단

#ifdef _DEBUG
void CDrangAndDropWindowView::AssertValid() const
{
	CView::AssertValid();
}

void CDrangAndDropWindowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrangAndDropWindowDoc* CDrangAndDropWindowView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrangAndDropWindowDoc)));
	return (CDrangAndDropWindowDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrangAndDropWindowView 메시지 처리기


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
