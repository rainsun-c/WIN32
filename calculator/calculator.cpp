#include <Windows.h>
#include <stdio.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS
#define DIALOG_CLOSE 666
//IDC_BUTTON1
BOOL CALLBACK DialogPrec(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HFONT myFont = CreateFont(25, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"楷体");
		HWND fontHWND = GetDlgItem(hWnd, IDC_STATIC_sss);
		SendMessage(fontHWND, WM_SETFONT, (WPARAM)myFont, 0);
		HFONT myFont1 = CreateFont(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"楷体");
		HWND fontHWND1 = GetDlgItem(hWnd, IDC_STATIC_23);
		SendMessage(fontHWND1, WM_SETFONT, (WPARAM)myFont1, 0);
		break;
	}
	case WM_CLOSE:
		EndDialog(hWnd, DIALOG_CLOSE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
	{
		static TCHAR szShowText[100];	//最下static编辑框文字
		static TCHAR szProvText[100];	//最上static编辑框文字
		static double num = 0;			//记录当前输入的数子
		static double result = 0;		//记录结果
		static TCHAR sysbol;			//运算符标记
		static TCHAR T;					//当按下等号之后,再按运算符运算显示方式
		int wID = LOWORD(wParam);
		switch (wID)
		{
		case IDC_BUTTON0:
			if (szShowText[0] != '\0')	//防止出现0008的这种情况
			{
				wcscat(szShowText, L"0");
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);//设置编辑框输出
			}
			break;
		case IDC_BUTTON1:
			if (sysbol == 'E')	   //表示按下等号之后，再数字表示全部清空重新计算
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';		//按完数子键后，取消等号运算符的标记，
			}
			wcscat(szShowText, L"1");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);

			break;
		case IDC_BUTTON2:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"2");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);

			break;
		case IDC_BUTTON3:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"3");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
			break;
		case IDC_BUTTON4:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"4");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);

			break;
		case IDC_BUTTON5:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"5");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
			break;
		case IDC_BUTTON6:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"6");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);

			break;
		case IDC_BUTTON7:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"7");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);

			break;
		case IDC_BUTTON8:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"8");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
			
			break;
		case IDC_BUTTON9:
			if (sysbol == 'E')
			{
				memset(szShowText, 0, sizeof(szShowText));
				SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
				memset(szProvText, 0, sizeof(szProvText));
				SetDlgItemText(hWnd, IDC_STATIC_sss, L"0");
				result = 0;
				num = 0;
				sysbol = 'N';
			}
			wcscat(szShowText, L"9");
			SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
			
			break;
		case IDC_BUTTONDelete:
		{
			if (szShowText[0]!='\0')
			{
				if (wcslen(szShowText) - 1 == 0)
				{
					SetDlgItemText(hWnd, IDC_STATIC_23, L"0");
					break;
				}
				szShowText[wcslen(szShowText) - 1] = '\0';
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
			}
			break;
		}

		case IDC_BUTTONADD:
		{
			if (szShowText[0]!='\0')
			{
				if (T=='A')
				{
					result = result;
					swprintf(szProvText, L"%lf", result);
					wcscat(szProvText, L"+");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					T = 0;
				}
				else 
				{
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"+");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					num = _wtoi(szShowText);
					result = result + num;
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				memset(szShowText, 0, sizeof(szShowText));
			}
			sysbol = '+';
			break;
		}
		case IDC_BUTTONSUB:
		{
			sysbol = '-';
			if (szShowText[0] != '\0')
			{
				if (T == 'A')
				{
					result = _wtoi(szShowText);
					result = result;
					swprintf(szShowText, L"%lf", result);
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"-");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					T = 0;
				}
				else
				{
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"-");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					num = _wtoi(szShowText);
					if (result == 0)
					{
						result = num;
					}
					else
					{
						result = result - num;
					}
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				memset(szShowText, 0, sizeof(szShowText));
			}
			break;
		}
		case IDC_BUTTONcheng:
		{
			sysbol = '*';
			if (szShowText[0] != '\0')
			{
				if (T == 'A')
				{
			
					result = _wtoi(szShowText);
					result = result;
					swprintf(szShowText, L"%lf", result);
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"X");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					T = 0;
				}
				else
				{
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"X");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					num = _wtoi(szShowText);
					if (result == 0)
					{
						result = num;
					}
					else
					{
						result = result * num;
					}
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				memset(szShowText, 0, sizeof(szShowText));
			}
			break;
		}
		case IDC_BUTTONCHU:
		{
			sysbol = '/';
			if (szShowText[0] != '\0')
			{
				if (T == 'A')
				{
					result = _wtoi(szShowText);
					result = result;
					swprintf(szShowText, L"%lf", result);
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"/");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					T = 0;
				}
				else
				{
					wcscat(szProvText, szShowText);
					wcscat(szProvText, L"/");
					SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
					num = _wtoi(szShowText);
					if (result == 0)
					{
						result = num;
					}
					else
					{
						result = result / num;
					}
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				memset(szShowText, 0, sizeof(szShowText));
			}
			break;
		}
		case IDC_BUTTONQ:
		{
			switch (sysbol)
			{
			case '+':
			{
				wcscat(szProvText, szShowText);
				wcscat(szProvText, L"=");
				SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
				num = _wtoi(szShowText);
				result = result + num;
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				break;
			}
			case'-':
			{
				wcscat(szProvText, szShowText);
				wcscat(szProvText, L"=");
				SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
				num = _wtoi(szShowText);
				if (result == 0)
				{
					result = num;
				}
				else
				{
					result = result - num;
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				break;
			}

			case '*':
			{
				wcscat(szProvText, szShowText);
				wcscat(szProvText, L"=");
				SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
				num = _wtoi(szShowText);
				if (result == 0)
				{
					result = num;
				}
				else
				{
					result = result * num;
				}
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				break;
			}
			case '/':
			{
				wcscat(szProvText, szShowText);
				wcscat(szProvText, L"=");
				SetDlgItemText(hWnd, IDC_STATIC_sss, szProvText);
				num = _wtoi(szShowText);
				result = result / num;
				swprintf(szShowText, L"%lf", result);
				SetDlgItemText(hWnd, IDC_STATIC_23, szShowText);
				break;
			}

			}
			sysbol = 'E';
			T = 'A';
		}
			break;
		case IDC_BUTTONcls:
			memset(szShowText, 0, sizeof(szShowText));
			SetDlgItemText( hWnd ,IDC_STATIC_23 , L"0");
			memset(szProvText, 0, sizeof(szProvText));
			SetDlgItemText( hWnd ,IDC_STATIC_sss, L"0");
			result = 0;
			num = 0;
			sysbol = 0;
			T = 0;
			break;
		}

	}
	
	}
	return FALSE;
}
int WINAPI WinMain(HINSTANCE hlnstance,HINSTANCE hPrevInstance,LPSTR ipCmdLine,int nCmdShow)
{
	DialogBox(hlnstance, MAKEINTRESOURCE(IDD_CAL),NULL,DialogPrec);
	return 0;
}
