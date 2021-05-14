#include "UIT_ObjectManager.h"


ObjectManager om;
HWND hWnd;

ObjectManager::ObjectManager()
{
	hWnd = FindWindow(NULL, NULL);
}


ObjectManager::~ObjectManager()
{
}


void ObjectManager::ObjectsAction()
{
	Object::m_currentTime = GetTickCount();

//	KeyInput();

	if (m_pPlayer->fpAction)
		(m_pPlayer->*(*m_pPlayer).fpAction)();

	NPC* pNPC = m_pNPC;

	while (pNPC)
	{
		(pNPC->*(*pNPC).fpAction)();
		pNPC = (NPC*)pNPC->m_pNextObject;
	}
}


void ObjectManager::DrawObjects(HDC* phDC)
{
	HDC memDC;
	memDC = CreateCompatibleDC(*phDC);

	Object::m_pBufferDC = phDC;
	Object::m_memDC = memDC;

	m_pPlayer->DrawObject();
	
	NPC* pNPC = m_pNPC;

	while (pNPC)
	{
		pNPC->DrawObject();
		pNPC = (NPC*)pNPC->m_pNextObject;
	}

	if (!DeleteDC(memDC))
		MessageBox(hWnd, _T("Memory leek!"), NULL, MB_OK);
}


void ObjectManager::CreateNPC(FLOAT x, FLOAT y)
{
	if (!m_pLastNPC)
	{
		m_pNPC = new NPC;
		m_pLastNPC = m_pNPC;
	}
	else
	{
		m_pLastNPC->m_pNextObject = new NPC;
		m_pLastNPC = (NPC*)m_pLastNPC->m_pNextObject;
	}

	m_pLastNPC->SetPosition(x, y);
	m_pLastNPC->SetRandomWaypoint();
}


void ObjectManager::CreatePlayer(FLOAT x, FLOAT y)
{
	if (!m_pPlayer)
		delete m_pPlayer;

	m_pPlayer = new Player;

	m_pPlayer->SetPosition(x, y);
}