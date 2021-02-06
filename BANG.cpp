#include"BangAPI.h"
#pragma warning (disable: 4996)
//#pragma comment (lib,"BANG.lib")

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR hcmdline, INT ncmdshow)
{

	WNDCLASS wnd;
	HWND QQ_h = NULL;
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = MyWndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hinstance;
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)(GetStockObject(SYSTEM_FIXED_FONT));
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = L"轰炸机";
	RegisterClass(&wnd);
	HWND hWnd = CreateWindow(L"轰炸机", L"QQ轰炸机", WS_OVERLAPPEDWINDOW, 300, 300, 300, 200, NULL, NULL, hinstance, NULL);
	ShowWindow(hWnd, ncmdshow);
	UpdateWindow(hWnd);
	QQ_state(QQ_h);
	//MessageBox(NULL, L"", L"", MB_ICONASTERISK);
	MSG msg;
	BOOL bRet;
	while ((bRet = GetMessage(&msg, hWnd, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			exit(0);
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND h1, h2, h3;
	static char qq_num[64];
	switch (uMsg)
	{
	case WM_CREATE:
		CreateWindow(
			TEXT("STATIC"),
			TEXT("QQ号:"),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_RIGHT,
			20,
			15,
			50,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		h1 = CreateWindow(L"EDIT",
			TEXT("必须是好友的QQ号"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
			70,
			15,
			210,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		h3 = CreateWindow(TEXT("BUTTON"),
			TEXT("开始"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
			125,
			80,
			40,
			30,
			hWnd,
			NULL,
			NULL,
			NULL);
		break;
	case WM_COMMAND:
		if ((HWND)lParam == h3)
		{
			HWND B_h = NULL;
			GetWindowTextA(h1, qq_num, 11);
			char url[64] = { "tencent://message/?uin=" };
			char* name = (char*)malloc(strlen(url) + strlen(qq_num));
			sprintf(name, "%s%s", url, qq_num);
			Bang(B_h, name);
		}
		break;
	case WM_DESTROY:
		exit(0);
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}