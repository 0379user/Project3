//#include "objectmodel.h"
//#include <iostream>

//namespace Core
//{
//	namespace Util
//	{
//		bool isLittleEndian()
//		{
//			int8_t a = 5; // 0101
//			std::string result = std::bitset<8>(a).to_string();
//			if (result.back() == '1')
//				return true;
//		}
//
//		void save(const  char* file, std::vector<int8_t> buffer)
//		{
//			std::ofstream out;
//			out.open(file, std::ios::app);
//			for (unsigned i = 0; i < buffer.size(); i++)
//			{
//				out << buffer[i];
//			}
//			out.close();
//		}
//
//		void retriveNsave(Root* r)
//		{
//			int16_t iterator = 0;
//			std::vector<int8_t> buffer(r->getSize());
//			std::string name = r->getName().substr(0, r->getName().size()).append(".abc");
//			r->pack(&buffer, &iterator);
//			save(name.c_str(), buffer);
//		}
//
//	}
//
//	Root::Root()
//		:
//		name("unknown"),
//		wrapper(0),
//		nameLenhgt(0),
//		size(sizeof(nameLenhgt) + sizeof(wrapper) + sizeof(size)) {}
//
//	void  Root::pack(std::vector<int8_t>*, int16_t*)
//	{
//
//	}
//
//	int32_t Root::getSize()
//	{
//		return size;
//	}
//	void Root::setName(std::string str)
//	{
//		name = str;
//		nameLenhgt = (int16_t)name.length();
//		size += nameLenhgt;
//	}
//	std::string Root::getName()
//	{
//		return name;
//	}
//
//
//
//	Primitive::Primitive()
//	{
//		size += sizeof(type);
//	}
//	void  Primitive::pack(std::vector<int8_t>* buffer, int16_t* iterator)
//	{
//		Core::encode<std::string>(buffer, iterator, name);
//		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
//		Core::encode<int8_t>(buffer, iterator, wrapper);
//		Core::encode<int8_t>(buffer, iterator, type);
//		Core::encode<int8_t>(buffer, iterator, *data);
//		Core::encode<int32_t>(buffer, iterator, size);
//
//	}
//
//	Array::Array()
//	{
//		size += sizeof(type) + sizeof(count);
//	}
//
//	void  Array::pack(std::vector<int8_t>* buffer, int16_t* iterator)
//	{
//		Core::encode<std::string>(buffer, iterator, name);
//		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
//		Core::encode<int8_t>(buffer, iterator, wrapper);
//		Core::encode<int8_t>(buffer, iterator, type);
//		Core::encode<int32_t>(buffer, iterator, count);
//		Core::encode<int8_t>(buffer, iterator, *data);
//		Core::encode<int32_t>(buffer, iterator, size);
//
//	}
//
//
//
//	Object::Object(std::string name)
//	{
//		setName(name);
//		wrapper = static_cast<int8_t>(Wrapper::OBJECT);
//		size += sizeof(count);
//	}
//
//
//	void Object::addEntitie(Root* r)
//	{
//		this->entities.push_back(r);
//		count += 1;
//		size += r->getSize();
//	}
//	void Object::pack(std::vector<int8_t>* buffer, int16_t* iterator)
//	{
//		Core::encode<std::string>(buffer, iterator, name);
//		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
//		Core::encode<int8_t>(buffer, iterator, wrapper);
//		Core::encode<int32_t>(buffer, iterator, count);
//
//		for (Root* r : entities)
//		{
//			r->pack(buffer, iterator);
//		}
//		Core::encode<int16_t>(buffer, iterator, size);
//	}
//
//	Root* Object::findByName(std::string name)
//	{
//		for (auto& r : entities)
//		{
//			if (r->getName() == name)
//			{
//				return r;
//			}
//		}
//		std::cout << "not found";
//		return new Object("ERROR: NOT FOUND");
//	}
//
//}