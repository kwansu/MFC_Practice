#pragma once

#include "UIT_Base.h"


class Object
{
protected:
	FLOAT	m_x, m_y;
	FLOAT	m_dx, m_dy;

	FLOAT	m_wayX, m_wayY;
	RECT	m_rtWay;

	int		m_width, m_height;
	RECT	m_rtColl;
	HBITMAP	m_hBmp;

public:
	Object*	m_pNextObject;

	static HDC	*m_pBufferDC, m_memDC;
	static DWORD	m_currentTime;

public:
	Object();

public:
	void SetPosition(FLOAT x, FLOAT y);
	void SetWaypoint(FLOAT wayX, FLOAT wayY);
	BOOL MoveObject();
	void DrawObject();
	void SetBitmap(HBITMAP& hBmp);
	void SetCollideBody();

protected:
	//	virtual void Action_Move() = 0;

};

