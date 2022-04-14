#include "system.h"


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
void System::addEvent(Event* e)
{
	//e->bind(this, e);
}

Event* System::getEvent() 
{
	//return events.front();
}
bool System::isActive()
{
	//if(!system)
//	{
//		return false;
//	}
	return true;
}


}