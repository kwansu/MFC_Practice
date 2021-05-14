
// GDIPlusTemView.cpp : CGDIPlusTemView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "GDIPlusTem.h"
#endif

#include "GDIPlusTemDoc.h"
#include "GDIPlusTemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIPlusTemView

IMPLEMENT_DYNCREATE(CGDIPlusTemView, CView)

BEGIN_MESSAGE_MAP(CGDIPlusTemView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGDIPlusTemView ����/�Ҹ�

CGDIPlusTemView::CGDIPlusTemView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CGDIPlusTemView::~CGDIPlusTemView()
{
}

BOOL CGDIPlusTemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CGDIPlusTemView �׸���

void CGDIPlusTemView::OnDraw(CDC* /*pDC*/)
{
	CGDIPlusTemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CGDIPlusTemView �μ�

BOOL CGDIPlusTemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CGDIPlusTemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CGDIPlusTemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CGDIPlusTemView ����

#ifdef _DEBUG
void CGDIPlusTemView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIPlusTemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIPlusTemDoc* CGDIPlusTemView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusTemDoc)));
	return (CGDIPlusTemDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIPlusTemView �޽��� ó����


void CGDIPlusTemView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);

	Pen MyPen(Color(128, 255, 0, 0), 10.0f);

	graphics.DrawEllipse(&MyPen, 100, 100, 400, 500);
}
