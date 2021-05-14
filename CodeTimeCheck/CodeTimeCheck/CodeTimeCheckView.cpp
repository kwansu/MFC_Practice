
// CodeTimeCheckView.cpp : CCodeTimeCheckView Ŭ������ ����
//

#include "stdafx.h"
#include "CBufferDC.h"

// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CCodeTimeCheckView ����/�Ҹ�

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCodeTimeCheckView �׸���

void CCodeTimeCheckView::OnDraw(CDC* /*pDC*/)
{
	CCodeTimeCheckDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCodeTimeCheckView �μ�

BOOL CCodeTimeCheckView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCodeTimeCheckView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCodeTimeCheckView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCodeTimeCheckView ����

#ifdef _DEBUG
void CCodeTimeCheckView::AssertValid() const
{
	CView::AssertValid();
}

void CCodeTimeCheckView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCodeTimeCheckDoc* CCodeTimeCheckView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCodeTimeCheckDoc)));
	return (CCodeTimeCheckDoc*)m_pDocument;
}
#endif //_DEBUG


// CCodeTimeCheckView �޽��� ó����


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
	
	str.Format(_T("�ɸ��ð� : %d"), runTime);
	AfxMessageBox(str);

	CView::OnLButtonDown(nFlags, point);
}


BOOL CCodeTimeCheckView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;

	//return CView::OnEraseBkgnd(pDC);
}
