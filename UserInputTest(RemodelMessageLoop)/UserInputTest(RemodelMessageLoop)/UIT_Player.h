#pragma once

#include "UIT_Object.h"


class Player :
	public Object
{
public:
	//���� �ൿ�Լ�������.
	(void)(Player::*fpAction)(void);

public:
	Player();
	~Player();

public:
	void Action_Move();
	void SetCenterViewport(POINT* pptView, RECT* prtClient);
};

