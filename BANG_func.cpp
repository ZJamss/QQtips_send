

#include"BangAPI.h"

void QQ_state(HWND QQ_Hwnd) {
	do
	{
		QQ_Hwnd = FindWindow(L"TXGuiFoundation", L"QQ");
		if (QQ_Hwnd == NULL)
			MessageBox(NULL, L"请打开QQ（不用关闭该程序）", L"提示", MB_ICONASTERISK);
	} while (QQ_Hwnd == NULL);
}
void Bang(HWND h, char* name)
{
	ShellExecuteA(NULL, "open", name, NULL, NULL, SW_NORMAL);
	Sleep(500);
	h = GetForegroundWindow();
	Sleep(500);
	while (MessageBox(h, L"是否开始发送", L"温馨提示", MB_YESNO) == IDYES)
	{
		int a = 10;
		while (a--)
		{
			SendMessage(h, WM_PASTE, 0, 0);
			SendMessage(h, WM_KEYDOWN, VK_RETURN, 0);
		}
	}
}