#pragma once

#include "system.h"
#include <string>
#include <random>


namespace Core
{
	class System;

	class Event
	{
	public:
		enum class EventType : int8_t
		{
			MOUSE_MOVED_EVENT = 1,
			MOUSE_SCROLLED_EVENT,
			MOUSE_BUTTON_PRESSED_EVENT,
			MOUSE_BUTTON_RELEASED_EVENT,
			KEY_PRESSED_EVENT,
			KEY_RELEASED_EVENT,
			WINDOW_RESIZED_EVENT,
			WINDOW_CLOSE_EVENT
		};
	private:
		int32_t ID;
	protected:
		EventType type;
		std::string name;
	protected:
		System* system=nullptr;
		Event(std::string name, EventType type)
			:
			name(name),
			type(type)
		{
		//random
			std::random_device rd;
			std::uniform_int_distribution<> destr(1, 100);
			this->ID = destr(rd);
		
		}
	public:
		virtual ~Event() = default;
		inline std::string getName()const { return name; }
		inline EventType getType()const { return type; }
		int32_t getID() { return ID; }
		/*void bind(System* system, Event* e) 
		{
			this->system = system;
			this->system->events.push_back(e);
		}*/
	public:
		virtual std::string format() const = 0;
	};


}