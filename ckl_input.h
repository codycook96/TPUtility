#ifndef CKL_INPUT_H
#define CKL_INPUT_H

#include <iostream>
#include <vector>
#include "ckl_events.h"
#include "ckl_keylist.h"
#include <functional>
#include <Windows.h>
#include <Windowsx.h>

#include <tchar.h> 

namespace ckl{
	
	
	enum InputType{
		input_key, input_mouse, input_wheel
	};
	
	class InputEvent{
		public:
			InputType type;
			ckl::key key;
			int x;
			int y;
			bool keyDown;
			
			InputEvent(ckl::key k, bool kD): type(input_key), key(k), x(0), y(0), keyDown(kD){}
			InputEvent(int a, int b): type(input_mouse), key(ckl::key_null), x(a), y(b){} //temp set keydown true
			InputEvent(int a): type(input_wheel), key(ckl::key_null), x(a), y(0){} //temp set keydown true
	};
	

	
	class InputController{
		private:
			EventHandler<InputEvent> handler;
			
			HWND m_Wnd;
			HDC hdc;
			PAINTSTRUCT ps;
			
			HDC hdcBuffer;
			HBITMAP hBitmapBuffer;
			
			static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

			bool active;
			bool hasFocus;
			
			std::vector<bool> keyDown;

		public:
			int posX;
			int posY;
		
			InputController(){
				for(int i = 0; i < 256; i++){
					keyDown.push_back(false);
				}
				posX = 1;
				posY = 1;
			}
			
			WNDPROC getWndProc(){
				return WndProc;
			}
			
			HWND getHWND(){
				return m_Wnd;
			}
			
			void setHWND(HWND mhwnd){
				m_Wnd = mhwnd;
			}
			
			int registerHandle(std::function<void(InputEvent)> func){
				return handler.registerHandle(func);
			}
			
			bool getKeyDown(int n){
				return keyDown.at(n);
			}
			
