#pragma once

#include "UIT_Player.h"
#include "UIT_NPC.h"

class ObjectManager
{
public:
	Player*	m_pPlayer;
	NPC*	m_pNPC;
	NPC*	m_pLastNPC;
	
public:
	ObjectManager();
	~ObjectManager();

public:
	void ObjectsAction();
	void DrawObjects(HDC* phDC);
	void CreateNPC(FLOAT x, FLOAT y);
	void CreatePlayer(FLOAT x, FLOAT y);
};

extern	ObjectManager om;

