#include "system.h"
#include "keyboardevent.h"

namespace Core 
{
System::System(std::string str)
	:
	name(str),
	descriptor(123),
	index(1),
	active(true){}
 
System::~System()
{
//TODO::
}
void System::addEvent(Event &e)
{
	event_messedge.push_back(e.format());
	 
	//what is happening
}

Event* System::getEvent() 
{
	return events.front();
}
bool System::isActive()
{
	if(!system)
	{
		return false;
	}
	return true;
}


}