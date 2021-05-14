
// ImageLoadView.cpp : CImageLoadView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageLoad.h"
#endif

#include "ImageLoadDoc.h"
#include "ImageLoadView.h"

#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageLoadView

IMPLEMENT_DYNCREATE(CImageLoadView, CView)

BEGIN_MESSAGE_MAP(CImageLoadView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CImageLoadView 생성/소멸

CImageLoadView::CImageLoadView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bAlphaFlag = FALSE;
	m_rtAlphaLocation.SetRectEmpty();
}

CImageLoadView::~CImageLoadView()
{
}

BOOL CImageLoadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageLoadView 그리기

void CImageLoadView::OnDraw(CDC* /*pDC*/)
{
	CImageLoadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CImageLoadView 인쇄

BOOL CImageLoadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageLoadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageLoadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageLoadView 진단

#ifdef _DEBUG
void CImageLoadView::AssertValid() const
{
	CView::AssertValid();
}

void CImageLoadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageLoadDoc* CImageLoadView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageLoadDoc)));
	return (CImageLoadDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageLoadView 메시지 처리기


void CImageLoadView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

//	CRect rtClient;
//	GetClientRect(rtClient);

	CImage image;

	image.Load(TEXT("C://img1.jpg"));

	if (m_bAlphaFlag)
	{
		CDC* pDC_image = CDC::FromHandle(image.GetDC());
		CDC memDC;

		memDC.CreateCompatibleDC(pDC_image);
		memDC.SetBkMode(TRANSPARENT);
		
		CBrush* pOldBrush = memDC.SelectObject(&m_brush_alpha);
		memDC.Ellipse(&m_rtAlphaLocation);
		memDC.SelectObject(pOldBrush);

		BLENDFUNCTION bf;
		bf.AlphaFormat = 0;
		bf.BlendFlags = 0;
		bf.BlendOp = AC_SRC_OVER;
		bf.SourceConstantAlpha = 255 / 2;

		pDC_image->AlphaBlend(0, 0, 1600, 1024, &memDC, 0, 0, 1600, 1024, bf);
		image.ReleaseDC();
	}

	image.BitBlt(dc.m_hDC, 0, 0);
}


int CImageLoadView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	HRESULT hResult = m_image_bkg.Load(TEXT("C://img1.jpg"));
	if (hResult == E_FAIL)
	{
		AfxMessageBox(_T("이미지 로드에 실패했습니다."));
		GetParent()->PostMessage(WM_CLOSE);
	}

	m_brush_alpha.CreateSolidBrush(RGB(255/2 , 255/2, 255/2));

	return 0;
}


void CImageLoadView::OnMouseMove(UINT nFlags, CPoint point)
{
//	m_ptMouse = point;
	m_rtAlphaLocation.SetRect(point, point);
	m_rtAlphaLocation.InflateRect(50, 50);
	InvalidateRect(NULL, FALSE);

	CView::OnMouseMove(nFlags, point);
}


void CImageLoadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bAlphaFlag)
		m_bAlphaFlag = FALSE;
	else
		m_bAlphaFlag = TRUE;

	InvalidateRect(NULL, FALSE);

	CView::OnLButtonDown(nFlags, point);
}


BOOL CImageLoadView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return TRUE;

	//return CView::OnEraseBkgnd(pDC);
}
