#pragma once

#include "UIT_Object.h"


class NPC :
	public Object
{
private:
	DWORD m_waitTime;

public:
	//���� �ൿ�Լ�������.
	(void)(NPC::*fpAction)(void);

public:
	NPC();
	~NPC();

public:
	void Action_Move();
	void Action_Wait();
	void SetRandomWaypoint();
};

