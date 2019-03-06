#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include <Windows.h>
//#include <sstream>
//#include <thread>
//#include <mutex>



#include "ckl_window.h"
#include "ckl_input.h"

#include <fcntl.h>
#include <io.h>
#include <cstdint>

	
int WINAPI WinMain( HINSTANCE hInstance,
					HINSTANCE hPrevinstance,
					LPTSTR lpCmdline,
					int nCmdshow )	
{
    
	

	
	
	ckl::InputController ic; 
	//ckl::InputController ic2;
	
	ckl::Window mywind(&ic, "Window 1", 500, 500);
	mywind.show();
	
	//ckl::Window mywind2(&ic2, "Window 2", 500, 500, 500, 500);
	//mywind2.show();
	
	MSG msg;
	
	int keyGet = 0x41;
	bool console = false;
	bool f5Down = false;
	
	RECT r = {0, 0, 500, 500};
	
	while(true){
		
		if(ic.getKeyDown(0x74) & !f5Down){
			f5Down = true;
		}
		
		if(!ic.getKeyDown(0x74) & f5Down){
			break;
			f5Down = false;
		}
		
		if(ic.getKeyDown(0x70) && !ic.getKeyDown(0x71)){
			if(!console){
				
				AllocConsole();
				
				HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
				int hCrt = _open_osfhandle((intptr_t) handle_out, _O_TEXT);
				FILE* hf_out = _fdopen(hCrt, "w");
				setvbuf(hf_out, NULL, _IONBF, 1);
				*stdout = *hf_out;

				HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
				hCrt = _open_osfhandle((intptr_t) handle_in, _O_TEXT);
				FILE* hf_in = _fdopen(hCrt, "r");
				setvbuf(hf_in, NULL, _IONBF, 128);
				*stdin = *hf_in;
			
			console = true;
			}
		}
		
		if(ic.getKeyDown(0x71) && !ic.getKeyDown(0x70)){
			if(console){	
			console = false;
			FreeConsole();
			}
		}
		
		if(ic.getKeyDown(0x44)){
			if(ic.posX < 100){
				std::cout << "posx: " << 
				ic.posX += 5;
			}
			InvalidateRect(ic.getHWND(), &r, TRUE);
		}
		if(ic.getKeyDown(0x41)){
			ic.posX -= 5;
			InvalidateRect(ic.getHWND(), &r, TRUE);
		}
		if(ic.getKeyDown(0x57)){
			ic.posY -= 5;
			InvalidateRect(ic.getHWND(), &r, TRUE);
		}
		if(ic.getKeyDown(0x53)){
			ic.posY += 5;
			InvalidateRect(ic.getHWND(), &r, TRUE);
		}
		
		
		
		if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)){
			if(msg.message == WM_QUIT){
				//std::cout << "Quit" << std::endl;
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

