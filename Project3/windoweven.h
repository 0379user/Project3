#pragma once
#include "event.h"

namespace Core
{
	class WindowReasizedEvent : public Event
	{
	public:
		WindowReasizedEvent(int wight, int height)
			:
			Event("Window Reasized Event", Core::Event::EventType::WINDOW_RESIZED_EVENT),
			wight(wight),
			height(height) {}
	public:
		std::string format() const override
		{
			std::string formatted = name + " : " + std::to_string(wight) + " " + std::to_string(height);
			return formatted;
		}
	private:
		int wight, height;
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			:
			Event("Windows closed", Core::Event::EventType::WINDOW_CLOSE_EVENT){}
	public:
		std::string format() const override
		{
			
			return name;
		}
	};

}