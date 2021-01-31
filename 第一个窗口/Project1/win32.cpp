#include <windows.h>
#include "resource2.h"
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
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM/*unsigned int*/ wParam, LPARAM/*long*/ IParam)
{
	switch (uMsg)
	{
	case WM_CLOSE://窗口关闭消息
		DestroyWindow(hWnd);//销毁窗口
		break;
	case WM_DESTROY://窗口销毁消息
		PostQuitMessage(0);//wm_QUIT;
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
	wc.lpszClassName = L"斗战胜佛";					//窗口类型名
	//2.注册窗口类
	if (0 == RegisterClass(&wc))
	{
		MessageBox(NULL, L"此程序不能正常运行在window NT上", L"温馨提示", MB_OK | MB_ICONWARNING);
		return 0;
	}

	//3.创建窗口
	//Window Style ==> WS_
	HWND hWnd = CreateWindow(
		L"斗战胜佛",                                  //窗口类型名            
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
		//讲虚拟键消息转化为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}
	return 0;
}