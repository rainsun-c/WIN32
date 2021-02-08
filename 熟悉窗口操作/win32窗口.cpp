#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM WParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
					   MessageBox(hWnd, L"��ӭ����", L"��ʾ", MB_OK);
	}
		break;
	case WM_CLOSE:
	{
					  int r = MessageBox(hWnd, L"�Ƿ����", L"��ʾ", MB_YESNO);
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
		MessageBox(NULL,L"ע��ʧ��",L"��ʾ",MB_OK );
		return 0;
	}

	HWND hWnd = CreateWindow(
		L"rrrr",                                      //����������            
		L"��һ������",								  //���ڵı���
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX,//���ڵķ��
		300, 200,									  //��������
		800, 600,									  //���� ����
		NULL,										  //�����ھ��
		NULL,										  //�˵����
		hInstance,									  //��ǰӦ�ó���ʵ���������
		NULL										  //�������ڴ��ݵĸ�������
		);
	if (hWnd == NULL)
	{
		MessageBox(NULL, L"ע��ʧ��", L"��ʾ", MB_OK);
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
