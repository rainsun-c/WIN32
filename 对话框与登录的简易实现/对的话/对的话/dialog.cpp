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
	case WM_DESTROY://close֮��Ĭ����Ӧdestroy.,û��һ��Ҳ����
		break;
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDOK:
			//��ȡ������˺�
			TCHAR szUsername[200];
			TCHAR szPassword[200];
			GetDlgItemText(hWnd, IDC_EDIT1, szUsername,200);//��ȡ���ݵ��ַ�����
			GetDlgItemText(hWnd, IDC_EDIT2, szPassword, 200);
			if (wcscmp(szUsername, L"asdfgh")==0 && wcscmp(szPassword, L"123456")==0)
			{
				EndDialog(hWnd, IDLOGIN);
			}
			else
			{
				MessageBox(hWnd, L"�������",L"��ʾ", MB_OK);
				return TRUE;
			}
			break;
		}
		break;
	}
	}
	//return TRUE;��ʾ�����棬��ʾ���Ǵ����ˣ�����ϵͳ���ᴦ��
	return FALSE;//��ʾ���ǲ�����������ϵͳ����
}
BOOL CALLBACK DialogAbout(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, IDEND);
		break;
	case WM_DESTROY://close֮��Ĭ����Ӧdestroy.,û��һ��Ҳ����
		break;
	case WM_COMMAND:
	{
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDOK:
			MessageBox(hWnd, L"����ȷ��", L"��ʾ", MB_OK);
			break;
		}
		break;
	}
}

	//return TRUE;��ʾ�����棬��ʾ���Ǵ����ˣ�����ϵͳ���ᴦ��
	return FALSE;//��ʾ���ǲ�����������ϵͳ����
}
//CALLBACK����Լ����������ǻص�����
BOOL CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG://�Ի����ʼ����Ϣ�����Է������������Ի���û��ʾ�����������Ѿ������ˣ� 
	{
		//����ͼ��
		HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
		//����ͼ��
		SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
		SetWindowText(hWnd, L"chushihuaduihuak");
		//���ô���͸����
		SetLayeredWindowAttributes(hWnd,RGB(0,0,0),125,LWA_COLORKEY|LWA_ALPHA);
		break;
	}
	case WM_CLOSE:
		if (IDNO == MessageBox(NULL, L"������Ӧ", NULL, MB_YESNO))
		{
			return TRUE;
		}
		else
		{
			EndDialog(hWnd, IDEND);
		}
		break;
	case WM_DESTROY://close֮��Ĭ����Ӧdestroy.,û��һ��Ҳ����
		
		break;
	
	case WM_DROPFILES://�ļ���ק��Ϣ
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
			MessageBox(hWnd,L"����ȷ��",L"��ʾ",MB_OKCANCEL);
			break;
		case IDCANCEL:
			EndDialog(hWnd,IDEND);
			break;
		case IDC_BUTTON1:
			DialogBox(g_hInstance/*��ǰ���*/, MAKEINTRESOURCE(IDD_ABOUT)/*�ַ��������ƣ�*/, NULL/*�����ھ��*/, DialogAbout);
			break;
		}
		break;
	}
		
	}

	//return TRUE;��ʾ�����棬��ʾ���Ǵ����ˣ�����ϵͳ���ᴦ��
	return FALSE;//��ʾ���ǲ�����������ϵͳ����
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR IpCmdLine, int nCmdShow)
{   //EndDialog���ر�һ��ģ̬�Ի���
		g_hInstance = hInstance;
	int reault= DialogBox(hInstance/*��ǰ���*/, MAKEINTRESOURCE(IDD_LOGIN)/*�ַ��������ƣ�*/, NULL/*�����ھ��*/, FRISTDialog);
	if (reault == IDLOGIN)
	{
		DialogBox(hInstance/*��ǰ���*/, MAKEINTRESOURCE(IDD_NB)/*�ַ��������ƣ�*/, NULL/*�����ھ��*/, DialogProc);
	}
	system("pause");
	return 0;
}