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
		friend Core::Event;
		System(std::string str);
		~System();
		void addEvent(Event*);
		Event* getEvent();
		bool isActive();
		std::vector<Event*> events;
	private:
		std::string name;
		bool active;
		int32_t descriptor;
		int16_t index;
	};

}
