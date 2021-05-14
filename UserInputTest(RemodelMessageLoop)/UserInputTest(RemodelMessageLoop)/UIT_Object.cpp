#include "UIT_Object.h"


HDC* Object::m_pBufferDC = nullptr;
HDC Object::m_memDC = NULL;
DWORD Object::m_currentTime = GetTickCount();


Object::Object()
{
	m_dx =0, m_dy = 0;
	m_wayX = 0, m_wayY = 0, m_width = 0, m_height = 0;

	m_pNextObject = NULL;
}


void Object::SetPosition(FLOAT x, FLOAT y)
{
	m_x = MINMAX(x, 0, WORLD_WIDTH);
	m_y = MINMAX(y, 0, WORLD_HEIGHT);
}


void Object::SetWaypoint(FLOAT wayX, FLOAT wayY)
{
	m_wayX = MINMAX(wayX, 0, WORLD_WIDTH);
	m_wayY = MINMAX(wayY, 0, WORLD_WIDTH);

	m_dx = m_wayX - m_x;
	m_dy = m_wayY - m_y;

	FLOAT sum = ABS(m_dx) + ABS(m_dy);

	m_dx *= MAX_SPEED / sum;
	m_dy *= MAX_SPEED / sum;

	SetCenterRect(&m_rtWay, m_wayX, m_wayY, WAYPOINT_RDIAN);
}


BOOL Object::MoveObject()
{
	m_x += m_dx, m_y += m_dy;
	
	if (PtInRectCheck(&m_rtWay, m_x, m_y))
	{
		m_dx = 0, m_dy = 0;
		
		return TRUE;
	}
	return FALSE;
}


void Object::DrawObject()
{
	SetCollideBody();

	HBITMAP hOldBmp = (HBITMAP)SelectObject(m_memDC, m_hBmp);
	
	BitBlt(*m_pBufferDC, m_rtColl.left, m_rtColl.top, m_width, m_height
		, m_memDC, 0, 0, SRCCOPY);

	SelectObject(m_memDC, hOldBmp);
}


void Object::SetBitmap(HBITMAP& hBmp)
{
	m_hBmp = hBmp;

	BITMAP bitInfo;
	GetObject(hBmp, sizeof(BITMAP), &bitInfo);

	m_width = bitInfo.bmWidth;
	m_height = bitInfo.bmHeight;
}


void Object::SetCollideBody()
{
	SetRect(&m_rtColl, m_x - m_width / 2, m_y - m_height / 2
		, m_x + m_width / 2, m_y + m_height);
}