#include <Windows.h>
#include "resource.h"

#define IDEND 1
#define IDLOGIN 66
HINSTANCE g_hInstance;

BOOL CALLBACK FRISTDialog(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, IDEND);
		break;
	case WM_DESTROY://close之后默认响应destroy.,没有一个也可以
		break;
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDOK:
			//获取密码和账号
			TCHAR szUsername[200];
			TCHAR szPassword[200];
			GetDlgItemText(hWnd, IDC_EDIT1, szUsername,200);//获取数据到字符串中
			GetDlgItemText(hWnd, IDC_EDIT2, szPassword, 200);
			if (wcscmp(szUsername, L"asdfgh")==0 && wcscmp(szPassword, L"123456")==0)
			{
				EndDialog(hWnd, IDLOGIN);
			}
			else
			{
				MessageBox(hWnd, L"输入错误",L"提示", MB_OK);
				return TRUE;
			}
			break;
		}
		break;
	}
	}
	//return TRUE;表示返回真，表示我们处理了，操作系统不会处理
	return FALSE;//表示我们不处理，给操作系统处理
}
BOOL CALLBACK DialogAbout(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, IDEND);
		break;
	case WM_DESTROY://close之后默认响应destroy.,没有一个也可以
		break;
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDOK:
			MessageBox(hWnd, L"点了确定", L"提示", MB_OK);
			break;
		}
		break;
	}
}

	//return TRUE;表示返回真，表示我们处理了，操作系统不会处理
	return FALSE;//表示我们不处理，给操作系统处理
}
//CALLBACK调用约定表明这个是回调函数
BOOL CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG://对话框初始化消息，可以放在这里做（对话框还没显示出来，但是已经创建了） 
	{
		//设置图标
		HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
		//发送图标
		SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
		SetWindowText(hWnd, L"chushihuaduihuak");
		//设置窗口透明度
		SetLayeredWindowAttributes(hWnd,RGB(0,0,0),125,LWA_COLORKEY|LWA_ALPHA);
		break;
	}
	case WM_CLOSE:
		if (IDNO == MessageBox(NULL, L"销毁响应", NULL, MB_YESNO))
		{
			return TRUE;
		}
		else
		{
			EndDialog(hWnd, IDEND);
		}
		break;
	case WM_DESTROY://close之后默认响应destroy.,没有一个也可以
		
		break;
	
	case WM_DROPFILES://文件拖拽消息
	{
		HDROP hDrop = (HDROP)wParam;
		TCHAR szPath[MAX_PATH];
		int nCount = DragQueryFile(hDrop, 0xffffffff, NULL, 0);
		for (int i = 0; i < nCount; i++)
		{
			DragQueryFile(hDrop, i, szPath, MAX_PATH);
			MessageBox(hWnd, szPath, NULL, MB_OK);
		}
		break;
	}
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDOK:
			MessageBox(hWnd,L"点了确定",L"提示",MB_OKCANCEL);
			break;
		case IDCANCEL:
			EndDialog(hWnd,IDEND);
			break;
		case IDC_BUTTON1:
			DialogBox(g_hInstance/*当前句柄*/, MAKEINTRESOURCE(IDD_ABOUT)/*字符串（名称）*/, NULL/*父窗口句柄*/, DialogAbout);
			break;
		}
		break;
	}
		
	}

	//return TRUE;表示返回真，表示我们处理了，操作系统不会处理
	return FALSE;//表示我们不处理，给操作系统处理
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR IpCmdLine, int nCmdShow)
{   //EndDialog（关闭一个模态对话框）
		g_hInstance = hInstance;
	int reault= DialogBox(hInstance/*当前句柄*/, MAKEINTRESOURCE(IDD_LOGIN)/*字符串（名称）*/, NULL/*父窗口句柄*/, FRISTDialog);
	if (reault == IDLOGIN)
	{
		DialogBox(hInstance/*当前句柄*/, MAKEINTRESOURCE(IDD_NB)/*字符串（名称）*/, NULL/*父窗口句柄*/, DialogProc);
	}
	system("pause");
	return 0;
}