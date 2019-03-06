#ifndef CKL_EVENTS_H
#define CKL_EVENTS_H

#include <thread>
#include <vector>
#include <mutex>
#include <functional>

#include <string>

namespace ckl{

	/*
	class Event{
		private:
			std::string s:
		public:
			std::string t;
	};
	*/
	
	//Local Handler
	template <class e>
	class EventHandler{
		private:
			std::vector<std::function<void(e)>> funcs;
			
		public:
			int registerHandle(std::function<void(e)> f){
				for(int i = 0; i < funcs.size(); i++){
					if(!(funcs.at(i))) {
						funcs.at(i) = f;
						return i;
					}
				}
				funcs.push_back(f);
				return funcs.size() - 1;
			}
			
			void removeHandle(int i){
				funcs.at(i) = nullptr;
			}
			
			void handle(e e_instance){
				for(int i = 0; i < funcs.size(); i++){
					if(funcs.at(i)){
						funcs.at(i)(e_instance);
					}
				}
			}
	};
	
	//Sample Handler Usage
	//
	//std::string someVar = "some value";
	//
	//Event myEvent;
	//
	//ckl::EventHandler<Event> myHandler;
	//
	//int handleID = myHandler.registerHandle([&](Event e) -> void 
	//{ 
	//	//Do stuff with event or other things in scope of handler
	//});
	//
	// myHandler.handle(myEvent);
	
	
	/*
	//Global Manager
	class EventManager{
		private:
			std::mutex mtx;
			std::vector<EventHandler> handlers;
			std::vector<Event> buffer;
			
		public:
		
		
		
		//reg()
	};
	*/
}
#endif