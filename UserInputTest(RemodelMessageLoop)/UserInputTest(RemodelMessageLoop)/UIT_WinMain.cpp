
#include "UIT_Std.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdLine, int nCmdShow)
{
	LPTSTR lpszClassName = _T("UserInputTest");
	HWND hWnd;
	MSG msg;
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wndClass.hIcon = LoadIcon(hInstance, IDI_EXCLAMATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = lpszClassName;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	
	RegisterClass(&wndClass);

	hWnd = CreateWindow(lpszClassName, lpszClassName
		, WS_OVERLAPPEDWINDOW | WS_BORDER
		, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT
		, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	DWORD time;
	TCHAR str[30];

	//Remodel MessageLoop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (g_bRunGame)
		{
			time = GetTickCount();

			while (g_bRunGame)
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						return 0;

					DispatchMessage(&msg);
				}
				else
				{
					DWORD interval = GetTickCount() - time;

					if (interval < FRAME_INTERVAL)
					{
						Sleep(FRAME_INTERVAL - interval);
					}

					om.ObjectsAction();

					InvalidateRect(hWnd, NULL, FALSE);

					time = GetTickCount();
				}
			}
		}

		DispatchMessage(&msg);
	}

	return msg.wParam;
}