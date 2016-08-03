#include "stdafx.h"
#include "Game.h"
#include "SpriteBatch.h"

static TCHAR szWindowClass[] = _T("pApp01");
static TCHAR szTitle[] = _T("2D Play");

HINSTANCE hInst;
HWND hWnd;

SpriteBatch* sb = nullptr;
float gravity = 400;
Moves moves;


std::wstring gPath = L"C:/Box/Box Sync/Data/GameLib/";
std::wstring gTexturePath = L"Textures/";
std::wstring gShaderPath = L"Shaders/";
std::wstring gMeshPath = L"Meshes/";


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	RegisterClassEx(&wcex);

	hInst = hInstance; 
	hWnd = CreateWindow(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,720, 480,NULL,NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	Game game;

	MSG msg;
	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)break;
		}
		else {
			if (game.Update())break;
			game.Draw();

		}
	}
	return 0;

	return (int)msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_ACTIVATEAPP: {
			Keyboard::ProcessMessage(message, wParam, lParam);
			Mouse::ProcessMessage(message, wParam, lParam);
		} break;


		case WM_INPUT:
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MOUSEWHEEL:
		case WM_XBUTTONDOWN:
		case WM_XBUTTONUP:
		case WM_MOUSEHOVER:
			Mouse::ProcessMessage(message, wParam, lParam);
			break;

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			Keyboard::ProcessMessage(message, wParam, lParam);
			break;


		case WM_DESTROY: {
			PostQuitMessage(0);
			return 0;
		} break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}