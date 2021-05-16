
// ImageLoadView.cpp : CImageLoadView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CImageLoadView ����/�Ҹ�

CImageLoadView::CImageLoadView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_bAlphaFlag = FALSE;
	m_rtAlphaLocation.SetRectEmpty();
}

CImageLoadView::~CImageLoadView()
{
}

BOOL CImageLoadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CImageLoadView �׸���

void CImageLoadView::OnDraw(CDC* /*pDC*/)
{
	CImageLoadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CImageLoadView �μ�

BOOL CImageLoadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CImageLoadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CImageLoadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CImageLoadView ����

#ifdef _DEBUG
void CImageLoadView::AssertValid() const
{
	CView::AssertValid();
}

void CImageLoadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageLoadDoc* CImageLoadView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageLoadDoc)));
	return (CImageLoadDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageLoadView �޽��� ó����


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
		AfxMessageBox(_T("�̹��� �ε忡 �����߽��ϴ�."));
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return TRUE;

	//return CView::OnEraseBkgnd(pDC);
}
