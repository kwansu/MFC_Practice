#include "UIT_NPC.h"
#include "UIT_WndProc.h"


NPC::NPC()
	:Object()
{
	fpAction = &NPC::Action_Move;

	SetBitmap(g_hBmp_NPC);
}


NPC::~NPC()
{
}


void NPC::Action_Move()
{
	if (MoveObject())
	{
		fpAction = &NPC::Action_Wait;

		m_waitTime = m_currentTime + rand() % MAX_WAIT_TIME;
	}
}


void NPC::Action_Wait()
{
	if (m_waitTime < m_currentTime)
	{
		fpAction = &NPC::Action_Move;

		SetRandomWaypoint();
	}
}


void NPC::SetRandomWaypoint()
{
	SetWaypoint(m_x + rand() % MAX_MOVE_RADIUS * 2 - MAX_MOVE_RADIUS
		, m_y + rand() % MAX_MOVE_RADIUS * 2 - MAX_MOVE_RADIUS);
}