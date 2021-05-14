
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CScrollView
{
	DECLARE_DYNCREATE(CChildView)
// 생성입니다.
protected:
	CChildView();
	virtual ~CChildView();

// 특성입니다.
public:
	CachedBitmap*	m_pCachedBmp;
	Bitmap*			m_pBmp;
	Bitmap*			m_pBmpBkgnd;
	CImage			m_CImage;
	UINT			m_iCodeTime;
	CString			m_strMessage;
	HBITMAP			m_hBmp;

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

