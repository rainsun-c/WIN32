#include <Windows.h>
#include"resource.h"
#include <time.h>
#define  _CRT_SECURE_NO_WARNINGS
#define OPEN_TIME_ONE 1
#define DIALOG_CLOSE_RETURN 66

BOOL CALLBACK DialogPrec(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		
		break;
	case WM_COMMAND:
	{
		int cID = LOWORD(wParam);
		switch (cID)
		{
		case IDOK:
			SetTimer(hWnd, OPEN_TIME_ONE, 1000, NULL);
			break;
		case IDCANCEL:
			KillTimer(hWnd, OPEN_TIME_ONE);
			break;
		}
		break;
	}
		
	case WM_TIMER:
	{
		int TimeID = wParam;
		switch (TimeID)
		{
		case OPEN_TIME_ONE:
			{
			time_t tt = time(NULL);
			tm* t= localtime(&tt);
			TCHAR str[MAX_PATH];
			wsprintf(str, L"现在时间为 %d-%d-%d", t->tm_hour, t->tm_min, t->tm_sec);
			SetWindowText(hWnd,str);
			}
			break;
		}
		break;
	}
		
	case WM_CLOSE:
	{
		if (IDOK == MessageBox(hWnd, L"确定关闭定时器！！", L"提示", MB_OKCANCEL))
		{
			EndDialog(hWnd, DIALOG_CLOSE_RETURN);
		}
		else
		{
			return TRUE;
		}
		break;
	}
	}
	return FALSE;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_TIMER), NULL, DialogPrec);
	return 0;
}