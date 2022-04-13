#pragma once
#include "event.h"

namespace Core
{
	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int key)
			:
			Event("Key pressed event", Core::Event::EventType::KEY_PRESSED_EVENT),
			key(key){}
		std::string format() const override 
		{
			std::string formatted = name + " : " + (char)key;
			return formatted;
		}
	private:
		int key;
	};
	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int key)
			:
			Event("Key released event", Core::Event::EventType::KEY_PRESSED_EVENT),
			key(key) {}
		std::string format() const override
		{
			std::string formatted = name + " : " + (char)key;
			return formatted;
		}
	private:
		int key;
	};


}