#pragma once
#include <iostream>
#include "event.h"
#include <string>
#include <vector>


namespace Core
{
	class System 
	{
	public:
		friend class Event;
		friend class Window;
		System(std::string str);
		~System();
		void addEvent(Event&);
		Event* getEvent();
		bool isActive();
		std::vector<std::string> event_messedge;
	private:
		std::vector<Event*> events;
		std::string name;
		bool active;
		int32_t descriptor;
		int16_t index;
	};

}
