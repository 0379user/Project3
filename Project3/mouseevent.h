#pragma once
#include "event.h"


namespace Core
{
	class MouseMovedEvent : public Event
	{
	private:
		double x, y;
	public:
		MouseMovedEvent(double x, double y)
			:
			Event("Mouse moved Event", Event::EventType::MOUSE_MOVED_EVENT),
			x(x),
			y(y) {}
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
			offset(offset) {}
	public:
		std::string format() const override
		{
			std::string formatted = "";
			return (offset > 0) ? formatted = name + " : " + "up " : formatted = name + " : " + "down ";
		}
	};


	class MouseButtonPressedEvent : public Event
	{
	private:
		int button;
	public:
		MouseButtonPressedEvent(int button)
			:
			Event("Mouse button pressed", Core::Event::EventType::MOUSE_BUTTON_PRESSED_EVENT),
			button(button)
		{}
	public:
		std::string format() const override
		{
			std::string formatted = name + " : " + std::to_string(button);
			return formatted;
		}



	};


	class MouseButtonReleasedEvent : public Event
	{
	private:
		int button;
	public:
		MouseButtonReleasedEvent(int button)
			:
			Event("Mouse button released", Core::Event::EventType::MOUSE_BUTTON_RELEASED_EVENT),
			button(button) {}
	public:
		std::string format() const override
		{
			std::string formatted = name + " : " + std::to_string(button);
			return formatted;
		}
	};

}