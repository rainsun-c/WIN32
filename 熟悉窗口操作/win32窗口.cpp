#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM WParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
					   MessageBox(hWnd, L"欢迎进入", L"提示", MB_OK);
	}
		break;
	case WM_CLOSE:
	{
					  int r = MessageBox(hWnd, L"是否进入", L"提示", MB_YESNO);
					  if (IDYES == r)
					  {
						  break;
					  }
					  else if (IDNO == r)
					  {
						  return 0;
					  }
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, WParam, lParam);
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR IpCmdLine,int nCmdShow )
{
	WNDCLASS ws = { 0 };
	ws.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	ws.lpfnWndProc = WindowProc;
	ws.cbClsExtra = 0;
	ws.cbWndExtra = 0;
	ws.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(NULL));
	ws.hbrBackground = CreateSolidBrush(RGB(0,0,0));
	ws.hCursor = LoadCursor(NULL, IDC_CROSS);
	ws.lpszMenuName = NULL;
	ws.lpszClassName = L"rrrr";

	if (0 == RegisterClass(&ws))
	{
		MessageBox(NULL,L"注册失败",L"提示",MB_OK );
		return 0;
	}

	HWND hWnd = CreateWindow(
		L"rrrr",                                      //窗口类型名            
		L"第一个窗口",								  //窗口的标题
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX,//窗口的风格
		300, 200,									  //窗口坐标
		800, 600,									  //窗口 宽，高
		NULL,										  //父窗口句柄
		NULL,										  //菜单句柄
		hInstance,									  //当前应用程序实例句柄类型
		NULL										  //创建窗口传递的附加数据
		);
	if (hWnd == NULL)
	{
		MessageBox(NULL, L"注册失败", L"提示", MB_OK);
		return 0;
	}

	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);

	MSG uMsg;
	while (GetMessage(&uMsg, NULL, 0, 0))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return 0;
}