			LRESULT InputProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
				//Get Notification even if out of focus
				switch(msg){
					case WM_CREATE:
						
						return 0;
					case WM_DESTROY:
						PostQuitMessage(0);
						return 0;
					case WM_SETFOCUS:
						hasFocus = true;
						return 0;
					case WM_KILLFOCUS:
						hasFocus = false;
						return 0;
					case WM_DISPLAYCHANGE:
						//Only gets resolution of main screen
						std::cout << "new screen resolution: (" << LOWORD(lParam) << ", " << HIWORD(lParam) << ")" << std::endl;
						return 0;
					case WM_QUERYENDSESSION:
						if (lParam == 0)
							//Computer is shutting down
						if ((lParam & ENDSESSION_LOGOFF) == ENDSESSION_LOGOFF)
							//User is logging off
						return 0;
						
					case WM_PAINT:
						/*
						//PAINTSTRUCT ps;
						
						RECT rect;
						GetClientRect(hwnd, &rect);
						
						//TCHAR greeting[400];
						//_stprintf( greeting, TEXT( "X: %d     " ), posX / 10 ) ;
						
						
						hdc = BeginPaint(hwnd, &ps);  
						
						
						
						//hdc = BeginPaint(hwnd,&ps); // actual screen DC

						hdcBuffer = CreateCompatibleDC(hdc);  // OFF screen DC

						hBitmapBuffer = CreateCompatibleBitmap(hdc,500,500);  // create memory bitmap for that off screen DC

						SelectObject(hdcBuffer,hBitmapBuffer); // Select the created memory bitmap into the OFF screen DC
						
						//FillRect(hdcBuffer, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
						
						
						// Draw a red line
						HPEN hLinePen;
						HPEN hPenOld;
						COLORREF qLineColor;
						qLineColor = RGB(255, 0, 0);
						hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
						hPenOld = (HPEN)SelectObject(hdcBuffer, hLinePen);

						MoveToEx(hdcBuffer, (posX / 10) + 100, (posY / 10) + 100, NULL);
						LineTo(hdcBuffer, (posX / 10) + 100, (posY / 10) + 100);
						
						//MoveToEx(hdc, 100, 100, NULL);
						//LineTo(hdc, 200, 200);

						SelectObject(hdcBuffer, hPenOld);
						DeleteObject(hLinePen);

						BitBlt(hdc,0,0,500,500,hdcBuffer,0,0,SRCCOPY); // copy the content of OFF screen DC to actual screen DC

						DeleteDC (hdcBuffer); // Release the OFF screen DC

						DeleteObject (hBitmapBuffer); // Free the memory for bitmap
						
						
						/*
						hdcBuffer = CreateCompatibleDC(hdc);  // OFF screen DC

						hBitmapBuffer = CreateCompatibleBitmap(hdc,rect.bottom, rect.right);  // create memory bitmap for that off screen DC

						SelectObject(hdcBuffer,hBitmapBuffer);
						
						
						FillRect(hdcBuffer, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
						
						TextOut(hdcBuffer, 5, 5, greeting, _tcslen(greeting));    
						//EndPaint(hwnd, &ps);
						
						//hdc = BeginPaint(hwnd, &ps);
						HPEN hPenOld;

						// Draw a red line
						HPEN hLinePen;
						COLORREF qLineColor;
						qLineColor = RGB(255, 0, 0);
						hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
						hPenOld = (HPEN)SelectObject(hdcBuffer, hLinePen);

						MoveToEx(hdcBuffer, (posX / 10) + 100, (posY / 10) + 100, NULL);
						LineTo(hdcBuffer, (posX / 10) + 100, (posY / 10) + 100);
						
						//MoveToEx(hdc, 100, 100, NULL);
						//LineTo(hdc, 200, 200);

						SelectObject(hdcBuffer, hPenOld);
						DeleteObject(hLinePen);
						
						BitBlt(hdc,0,0,rect.bottom,rect.right,hdcBuffer,0,0,SRCCOPY); // copy the content of OFF screen DC to actual screen DC

						DeleteDC (hdcBuffer); // Release the OFF screen DC

						DeleteObject (hBitmapBuffer);

						EndPaint(hwnd, &ps);
						*/
						return (0);
						
					case WM_ERASEBKGND:
						
						return(1);
				}
				//Get Notification only if in focus
				if(hasFocus){
					switch(msg){						
						case WM_MOVING:
							//std::cout << "window coord: (" << ((RECT*) lParam)->left << ", " << ((RECT*) lParam)->top << ")" << std::endl;
							return 0;
						/*
						case WM_ACTIVATEAPP:
							std::cout << "active app: " << id << std::endl;
							return 0;
						*/
						case WM_SIZING:
							//std::cout << "resize: (" << ((RECT*) lParam)->right - ((RECT*) lParam)->left  << ", " << ((RECT*) lParam)->bottom - ((RECT*) lParam)->top << ")" << std::endl;
							return 0;
						
						case WM_KEYDOWN:
							if(!keyDown.at(wParam)){
								handler.handle(InputEvent(ckl::getKey(wParam), true));
								keyDown.at(wParam) = true;
							}
							return 0;
						
						case WM_KEYUP:
							if(keyDown.at(wParam)){
								handler.handle(InputEvent(ckl::getKey(wParam), false));
								keyDown.at(wParam) = false;
							}
							return 0;
						
						case WM_MOUSEMOVE:
							//handler.handle(InputEvent(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)));
							return 0;
							
						case WM_LBUTTONDOWN:
							//handler.handle(InputEvent(ckl::mouse_left));
							return 0;
							
						case WM_LBUTTONUP:
							return 0;
							
						case WM_RBUTTONDOWN:
							//handler.handle(InputEvent(ckl::mouse_right));
							return 0;
							
						case WM_RBUTTONUP:
							return 0;
							
						case WM_MBUTTONDOWN:
							//handler.handle(InputEvent(ckl::mouse_middle));
							return 0;
							
						case WM_MBUTTONUP:
							return 0;
							
						case WM_MOUSEWHEEL:
							//handler.handle(InputEvent(HIWORD(wParam)));
							return 0;
					}
				}
				return DefWindowProc(hwnd, msg, wParam, lParam);
			}
		
			
			
	};
	
	LRESULT CALLBACK InputController::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){ 
		//Recover pointer to controller instance
		InputController* icptr = (InputController*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		
		//If pointer is not null then use instance proc
		if (icptr == NULL) {
			return DefWindowProc(hwnd, msg, wParam, lParam);
		} else {
			icptr->setHWND(hwnd);
			return icptr->InputProc(hwnd, msg, wParam, lParam);
		}
	}
	
}	



#endif
