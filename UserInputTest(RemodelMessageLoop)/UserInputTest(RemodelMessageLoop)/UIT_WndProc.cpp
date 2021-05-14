#include "UIT_WndProc.h"


BOOL g_bRunGame;
BOOL g_bDragMap;

HBITMAP g_hBmp_worldmap, g_hBmp_viewport;
HBITMAP g_hBmp_player, g_hBmp_NPC;

POINT g_ptViewportPos;
POINT g_ptDragClickedPos, g_ptDragViewportPos;

RECT g_rtClient;

HINSTANCE g_hInst;

HRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
		HANDLE_MSG(hWnd, WM_CREATE, Cls_OnCreate);
		HANDLE_MSG(hWnd, WM_DESTROY, Cls_OnDestroy);
		HANDLE_MSG(hWnd, WM_PAINT, Cls_OnPaint);
		HANDLE_MSG(hWnd, WM_LBUTTONDOWN, Cls_OnLButtonDown);
		HANDLE_MSG(hWnd, WM_LBUTTONUP, Cls_OnLButtonUp);
		HANDLE_MSG(hWnd, WM_RBUTTONDOWN, Cls_OnRButtonDown);
		HANDLE_MSG(hWnd, WM_RBUTTONUP, Cls_OnRButtonUp);
		HANDLE_MSG(hWnd, WM_MOUSEMOVE, Cls_OnMouseMove);
		HANDLE_MSG(hWnd, WM_KEYDOWN, Cls_OnKey);
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}


BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
	g_hInst = GetModuleHandle(NULL);

	g_hBmp_player = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
	g_hBmp_NPC = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_NPC));

	HDC hdc = GetDC(hwnd);

	g_hBmp_viewport = CreateCompatibleBitmap(hdc
		, WORLD_WIDTH, WORLD_HEIGHT);
	g_hBmp_worldmap = CreateCompatibleBitmap(hdc
		, WORLD_WIDTH, WORLD_HEIGHT);

	HBITMAP hBmp_pattern = LoadBitmap(g_hInst
		, MAKEINTRESOURCE(IDB_WORLDMAP_HATCH));

	HDC memDC = CreateCompatibleDC(hdc);

	HBRUSH hBrush_pattern = CreatePatternBrush(hBmp_pattern);

	HBITMAP hBmp_Old = (HBITMAP)SelectObject(memDC, g_hBmp_worldmap);

	RECT rcWorld = { 0, 0, WORLD_WIDTH, WORLD_HEIGHT };

	FillRect(memDC, &rcWorld, hBrush_pattern);

	SelectObject(memDC, hBmp_Old);

	DeleteObject(hBrush_pattern);
	DeleteObject(hBmp_pattern);

	DeleteDC(hdc);
	DeleteDC(memDC);

	g_bRunGame = FALSE;

	om.CreatePlayer(500.0f, 500.0f);
	return TRUE;
}


void Cls_OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}


void Cls_OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc, memDC, bufferDC;
	HBITMAP hOldBmp1, hOldBmp2;

	GetClientRect(hwnd, &g_rtClient);

	if (GetKeyState(VK_SPACE) & 0x8000)
		om.m_pPlayer->SetCenterViewport(&g_ptViewportPos, &g_rtClient);

	hdc = BeginPaint(hwnd, &ps);
	memDC = CreateCompatibleDC(hdc);
	bufferDC = CreateCompatibleDC(hdc);

	hOldBmp1 = (HBITMAP)SelectObject(memDC, g_hBmp_worldmap);
	hOldBmp2 = (HBITMAP)SelectObject(bufferDC, g_hBmp_viewport);

	BitBlt(bufferDC, g_ptViewportPos.x, g_ptViewportPos.y
		, 1920, 1080, memDC
		, g_ptViewportPos.x, g_ptViewportPos.y, SRCCOPY);

	if (g_bRunGame)
		om.DrawObjects(&bufferDC);

	TCHAR str[30];

	wsprintf(str, _T("x : %d	y : %d"), g_ptViewportPos.x
		, g_ptViewportPos.y);
	TextOut(bufferDC, g_ptViewportPos.x + 100
		, g_ptViewportPos.y + 100, str, lstrlen(str));

	BitBlt(hdc, 0, 0, 1920, 1080, bufferDC
		, g_ptViewportPos.x, g_ptViewportPos.y, SRCCOPY);


	if (!SelectObject(memDC, hOldBmp1))
		MessageBox(hwnd, _T("Memory leek!"), NULL, MB_OK);

	if (!SelectObject(bufferDC, hOldBmp2))
		MessageBox(hwnd, _T("Memory leek!"), NULL, MB_OK);

	if (!DeleteDC(memDC))
		MessageBox(hwnd, _T("Memory leek!"), NULL, MB_OK);
	if (!DeleteDC(bufferDC))
		MessageBox(hwnd, _T("Memory leek!"), NULL, MB_OK);

	EndPaint(hwnd, &ps);
}


void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	g_bDragMap = TRUE;

	g_ptDragClickedPos.x = x;
	g_ptDragClickedPos.y = y;

	g_ptDragViewportPos = g_ptViewportPos;

	SetCapture(hwnd);
}


void Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags)
{
	g_bDragMap = FALSE;
	ReleaseCapture();
}


void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}


void Cls_OnRButtonUp(HWND hwnd, int x, int y, UINT flags)
{
	if (g_bRunGame)
	{
		om.m_pPlayer->SetWaypoint(g_ptViewportPos.x + x, g_ptViewportPos.y + y);
		om.m_pPlayer->fpAction = &Player::Action_Move;
	}
	else
	{
		om.CreateNPC(g_ptViewportPos.x + x, g_ptViewportPos.y + y);
	}
}


void Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags)
{
	if (g_bDragMap)
	{
		g_ptViewportPos.x = MINMAX(g_ptDragViewportPos.x
			- (x - g_ptDragClickedPos.x), 0, WORLD_WIDTH - 1920);
		g_ptViewportPos.y = MINMAX(g_ptDragViewportPos.y
			- (y - g_ptDragClickedPos.y), 0, WORLD_HEIGHT - 1080);

		InvalidateRect(hwnd, NULL, FALSE);
	}
}


void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	switch (vk)
	{
	case VK_RETURN:
		g_bRunGame = TRUE;
		break;
	}
}