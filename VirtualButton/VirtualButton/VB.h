#pragma once

class CVirtualButton
{
public:
	CRect m_rtButtonSize;
	BOOL m_bActive;
	BOOL m_bClick;

public:
	CVirtualButton()
	{
		m_rtButtonSize = CRect(0, 0, 0, 0);
		m_bActive = FALSE;
		m_bClick = FALSE;
	}
};