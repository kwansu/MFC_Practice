#include "CBufferDC.h"
#include "stdafx.h"

CBufferDC::CBufferDC(CWnd* pWnd)
	:m_pWnd(pWnd)
{
	m_pWndDC = pWnd->BeginPaint(&m_ps);

	pWnd->GetClientRect(&m_rcClient);

	m_memoryDC.CreateCompatibleDC(m_pWndDC);


	m_bmpBkgnd.CreateBitmap(m_rcClient.Width(), m_rcClient.Height()
		, m_memoryDC.GetDeviceCaps(PLANES)
		, m_memoryDC.GetDeviceCaps(BITSPIXEL), NULL);

	m_bmpOld = m_memoryDC.SelectObject(&m_bmpBkgnd);

	CDC::m_hDC = m_memoryDC.m_hDC;
//	Attach(m_memoryDC.m_hDC);
}

CBufferDC::~CBufferDC()
{
	m_pWndDC->BitBlt(m_ps.rcPaint.left, m_ps.rcPaint.top
		, m_ps.rcPaint.right - m_ps.rcPaint.left
		, m_ps.rcPaint.bottom - m_ps.rcPaint.top
		, &m_memoryDC, m_ps.rcPaint.left, m_ps.rcPaint.top, SRCCOPY);

	m_memoryDC.SelectObject(m_bmpOld);

	m_pWnd->EndPaint(&m_ps);
//	Detach();
}
