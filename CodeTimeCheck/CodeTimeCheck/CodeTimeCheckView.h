
// CodeTimeCheckView.h : CCodeTimeCheckView 클래스의 인터페이스
//

#pragma once


class CCodeTimeCheckView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCodeTimeCheckView();
	DECLARE_DYNCREATE(CCodeTimeCheckView)

// 특성입니다.
public:
	CCodeTimeCheckDoc* GetDocument() const;

	UINT runTime;
	CImage m_Cimage;
	Image* m_pImage;

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
	virtual ~CCodeTimeCheckView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // CodeTimeCheckView.cpp의 디버그 버전
inline CCodeTimeCheckDoc* CCodeTimeCheckView::GetDocument() const
   { return reinterpret_cast<CCodeTimeCheckDoc*>(m_pDocument); }
#endif

