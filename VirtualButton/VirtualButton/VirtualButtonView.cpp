
// VirtualButtonView.cpp : CVirtualButtonView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "VirtualButton.h"
#endif

#include "VirtualButtonDoc.h"
#include "VirtualButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVirtualButtonView

IMPLEMENT_DYNCREATE(CVirtualButtonView, CView)

BEGIN_MESSAGE_MAP(CVirtualButtonView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CVirtualButtonView 생성/소멸

CVirtualButtonView::CVirtualButtonView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_vbButton1.m_rtButtonSize = CRect(100, 100, 200, 200);
}

CVirtualButtonView::~CVirtualButtonView()
{
}

BOOL CVirtualButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CVirtualButtonView 그리기

void CVirtualButtonView::OnDraw(CDC* /*pDC*/)
{
	CVirtualButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CVirtualButtonView 인쇄

BOOL CVirtualButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CVirtualButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CVirtualButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CVirtualButtonView 진단

#ifdef _DEBUG
void CVirtualButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CVirtualButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVirtualButtonDoc* CVirtualButtonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualButtonDoc)));
	return (CVirtualButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CVirtualButtonView 메시지 처리기


void CVirtualButtonView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CRect rtBtFrame(m_vbButton1.m_rtButtonSize);
	rtBtFrame.InflateRect(1, 1);

	dc.Rectangle(&rtBtFrame);
	dc.FillSolidRect(&m_vbButton1.m_rtButtonSize, ::GetSysColor(COLOR_BTNFACE));

	if (m_vbButton1.m_bClick)
	{
		dc.FillSolidRect(&m_vbButton1.m_rtButtonSize, ::GetSysColor(COLOR_HIGHLIGHT));
		dc.Draw3dRect(m_vbButton1.m_rtButtonSize
			,::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DLIGHT));
	}
	else if (m_vbButton1.m_bActive)
	{
		dc.FillSolidRect(&m_vbButton1.m_rtButtonSize, ::GetSysColor(COLOR_HIGHLIGHT));
		dc.Draw3dRect(m_vbButton1.m_rtButtonSize
			, ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}
}


void CVirtualButtonView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptMouse = point;

	if (m_vbButton1.m_rtButtonSize.PtInRect(point))
		m_vbButton1.m_bActive = TRUE;
	else
		m_vbButton1.m_bActive = FALSE;

	RedrawWindow();

	CView::OnMouseMove(nFlags, point);
}


void CVirtualButtonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_vbButton1.m_rtButtonSize.PtInRect(point))
		m_vbButton1.m_bClick = TRUE;

	RedrawWindow();

	CView::OnLButtonDown(nFlags, point);
}


void CVirtualButtonView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_vbButton1.m_bClick = FALSE;

	RedrawWindow();

	CView::OnLButtonUp(nFlags, point);
}
