
// CodeTimeCheckView.cpp : CCodeTimeCheckView 클래스의 구현
//

#include "stdafx.h"
#include "CBufferDC.h"

// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CodeTimeCheck.h"
#endif

#include "CodeTimeCheckDoc.h"
#include "CodeTimeCheckView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCodeTimeCheckView

IMPLEMENT_DYNCREATE(CCodeTimeCheckView, CView)

BEGIN_MESSAGE_MAP(CCodeTimeCheckView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CCodeTimeCheckView 생성/소멸

CCodeTimeCheckView::CCodeTimeCheckView()
{
	m_Cimage.Load(_T("img1.jpg"));
	m_pImage = Image::FromFile(_T("img1.jpg"));

}

CCodeTimeCheckView::~CCodeTimeCheckView()
{
}

BOOL CCodeTimeCheckView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCodeTimeCheckView 그리기

void CCodeTimeCheckView::OnDraw(CDC* /*pDC*/)
{
	CCodeTimeCheckDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCodeTimeCheckView 인쇄

BOOL CCodeTimeCheckView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCodeTimeCheckView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCodeTimeCheckView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCodeTimeCheckView 진단

#ifdef _DEBUG
void CCodeTimeCheckView::AssertValid() const
{
	CView::AssertValid();
}

void CCodeTimeCheckView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCodeTimeCheckDoc* CCodeTimeCheckView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCodeTimeCheckDoc)));
	return (CCodeTimeCheckDoc*)m_pDocument;
}
#endif //_DEBUG


// CCodeTimeCheckView 메시지 처리기


void CCodeTimeCheckView::OnPaint()
{
	CTimeCheck codeTimer;
	codeTimer.ResetTime();

	CBufferDC dc(this);

	m_Cimage.BitBlt(dc.m_hDC, 0, 0);
	
	runTime = codeTimer.GetRunTime();
}


void CCodeTimeCheckView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CString str;
	
	str.Format(_T("걸린시간 : %d"), runTime);
	AfxMessageBox(str);

	CView::OnLButtonDown(nFlags, point);
}


BOOL CCodeTimeCheckView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;

	//return CView::OnEraseBkgnd(pDC);
}
