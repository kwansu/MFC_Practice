
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView : public CScrollView
{
	DECLARE_DYNCREATE(CChildView)
// �����Դϴ�.
protected:
	CChildView();
	virtual ~CChildView();

// Ư���Դϴ�.
public:
	CachedBitmap*	m_pCachedBmp;
	Bitmap*			m_pBmp;
	Bitmap*			m_pBmpBkgnd;
	CImage			m_CImage;
	UINT			m_iCodeTime;
	CString			m_strMessage;
	HBITMAP			m_hBmp;

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

