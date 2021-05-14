#pragma once

#include "UIT_Object.h"


class NPC :
	public Object
{
private:
	DWORD m_waitTime;

public:
	//현재 행동함수포인터.
	(void)(NPC::*fpAction)(void);

public:
	NPC();
	~NPC();

public:
	void Action_Move();
	void Action_Wait();
	void SetRandomWaypoint();
};

