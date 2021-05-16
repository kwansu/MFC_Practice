
// ImageLoadView.h : CImageLoadView Ŭ������ �������̽�
//

#pragma once

#include <atlimage.h>

class CImageLoadView : public CView
{
protected: // serialization������ ��������ϴ�.
	CImageLoadView();
	DECLARE_DYNCREATE(CImageLoadView)

// Ư���Դϴ�.
public:
	CImageLoadDoc* GetDocument() const;

	CImage m_image_bkg;
	CBrush m_brush_alpha;
	CRect m_rtAlphaLocation;
	BOOL m_bAlphaFlag;
	CPoint m_ptMouse;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CImageLoadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // ImageLoadView.cpp�� ����� ����
inline CImageLoadDoc* CImageLoadView::GetDocument() const
   { return reinterpret_cast<CImageLoadDoc*>(m_pDocument); }
#endif

