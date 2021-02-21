#include<Windows.h>
#include "resource.h"
#define Dialog_RETURN 66

HWND myHWNd;
HINSTANCE G_hInstance;

BOOL CALLBACK DialogPrec(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);//�ر�һ����ģ̬�Ի���
	
		break;
	case WM_DESTROY:
		//PostQuitMessage(0);//�˳���Ϣ(ȫ�˳�)
		break;
	}
	return FALSE;
}
BOOL CALLBACK DialogFront(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, Dialog_RETURN);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//�˳���Ϣ
		break;
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDC_INTER:
			myHWNd = CreateDialog(G_hInstance, MAKEINTRESOURCE(IDD_MOTAI),hWnd , DialogPrec);
			ShowWindow(myHWNd, SW_SHOW);//visible�ɼ����ã�Ҳ������
			break;
		case IDC_BUTTON1:
			EndDialog(myHWNd,0);
			break;
		case IDC_BUTTON2:
			ShowWindow(myHWNd,SW_SHOW);
			break;
		}
		break;
	}
		
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_FRONT), NULL, DialogFront);

	return 0;
}