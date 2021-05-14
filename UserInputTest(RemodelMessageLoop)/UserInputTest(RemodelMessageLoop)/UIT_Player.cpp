#include "UIT_Player.h"
#include "UIT_WndProc.h"


Player::Player()
	:Object()
{
	SetBitmap(g_hBmp_player);

	fpAction = NULL;
}


Player::~Player()
{
}


void Player::Action_Move()
{
	if (MoveObject())
		fpAction = NULL;
}


void Player::SetCenterViewport(POINT* pptView, RECT* prtClient)
{
	pptView->x = MINMAX(m_x - prtClient->right / 2
		, 0, WORLD_WIDTH - 1920);
	pptView->y = MINMAX(m_y - prtClient->bottom / 2
		, 0, WORLD_HEIGHT - 1080);
}