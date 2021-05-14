#include <Windows.h>

//사용자의 입력(마우스 드래그시 선 그리기)도중
//타이머(프레임 update -> 계산시간이 걸린다 가정) 사용 할때 어떻게 되는지 확인.

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Class");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT
		, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

void Update()
{
	int a = 2;

	for (int x = 0; x < 10000; x++)
		for (int y = 0; y < 10000; y++)
			a *= 7;

	return;
}

//일반 타이머로 확인결과 타이머 계산도중 입력을 받을 수 없다는 것을 확인. 대처로 타이머 함수를 사용해 본다.
void CALLBACK TimerFunc(HWND hWnd, UINT id, UINT_PTR wp, DWORD lp)
{
	Update();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static BOOL bDragPen;
	static WORD x, y;

	switch (iMessage)
	{
	case WM_CREATE:
		bDragPen = FALSE;
		SetTimer(hWnd, 666, 20, 0);
		break;
	case WM_LBUTTONDOWN:
		bDragPen = TRUE;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		bDragPen = FALSE;
		break;
	case WM_MOUSEMOVE:
		if (bDragPen)
		{
			hdc = GetDC(hWnd);

			MoveToEx(hdc, x, y, NULL);
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			LineTo(hdc, x, y);

			DeleteDC(hdc);
		}
		break;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);

		x = LOWORD(lParam);
		y = HIWORD(lParam);
		Ellipse(hdc, x - 5, y - 5, x + 5, y + 5);

		DeleteDC(hdc);
		break;
	case WM_TIMER:

		Update();

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
	return 0;
}