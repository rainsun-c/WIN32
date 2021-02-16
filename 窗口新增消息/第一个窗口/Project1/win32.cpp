#include <windows.h>
#include "resource2.h"
#include <time.h>
/*
流程：
1.设计窗口类
2.注册窗口类
3.创建窗口
4.显示和更新窗口
5.消息的循环
*/

//窗口处理函数(窗口过度函数/窗口回调函数)
/*
	第一个参数 ：窗口句柄，创建这个窗口
	第二个参数： 消息编号，数值
	第三个参数： 附加消息，附加信息(鼠标点击，附加上坐标信息或者按什么键键值传进来)
	第四个参数： 附加消息，附加信息
	CALLBACK 调用约定
	*/
LRESULT/*long*/ CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM/*unsigned int*/ wParam, LPARAM/*long*/ IParam)
{
	int x = LOWORD(IParam);//低字
	int y = HIWORD(IParam);//高字
	switch (uMsg)
	{
	case WM_CREATE://在CreateWindow或者CreateWindowEX时，出现，连窗口都没有生成时出现。
	{
		//MessageBox(hWnd, L"欢迎进入", L"提示", MB_OK);
		CREATESTRUCT* lpcs = (CREATESTRUCT*)IParam;
		SetTimer(hWnd, 1, 1000, NULL);//NULL会默认在定时器消息中处理
	}
		break;
	case WM_CLOSE://窗口关闭消息，在点击关闭按钮是出现
	{
					  int r = MessageBox(hWnd, L"是否进入", L"提示", MB_YESNO);
					  if (IDYES == r)
					  {
						  break;
					  }
					  else if (IDNO == r)
					  {
						   // return 1;//返回1，表示真，表示我自己已经处理了，不用系统处理
						return 0;//返回0，表示假，我自己不处理，系统也不处理。
					  }
	}
		//DestroyWindow(hWnd);//销毁窗口
		break;
	case WM_DESTROY://窗口销毁消息，窗口要退出时，清理工作，窗口子控件已经被销毁，无力回天。一下的对窗口操作如显示消息窗口都不能实现。
		PostQuitMessage(0);//wm_QUIT;
		break;
	case WM_RBUTTONDOWN:
		{
			PostQuitMessage(0);
		}
		break;
	//case WM_LBUTTONDOWN://鼠标左键按下
	//	//LParam4个字节 2个字

	//	TCHAR str[256];
	//	wsprintf(str, L"左键按下（%d,%d）", x, y);//先按
	//	if (wParam&MK_CONTROL)
	//	{
	//		wcscat(str, L"按下了ctrol");
	//	}
	//	if (wParam&MK_RBUTTON)
	//	{
	//		wcscat(str, L"按下you");
	//	}
	//	if (wParam&MK_SHIFT)
	//	{
	//		wcscat(str, L"按下shirt");
	//	}
	//	if (wParam&MK_MBUTTON)
	//	{
	//		wcscat(str, L"按下中间键");
	//	}

	//	SetWindowText(hWnd, str);
	//	break;
	//
	//case WM_LBUTTONUP:

	//	TCHAR s[256];
	//	wsprintf(s, L"左键抬起（%d,%d）", x, y);//先按
	//	if (wParam&MK_CONTROL)
	//	{
	//		wcscat(s, L"按下了ctrol");
	//	}
	//	if (wParam&MK_RBUTTON)
	//	{
	//		wcscat(s, L"按下you");
	//	}
	//	if (wParam&MK_SHIFT)
	//	{
	//		wcscat(s, L"按下shirt");
	//	}
	//	if (wParam&MK_MBUTTON)
	//	{
	//		wcscat(s, L"按下中间键");//额外增加文字
	//	}

	//	SetWindowText(hWnd, s);
	//	break;
	//
	//case WM_LBUTTONDBLCLK:
	//{
	//	SetWindowText(hWnd,L"双击");
	//}
	//	break;

	//case WM_MOUSEMOVE://移动
	//	wsprintf(s, L"左键抬起（%d,%d）", x, y);//先按
	//	SetWindowText(hWnd, s);
	//	break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE://空格
		{
			int x = 50;
			int y = 100;
			SendMessage(hWnd, WM_LBUTTONDOWN, 0, MAKELPARAM(x, y));
		}
			break;
		case VK_SHIFT:
			SetWindowText(hWnd, L"按下shift");
			break;
		case VK_TAB:
			SetWindowText(hWnd, L"按下tab");
			break;
		case VK_F1:
			SetWindowText(hWnd, L"按下f1");
			break;
		case VK_ESCAPE:
			//关闭定时器
			KillTimer(hWnd,1);
			SetWindowText(hWnd, L"按下esc");
			break;
		case VK_RETURN:
			SetWindowText(hWnd, L"按下回车");
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
		 
	//case WM_CHAR://由按下消息和抬起消息组合成   由消息循环中的函数TranslateMessage(&msg)处理;
	//{
	//				 TCHAR ch = (TCHAR)wParam;
	//				 TCHAR sss[256];
	//				 wsprintf(sss, L"字符:%c", ch);
	//				 SetWindowText(hWnd, sss);
	//				 break;
	//}
	case WM_TIMER:
	{
		int nTimerID = wParam;
		switch (nTimerID)
		{
		case 1:
			//获取当前时间
			//俩种方法都会返回当前时间的时间戳1970年1月0时0分 到现在的秒数
			//1
			time_t tt = time(NULL);
			tm* t = localtime(&tt);
			TCHAR sz[256];
			wsprintf(sz,L"北京时间：%d-%02d-%02d %02d:%02d:%02d",t->tm_year+1900,t->tm_mon +1,t->tm_mday,t->tm_hour,t->tm_min ,t->tm_sec );
			//2
			//time_t tt;
			//time(&tt);
			SetWindowText(hWnd,sz);
			break;
		}
	}

		break;
	}

	//调用默认的窗口处理函数
	return DefWindowProc(hWnd, uMsg, wParam, IParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//1.设计窗口类
	WNDCLASS wc = { 0 };       
	//CS_VREDRAW如果移动或大小调整改变了客户区域的高度，则重绘整个窗口。
	//CS_HREDRAW整个窗口，如果移动或大小调整改变了客户区的宽度
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS/*双击信息获取*/;//窗口类的风格(窗口移动，缩放等)

	wc.lpfnWndProc = WindowProc;	 			//窗口处理函数ipfnWndProc(指向窗口过程的指针,必须使用CallWindowProc函数来调用窗口过程)
	wc.cbClsExtra = 0;								//窗口类这个结构体，额外拓展空间
	wc.cbWndExtra = 0;								//窗口实例空间大小，字节数（0则不需要开辟空间）
	                                                    
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); //运行里面的exe图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		//光标句柄
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 13));//背景颜色
	wc.lpszMenuName = NULL;							//菜单名
	wc.lpszClassName = L"rrrr";					//窗口类型名
	//2.注册窗口类
	if (0 == RegisterClass(&wc))
	{
		MessageBox(NULL, L"此程序不能正常运行在window NT上", L"温馨提示", MB_OK | MB_ICONWARNING);
		return 0;
	}

	//3.创建窗口
	//Window Style ==> WS_
	HWND hWnd = CreateWindow(
		L"rrrr",                                  //窗口类型名            
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
		MessageBox(NULL, L"窗口创建失败", L"温馨提示", MB_OK);
		return 0;
	}

	//4.显示和更新窗口
	ShowWindow(hWnd, SW_SHOW);
	/*
		SW_HIDE:隐藏
		SW_SHOW:显示
		SW_SHOWMAXIMIZED:最大化显示
		SW_SHOWMINiMIZED: 最小化显示
	*/

	UpdateWindow(hWnd);
	//5.消息循环
	//GetMessage函数的返回值为 0，只有接收到这个消息的时候：WM_QUIT
	//定义消息
	MSG msg;
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//将虚拟键消息转化为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}
	return 0;
}