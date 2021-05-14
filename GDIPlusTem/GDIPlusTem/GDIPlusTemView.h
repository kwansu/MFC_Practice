
// GDIPlusTemView.h : CGDIPlusTemView Ŭ������ �������̽�
//

#pragma once


class CGDIPlusTemView : public CView
{
protected: // serialization������ ��������ϴ�.
	CGDIPlusTemView();
	DECLARE_DYNCREATE(CGDIPlusTemView)

// Ư���Դϴ�.
public:
	CGDIPlusTemDoc* GetDocument() const;

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
	virtual ~CGDIPlusTemView();
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
};

#ifndef _DEBUG  // GDIPlusTemView.cpp�� ����� ����
inline CGDIPlusTemDoc* CGDIPlusTemView::GetDocument() const
   { return reinterpret_cast<CGDIPlusTemDoc*>(m_pDocument); }
#endif

