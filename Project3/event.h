#pragma once
#include "system.h"
#include <string>

namespace Core
{
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
	protected:
		System* system;
		EventType type;
		std::string name;
	protected:
		Event(std::string name, EventType type)
			:
			system(nullptr),
			name(name),
			type(type){}
	public:
		virtual ~Event() = default;
		inline std::string getName()const { return name; }
		inline EventType getType()const { return type; }
		void bind(System* system, Event* e) 
		{
			this->system = system;
			this->system->events.push_back(e);
		}
	public:
		virtual std::string format() const = 0;
	};


}