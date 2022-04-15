#include "objectmodel.h"


namespace Core
{
	namespace Util 
	{
		bool isLittleEndian()
		{
			int8_t a = 5; // 0101
			std::string result = std::bitset<8>(a).to_string();
			if (result.back() == '1')
				return true;
		}
	}
	template<typename T>
	void encode(std::vector<int8_t> * buffer, int16_t * iterator, T value)
	{
		for (unsigned i=0, j=0; i< sizeof T; i++)
		{
			(*buffer)[(*iterator)++] = value >> ((sizeof(T)*8 - 8) - ((i==0)? j: j+=8));
		}
	}



	Root::Root()
	:
	name("unknown"),
	wrapper(0),
	nameLenhgt(0),
	size(sizeof(nameLenhgt)+sizeof(wrapper)+sizeof(size)){}

	void  Root::pack(std::vector<int8_t>*, int16_t*)
	{
	
	}

	int32_t Root::getSize() 
	{
		return size;
	}
	void Root::setName(std::string str)
	{
		name = str;
		nameLenhgt = (int16_t)name.length();
		size += nameLenhgt;
	}
	std::string Root::getName() 
	{
		return name;
	}

	Primitive::Primitive()
	{
		size += sizeof(type);
	}
	void  Primitive::pack(std::vector<int8_t>*, int16_t*)
	{

	}

	Primitive* Primitive::createI32(std::string name, Type type, int32_t value) 
	{
		Primitive* p = new Primitive();
		p->setName(name);
		p->wrapper = static_cast<int8_t>(Wrapper::PRIMITIVE);
		p->type = static_cast<int8_t>(type);
		p->data = new std::vector<int8_t>(sizeof(value));
		int16_t iterator=0;
		Core::encode(p->data, &iterator, value);

		return p;
	}
}