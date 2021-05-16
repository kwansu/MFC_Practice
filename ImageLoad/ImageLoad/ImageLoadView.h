
// ImageLoadView.h : CImageLoadView 클래스의 인터페이스
//

#pragma once

#include <atlimage.h>

class CImageLoadView : public CView
{
protected: // serialization에서만 만들어집니다.
	CImageLoadView();
	DECLARE_DYNCREATE(CImageLoadView)

// 특성입니다.
public:
	CImageLoadDoc* GetDocument() const;

	CImage m_image_bkg;
	CBrush m_brush_alpha;
	CRect m_rtAlphaLocation;
	BOOL m_bAlphaFlag;
	CPoint m_ptMouse;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageLoadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // ImageLoadView.cpp의 디버그 버전
inline CImageLoadDoc* CImageLoadView::GetDocument() const
   { return reinterpret_cast<CImageLoadDoc*>(m_pDocument); }
#endif

