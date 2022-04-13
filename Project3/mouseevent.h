#pragma once
#include "event.h"


namespace Core
{
	class MouseMovedEvent : public Event
	{
	private:
		int x, y;
	public:
		MouseMovedEvent(int x,int y)
			:
			Event("Mouse moved Event", Event::EventType::MOUSE_MOVED_EVENT),
			x(x),
			y(y){}
	public:
		std::string format() const override
		{
			std::string formatted = name + ": " + std::to_string(x) + " " + std::to_string(y);
			return formatted;
		}
	};

	class MouseScrolledEvent : public Event
	{
	private:
		int offset;
	public:
		MouseScrolledEvent(int offset)
			:
			Event("Mouse Scrolled Event", Event::EventType::MOUSE_SCROLLED_EVENT),
			offset(offset){}
	public:
		std::string format() const override
		{
			std::string formatted = "";
			return (offset > 0) ? formatted = name + " : " + "up " : formatted = name + " : " + "down ";
		}
	};

}