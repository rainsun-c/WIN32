#include <windows.h>
#include "resource2.h"
#include <time.h>
/*
���̣�
1.��ƴ�����
2.ע�ᴰ����
3.��������
4.��ʾ�͸��´���
5.��Ϣ��ѭ��
*/

//���ڴ�����(���ڹ��Ⱥ���/���ڻص�����)
/*
	��һ������ �����ھ���������������
	�ڶ��������� ��Ϣ��ţ���ֵ
	������������ ������Ϣ��������Ϣ(�������������������Ϣ���߰�ʲô����ֵ������)
	���ĸ������� ������Ϣ��������Ϣ
	CALLBACK ����Լ��
	*/
LRESULT/*long*/ CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM/*unsigned int*/ wParam, LPARAM/*long*/ IParam)
{
	int x = LOWORD(IParam);//����
	int y = HIWORD(IParam);//����
	switch (uMsg)
	{
	case WM_CREATE://��CreateWindow����CreateWindowEXʱ�����֣������ڶ�û������ʱ���֡�
	{
		//MessageBox(hWnd, L"��ӭ����", L"��ʾ", MB_OK);
		CREATESTRUCT* lpcs = (CREATESTRUCT*)IParam;
		SetTimer(hWnd, 1, 1000, NULL);//NULL��Ĭ���ڶ�ʱ����Ϣ�д���
	}
		break;
	case WM_CLOSE://���ڹر���Ϣ���ڵ���رհ�ť�ǳ���
	{
					  int r = MessageBox(hWnd, L"�Ƿ����", L"��ʾ", MB_YESNO);
					  if (IDYES == r)
					  {
						  break;
					  }
					  else if (IDNO == r)
					  {
						   // return 1;//����1����ʾ�棬��ʾ���Լ��Ѿ������ˣ�����ϵͳ����
						return 0;//����0����ʾ�٣����Լ�������ϵͳҲ������
					  }
	}
		//DestroyWindow(hWnd);//���ٴ���
		break;
	case WM_DESTROY://����������Ϣ������Ҫ�˳�ʱ���������������ӿؼ��Ѿ������٣��������졣һ�µĶԴ��ڲ�������ʾ��Ϣ���ڶ�����ʵ�֡�
		PostQuitMessage(0);//wm_QUIT;
		break;
	case WM_RBUTTONDOWN:
		{
			PostQuitMessage(0);
		}
		break;
	//case WM_LBUTTONDOWN://����������
	//	//LParam4���ֽ� 2����

	//	TCHAR str[256];
	//	wsprintf(str, L"������£�%d,%d��", x, y);//�Ȱ�
	//	if (wParam&MK_CONTROL)
	//	{
	//		wcscat(str, L"������ctrol");
	//	}
	//	if (wParam&MK_RBUTTON)
	//	{
	//		wcscat(str, L"����you");
	//	}
	//	if (wParam&MK_SHIFT)
	//	{
	//		wcscat(str, L"����shirt");
	//	}
	//	if (wParam&MK_MBUTTON)
	//	{
	//		wcscat(str, L"�����м��");
	//	}

	//	SetWindowText(hWnd, str);
	//	break;
	//
	//case WM_LBUTTONUP:

	//	TCHAR s[256];
	//	wsprintf(s, L"���̧��%d,%d��", x, y);//�Ȱ�
	//	if (wParam&MK_CONTROL)
	//	{
	//		wcscat(s, L"������ctrol");
	//	}
	//	if (wParam&MK_RBUTTON)
	//	{
	//		wcscat(s, L"����you");
	//	}
	//	if (wParam&MK_SHIFT)
	//	{
	//		wcscat(s, L"����shirt");
	//	}
	//	if (wParam&MK_MBUTTON)
	//	{
	//		wcscat(s, L"�����м��");//������������
	//	}

	//	SetWindowText(hWnd, s);
	//	break;
	//
	//case WM_LBUTTONDBLCLK:
	//{
	//	SetWindowText(hWnd,L"˫��");
	//}
	//	break;

	//case WM_MOUSEMOVE://�ƶ�
	//	wsprintf(s, L"���̧��%d,%d��", x, y);//�Ȱ�
	//	SetWindowText(hWnd, s);
	//	break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE://�ո�
		{
			int x = 50;
			int y = 100;
			SendMessage(hWnd, WM_LBUTTONDOWN, 0, MAKELPARAM(x, y));
		}
			break;
		case VK_SHIFT:
			SetWindowText(hWnd, L"����shift");
			break;
		case VK_TAB:
			SetWindowText(hWnd, L"����tab");
			break;
		case VK_F1:
			SetWindowText(hWnd, L"����f1");
			break;
		case VK_ESCAPE:
			//�رն�ʱ��
			KillTimer(hWnd,1);
			SetWindowText(hWnd, L"����esc");
			break;
		case VK_RETURN:
			SetWindowText(hWnd, L"���»س�");
			break;
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_DOWN:
			break;
		case VK_UP:

			break;
		}
		break;
		 
	//case WM_CHAR://�ɰ�����Ϣ��̧����Ϣ��ϳ�   ����Ϣѭ���еĺ���TranslateMessage(&msg)����;
	//{
	//				 TCHAR ch = (TCHAR)wParam;
	//				 TCHAR sss[256];
	//				 wsprintf(sss, L"�ַ�:%c", ch);
	//				 SetWindowText(hWnd, sss);
	//				 break;
	//}
	case WM_TIMER:
	{
		int nTimerID = wParam;
		switch (nTimerID)
		{
		case 1:
			//��ȡ��ǰʱ��
			//���ַ������᷵�ص�ǰʱ���ʱ���1970��1��0ʱ0�� �����ڵ�����
			//1
			time_t tt = time(NULL);
			tm* t = localtime(&tt);
			TCHAR sz[256];
			wsprintf(sz,L"����ʱ�䣺%d-%02d-%02d %02d:%02d:%02d",t->tm_year+1900,t->tm_mon +1,t->tm_mday,t->tm_hour,t->tm_min ,t->tm_sec );
			//2
			//time_t tt;
			//time(&tt);
			SetWindowText(hWnd,sz);
			break;
		}
	}

		break;
	}

	//����Ĭ�ϵĴ��ڴ�����
	return DefWindowProc(hWnd, uMsg, wParam, IParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//1.��ƴ�����
	WNDCLASS wc = { 0 };       
	//CS_VREDRAW����ƶ����С�����ı��˿ͻ�����ĸ߶ȣ����ػ��������ڡ�
	//CS_HREDRAW�������ڣ�����ƶ����С�����ı��˿ͻ����Ŀ��
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS/*˫����Ϣ��ȡ*/;//������ķ��(�����ƶ������ŵ�)

	wc.lpfnWndProc = WindowProc;	 			//���ڴ�����ipfnWndProc(ָ�򴰿ڹ��̵�ָ��,����ʹ��CallWindowProc���������ô��ڹ���)
	wc.cbClsExtra = 0;								//����������ṹ�壬������չ�ռ�
	wc.cbWndExtra = 0;								//����ʵ���ռ��С���ֽ�����0����Ҫ���ٿռ䣩
	                                                    
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); //���������exeͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		//�����
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 13));//������ɫ
	wc.lpszMenuName = NULL;							//�˵���
	wc.lpszClassName = L"rrrr";					//����������
	//2.ע�ᴰ����
	if (0 == RegisterClass(&wc))
	{
		MessageBox(NULL, L"�˳���������������window NT��", L"��ܰ��ʾ", MB_OK | MB_ICONWARNING);
		return 0;
	}

	//3.��������
	//Window Style ==> WS_
	HWND hWnd = CreateWindow(
		L"rrrr",                                  //����������            
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
		MessageBox(NULL, L"���ڴ���ʧ��", L"��ܰ��ʾ", MB_OK);
		return 0;
	}

	//4.��ʾ�͸��´���
	ShowWindow(hWnd, SW_SHOW);
	/*
		SW_HIDE:����
		SW_SHOW:��ʾ
		SW_SHOWMAXIMIZED:�����ʾ
		SW_SHOWMINiMIZED: ��С����ʾ
	*/

	UpdateWindow(hWnd);
	//5.��Ϣѭ��
	//GetMessage�����ķ���ֵΪ 0��ֻ�н��յ������Ϣ��ʱ��WM_QUIT
	//������Ϣ
	MSG msg;
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//���������Ϣת��Ϊ�ַ���Ϣ
		TranslateMessage(&msg);
		//����Ϣ�ַ������ڴ�����
		DispatchMessage(&msg);
	}
	return 0;
}