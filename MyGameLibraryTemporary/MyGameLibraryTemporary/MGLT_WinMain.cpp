#include "MGLT_Std.h"

LPTSTR lpszClassName = TEXT("MyGameLibraryTemporary");

HRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WinMain(HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			LPSTR lpszCmdLine,
			int nCmdShow)
{
	MSG msg;
	HWND hWnd;
	WNDCLASS wc;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(hInstance, IDC_CROSS);
	wc.hIcon = LoadIcon(hInstance, IDI_ASTERISK);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = lpszClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);


	hWnd = CreateWindow(lpszClassName, lpszClassName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);


	//메인 루프.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


HRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wp, LPARAM lp)
{
	if (iMsg == WM_DESTROY)
		PostQuitMessage(0);

	return DefWindowProc(hWnd, iMsg, wp, lp);
}