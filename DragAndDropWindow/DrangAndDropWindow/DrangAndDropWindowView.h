
// DrangAndDropWindowView.h : CDrangAndDropWindowView Ŭ������ �������̽�
//

#pragma once


class CDrangAndDropWindowView : public CView
{
protected: // serialization������ ��������ϴ�.
	CDrangAndDropWindowView();
	DECLARE_DYNCREATE(CDrangAndDropWindowView)

// Ư���Դϴ�.
public:
	CDrangAndDropWindowDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	CFrameWnd* m_pFrameWnd;
	CRect m_rtFrameWnd;
	CPoint m_ptMousePos;

	BOOL m_bDragFlag;

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
	virtual ~CDrangAndDropWindowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // DrangAndDropWindowView.cpp�� ����� ����
inline CDrangAndDropWindowDoc* CDrangAndDropWindowView::GetDocument() const
   { return reinterpret_cast<CDrangAndDropWindowDoc*>(m_pDocument); }
#endif

