#pragma once

#include "Object.h"


class Creature :
	public Object
{
protected:
	CPointR	m_ptVel;
	CPointR m_ptWay;
	CRect	m_rtDestination;
	CRect	m_rtColl;
	CPointR	m_ptCenterOfColl;

public:
	int		m_nWayRadius;
	//character status
	int		m_nHP;
	int		m_nStr;

	//action FunctionPointer
	void(Creature::*fpAction)();

public:
	Creature();
	~Creature();

	void SetVelocity(CPointR);
	void SetWaypoint(CPointR);
	BOOL MoveCreature();

	//action function
	virtual void Action_Move();
	virtual void Action_Wait();
};

