#pragma once

#include "UIT_Object.h"


class Player :
	public Object
{
public:
	//현재 행동함수포인터.
	(void)(Player::*fpAction)(void);

public:
	Player();
	~Player();

public:
	void Action_Move();
	void SetCenterViewport(POINT* pptView, RECT* prtClient);
};

