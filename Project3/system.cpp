#include "system.h"
#include "keyboardevent.h"
//#include "objectmodel.h"
#include "event.h"

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
	//event_messege.push_back(e.format());
	 
	//what is happening
}

Event* System::getEvent() 
{
	return events.front();
}
 
void System::serialize()
{
	/*Core::Object system("SysInfo");
	Core::Array* name = Core::Array::createString("sysName", Core::Type::I8, this->name);
	Core::Primitive* desc = Core::Primitive::create("disc", Core::Type::I32, this->descriptor);
	Core::Primitive* index = Core::Primitive::create("index", Core::Type::I16, this->index);
	Core::Primitive* active = Core::Primitive::create("active", Core::Type::BOOL, this->active);
	system.addEntitie(name);
	system.addEntitie(desc);
	system.addEntitie(index);
	system.addEntitie(active);*/

	for(Event * e: events)
	{ 
		/*Core::KeyPressedEvent* kb = static_cast<KeyPressedEvent*>(e);*/
		
	}
}


}