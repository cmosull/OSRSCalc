
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
#include <process.h>	/* needed for multithreading */
#include <string.h>
#include "resource.h"
#include "globals.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nCmdShow)

{
	MSG			msg;
	HWND		hWnd;
	WNDCLASS	wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, "ID_PLUS_ICON");
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = "ID_MAIN_MENU";
	wc.lpszClassName = "OSRSCalculator";

	if (!RegisterClass(&wc))
		return(FALSE);

	hWnd = CreateWindow("OSRSCalculator", "OSRS Calculator",
		WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
		0, 0, WINWIDTH, WINHEIGHT, NULL, NULL, hInstance, NULL);
	if (!hWnd)
		return(FALSE);

	ShowScrollBar(hWnd, SB_BOTH, FALSE);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	MainWnd = hWnd;

	InvalidateRect(hWnd, NULL, TRUE);
	UpdateWindow(hWnd);

	ShowXPNeededExp = 0;
	ShowXPNeededLevel = 0;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return(msg.wParam);
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)

{
	HMENU				hMenu;
	HDC					hDC;

	switch (uMsg)
	{
	case WM_CREATE:
		LoadInitialImages();
		AddInitialControls(hWnd,WINWIDTH,WINHEIGHT);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_GOAL_EXPERIENCE:
			ShowXPNeededExp = (ShowXPNeededExp + 1) % 2;
			break;
		case ID_GOAL_LEVEL:
			break;
		case ID_FILE_QUIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_SIZE: /* could be used to detect when window size changes */
		NewWidth = LOWORD(lParam);
		NewHeight = HIWORD(lParam);
		LoadInitialImages();
		AddInitialControls(hWnd, NewWidth, NewHeight);
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_PAINT:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_LBUTTONDOWN:case WM_RBUTTONDOWN:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_MOUSEMOVE:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_KEYDOWN:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_TIMER:	  /* this event gets triggered every time the timer goes off */
		break;
	case WM_HSCROLL:	  /* this event could be used to change what part of the image to draw */
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_VSCROLL:	  /* this event could be used to change what part of the image to draw */
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return(DefWindowProc(hWnd, uMsg, wParam, lParam));
		break;
	}

	hMenu = GetMenu(MainWnd);
	if (ShowXPNeededExp == 1) {
		CheckMenuItem(hMenu, ID_GOAL_EXPERIENCE, MF_CHECKED);
	}
	else {
		CheckMenuItem(hMenu, ID_GOAL_EXPERIENCE, MF_UNCHECKED);
	}

	DrawMenuBar(hWnd);

	return(0L);
}

void AddInitialControls(HWND hWnd, int width, int height) {

	hMainLogo = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_REALSIZECONTROL, CW_USEDEFAULT, 0, width, height, hWnd, NULL, NULL, NULL);
	SendMessage(hMainLogo, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM) hMainLogoImage);
}

void LoadInitialImages() {
	if (IsDebuggerPresent()) {
		GetCurrentDirectory(MAXBUFFLEN, InitialDirectory);
		strcat(InitialDirectory, "\\src\\runescape_oldschool_logo.bmp");
		hMainLogoImage = (HBITMAP)LoadImage(NULL, InitialDirectory, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	else {
		hMainLogoImage = (HBITMAP)LoadImage(NULL, "..\\src\\runescape_oldschool_logo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	
}

void AddXPNeededControls(HWND hWnd, int width, int height) {
	


}

void LoadXPNeededImages() {

}






