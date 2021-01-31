#include <windows.h>
#include "resource2.h"
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
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM/*unsigned int*/ wParam, LPARAM/*long*/ IParam)
{
	switch (uMsg)
	{
	case WM_CLOSE://���ڹر���Ϣ
		DestroyWindow(hWnd);//���ٴ���
		break;
	case WM_DESTROY://����������Ϣ
		PostQuitMessage(0);//wm_QUIT;
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
	wc.lpszClassName = L"��սʤ��";					//����������
	//2.ע�ᴰ����
	if (0 == RegisterClass(&wc))
	{
		MessageBox(NULL, L"�˳���������������window NT��", L"��ܰ��ʾ", MB_OK | MB_ICONWARNING);
		return 0;
	}

	//3.��������
	//Window Style ==> WS_
	HWND hWnd = CreateWindow(
		L"��սʤ��",                                  //����������            
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