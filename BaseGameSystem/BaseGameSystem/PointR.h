#pragma once

#include "stdafx.h"

class CPointR :
	public CPoint
{
public:
	FLOAT xR, yR;

public:

	CPointR() : CPoint(0, 0) { xR = 0, yR = 0; }
	CPointR(CPoint pos) :CPoint(pos)	{ xR = x, yR = y; }
	CPointR(FLOAT x, FLOAT y) :CPoint(x, y) { xR = (FLOAT)x, yR = (FLOAT)y; }
};

