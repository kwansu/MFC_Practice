
// CodeTimeCheckView.h : CCodeTimeCheckView Ŭ������ �������̽�
//

#pragma once


class CCodeTimeCheckView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCodeTimeCheckView();
	DECLARE_DYNCREATE(CCodeTimeCheckView)

// Ư���Դϴ�.
public:
	CCodeTimeCheckDoc* GetDocument() const;

	UINT runTime;
	CImage m_Cimage;
	Image* m_pImage;

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
	virtual ~CCodeTimeCheckView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // CodeTimeCheckView.cpp�� ����� ����
inline CCodeTimeCheckDoc* CCodeTimeCheckView::GetDocument() const
   { return reinterpret_cast<CCodeTimeCheckDoc*>(m_pDocument); }
#endif

