#pragma once
#include "afxwin.h"

class CBufferDC :
	public CDC
{
private:
	CBufferDC() { }
	CBufferDC(const CBufferDC &src) { }
	CBufferDC& operator=(const CBufferDC &src) { }

public:
	CBufferDC(CWnd* pWnd);
	~CBufferDC();

private:
	CDC *m_pWndDC, m_memoryDC;
	CWnd* m_pWnd;
	PAINTSTRUCT m_ps;
	CRect m_rcClient;
	CBitmap m_bmpBkgnd, *m_bmpOld;
	
public:
	inline CRect ClientRect() const { return m_rcClient; }
	inline CRect UpdateRect() const { return m_ps.rcPaint; }

	operator HDC() const { return m_memoryDC.m_hDC; }
};

