#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include <fcntl.h>
#include <io.h>
#include <cstdint>

#include <Windows.h>

//#include "ckl_window.h"
//#include "ckl_input.h"
#include "ckl_menu.h"

#include "Search.h"

void doSearch();
void doCompare();
void doMap();

void gotoCursor(short x, short y);
void setCursor(bool visible, DWORD size);
void clearScreen();

std::string directory;

int WINAPI WinMain( HINSTANCE hInstance,
					HINSTANCE hPrevinstance,
					LPTSTR lpCmdline,
					int nCmdshow )	
{
    
	

	
	
	//ckl::InputController ic;
	//ckl::Window wind(&ic, "TP Utility", 500, 500);
	//wind.show();
	
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
	
	MSG msg;
	
	
	
	
	ckl::menu menuMain( "Main Menu",
		{
		ckl::option("Search for term", &doSearch),
		ckl::option("Compare procedures", &doCompare),
		ckl::option("Map out program", &doMap)
		}
	);
	
	//RECT r = {0, 0, 500, 500};
	
	
	//std::string directory;

	bool key_w = true;
	bool key_s = true;
	
	bool key_up = true;
	bool key_down = true;
	
	bool key_enter = true;
	bool key_escape = true;
	
	setCursor(false, 20);
	
	
	
	std::cout << "Enter directory of LS files: " << std::endl;
	std::getline(std::cin, directory);
	//std::cin >> directory;
	
	
	menuMain.open();

	while(true){
		
		
		//Up
		if(GetAsyncKeyState(0x57) && !key_w){
			key_w = true;
			menuMain.prev();
		}
		if(!GetAsyncKeyState(0x57)){
			key_w = false;
		}
		
		if(GetAsyncKeyState(0x26) && !key_up){
			key_up = true;
			menuMain.prev();
		}
		if(!GetAsyncKeyState(0x26)){
			key_up = false;
		}
		
		
		//Down
		if(GetAsyncKeyState(0x53) && !key_s){
			key_s = true;
			menuMain.next();
		}
		if(!GetAsyncKeyState(0x53)){
			key_s = false;
		}
		
		if(GetAsyncKeyState(0x28) && !key_down){
			key_down = true;
			menuMain.next();
		}
		if(!GetAsyncKeyState(0x28)){
			key_down = false;
		}
		
		//Enter
		//0x0D
		if(GetAsyncKeyState(0x0D) && !key_enter){
			key_enter = true;
			menuMain.select();
		}
		if(!GetAsyncKeyState(0x0D)){
			key_enter = false;
		}
		
		
		//menuMain.print(std::cout);
		
		if(menuMain.checkUpdate()){
			clearScreen();
			menuMain.print(std::cout);
			std::cout << "\nWorking Directory: " << directory << std::endl;
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

void gotoCursor(short x, short y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void setCursor(bool visible, DWORD size){
	if(size <= 0 || size >= 100){
		size = 20;
	}

	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
}

void clearScreen(){
	gotoCursor(0, 0);
	for(int i = 0; i < 10; i++){
		std::cout << "                                                                                                      " << std::endl;
	}
	gotoCursor(0, 0);
}

void doSearch(){
	std::string searchTerm;
	
	clearScreen();
	std::cout << "Enter search term: ";
	while(GetAsyncKeyState(0x0D)){}
	std::cout << "searching.." << std::endl;
	clearScreen();
	
	std::getline(std::cin, searchTerm);
	search(searchTerm, directory);
	//std::cin >> s;
}

void doCompare(){
	std::string s;
	std::cout << "compare" << std::endl;
	//std::cin >> s;
}

void doMap(){
	std::string s;
	std::cout << "traverse" << std::endl;
	//std::cin >> s;
}