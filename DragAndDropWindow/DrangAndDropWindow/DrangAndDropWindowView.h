
// DrangAndDropWindowView.h : CDrangAndDropWindowView 클래스의 인터페이스
//

#pragma once


class CDrangAndDropWindowView : public CView
{
protected: // serialization에서만 만들어집니다.
	CDrangAndDropWindowView();
	DECLARE_DYNCREATE(CDrangAndDropWindowView)

// 특성입니다.
public:
	CDrangAndDropWindowDoc* GetDocument() const;

// 작업입니다.
public:
	CFrameWnd* m_pFrameWnd;
	CRect m_rtFrameWnd;
	CPoint m_ptMousePos;

	BOOL m_bDragFlag;

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
	virtual ~CDrangAndDropWindowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // DrangAndDropWindowView.cpp의 디버그 버전
inline CDrangAndDropWindowDoc* CDrangAndDropWindowView::GetDocument() const
   { return reinterpret_cast<CDrangAndDropWindowDoc*>(m_pDocument); }
#endif

