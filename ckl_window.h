#ifndef CKL_WINDOW_H
#define CKL_WINDOW_H

#include <Windows.h>
#include <string> 
#include <random>
#include "ckl_input.h"
#include <iostream>

std::string random_string(std::string::size_type length);

namespace ckl{
	
	class Window{	
		
		private:
			ckl::InputController* _IC;
			
			std::string _title;
			int _w;
			int _h;
			int _x;
			int _y;
			
			DWORD _wStyle;
			DWORD _wStyleEx;
			DWORD _wClassStyle;
			
			LPCTSTR   _wClassName;
			
			HINSTANCE _hInst;
			WNDPROC _wndProc;
			
			HWND _wndParent;
			HMENU _wMenu;
			HWND _wnd;
			
			WNDCLASSEX _wClass;
			
		public:
			bool registerClass(){
				
				_wClass.cbSize = sizeof(WNDCLASSEX);
				_wClass.style = _wClassStyle;
				_wClass.lpfnWndProc = _wndProc;
				_wClass.cbClsExtra = 0;
				_wClass.cbWndExtra = 0;
				_wClass.hInstance = _hInst;
				_wClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION); //icon
				_wClass.hCursor = LoadCursor(nullptr, IDC_ARROW);   //default arrow mouse cursor
				_wClass.hbrBackground = (HBRUSH)(COLOR_BACKGROUND+1);
				_wClass.lpszMenuName = nullptr; // Menu
				_wClass.lpszClassName = _wClassName; //Class
				_wClass.hIconSm = nullptr;
					
				if(!RegisterClassEx(&_wClass)){
					MessageBox(NULL, "Error Registering Window Class", 
                         "Error", MB_OK);
					return false;
				}
				
				return true;
			}
			
			
			bool createWindow(){	
				
				_wnd = CreateWindowEx(_wStyleEx, _wClassName, (LPCSTR) _title.c_str(), _wStyle, _x, _y, _w, _h, _wndParent, _wMenu, _hInst, nullptr);
				if(_wnd != nullptr){
					return false;
				}
				return true;
			}
			
			int getX(){
				RECT rect;
				if(GetWindowRect(_wnd, &rect)){
					_x = rect.left;
					return _x;
				}
			}
			
			int getY(){
				RECT rect;
				if(GetWindowRect(_wnd, &rect)){
					_y = rect.top;
					return _y;
				}
			}
			
			int getWidth(){
				RECT rect;
				if(GetWindowRect(_wnd, &rect)){
					_w = rect.right - rect.left;
					return _w;
				}
			}
			
			int getHeight(){
				RECT rect;
				if(GetWindowRect(_wnd, &rect)){
					_h = rect.bottom - rect.top;
					return _h;
				}
			}
			/*
			void testPixel(int x, int y, COLORREF color){
				HDC hdc = GetDC(_wnd);
				SetPixel(hdc, x, y, color);
				ReleaseDC(_wnd,hdc);
			}
			*/
			bool connect(){
				SetWindowLongPtr(_wnd, GWLP_USERDATA, (LONG_PTR)_IC);
			}
			
			void show(){
				ShowWindow(_wnd, SW_SHOW);
				UpdateWindow(_wnd);
			}
			
			void hide(){
				ShowWindow(_wnd, SW_HIDE);
				UpdateWindow(_wnd);
			}
			
			void minimize(){
				ShowWindow(_wnd, SW_SHOWMINNOACTIVE);
				UpdateWindow(_wnd);
			}
			
			void maximize(){
				ShowWindow(_wnd, SW_SHOWMAXIMIZED);
				UpdateWindow(_wnd);
			}
			
			void restore(){
				ShowWindow(_wnd, SW_SHOWNORMAL);
				UpdateWindow(_wnd);
			}
			
			void resize(int x, int y){
				SetWindowPos(_wnd, 0, 0, 0, x, y, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
			}
			
			void move(int x, int y){
				MoveWindow(_wnd, x, y, getWidth(), getHeight(), false);
			}
			
			//Window(){}
			
			Window(	ckl::InputController* IC, std::string title, 
					int width = CW_USEDEFAULT, int height = CW_USEDEFAULT,
					int startx = CW_USEDEFAULT, int starty = CW_USEDEFAULT,
					DWORD wStyle = (WS_OVERLAPPEDWINDOW), 
					DWORD wStyleEx = (WS_EX_OVERLAPPEDWINDOW),
					DWORD wClassStyle = (CS_HREDRAW | CS_VREDRAW),
					HINSTANCE hInst = GetModuleHandle(nullptr), HWND wndParent = nullptr, HMENU wMenu = nullptr):
					_IC(IC), _title(title), _w(width), _h(height), _x(startx), _y(starty),
					_wStyle(wStyle), _wStyleEx(wStyleEx), _wClassStyle(wClassStyle),
					_hInst(hInst), _wndParent(wndParent), _wMenu(wMenu)
			{
				_wndProc = IC->getWndProc();
				
				srand (time(NULL));
				_wClassName = (LPCSTR) (random_string(12)).c_str();
				
				registerClass();
				createWindow();
				connect();
			}
			
	};
	
}

std::string random_string(std::string::size_type length){
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
	}

#endif