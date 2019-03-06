#ifndef CKL_MENU_H
#define CKL_MENU_H

#include <vector>
#include <iostream>

namespace ckl{
	
	typedef void (*fptr)();
	
	class menu;
	void menuOpen(menu* m);

	class option {
	private:
		std::string text;
		fptr function;
		menu* submenu;
		
	public:
		option(std::string t) : text(t) {}
		option(std::string t, void(*f)()) : text(t), function(f) { submenu = nullptr; }
		option(std::string t, menu& m) : text(t), submenu(&m) { function = nullptr; }
		option(const option &o){ 
			text = o.text;
			function = o.function;
			submenu = o.submenu;
		}
		
		std::string getText(){
			return text;
		}
		
		void select() {
			if (function != nullptr) {
				function();
			}
			if (function == nullptr) {
				menuOpen(submenu);
			}
		}
	};


	class menu{
		private:
			menu* parent;
			std::string title;
			std::vector<option> options;
			int selection;
			bool update;
			//bool menuOpen;
			
		public:
			menu(std::string t, std::vector<option> o) : title(t), options(o) {
				//menuOpen = false; 
				selection = 0;
				update = false;
			}
		
			menu(std::vector<option> o) : options(o) {
				//menuOpen = false; 
				selection = 0;
				update = false;
			}
			menu(std::vector<option> o, menu* p) : options(o), parent(p) {
				//menuOpen = false; 
				selection = 0;
				update = false;
			}
		
		
		void open(){
			update = true;
			//menuOpen = true;
			//while(run){
				//for (int i = 0; i < options.size(); i++) {
				//	options.at(i).select();
				//}	
			//}		
		}
		
		//void close(){
		//	menuOpen() = false;
		//}
		
		void select(){
			options.at(selection).select();
		}
		
		void next(){
			update = true;
			if(selection >= options.size() - 1){
				selection = 0;
			}
			else{
				selection++;
			}
		}
		
		void prev(){
			update = true;
			if (selection <= 0 ){
				selection = options.size() - 1;
			}
			else{
				selection--;
			}
		}
		
		void set(int i){
			update = true;
			selection = i;
		}
		
		int getSelection(){
			return selection;
		}
		
		std::string getTextTitle(){
			return title;
		}
		
		std::string getTextOption(int i){
			return options.at(i).getText();
		}
		
		bool checkUpdate(){
			return update;
		}
		
		void print(std::ostream& os){
			update = false;
			os << title << "\n";
			for(int i = 0; i < options.size(); i++){
				if(selection == i){
					os << "[X]";
				}
				else{
					os << "[ ]";
				}
				os << options.at(i).getText() << "\n";
			}
			//return os;
		}
		
	};

	void menuOpen(menu* m) {
		m->open();
	}

}

#endif