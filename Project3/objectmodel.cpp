//#include "objectmodel.h"

//
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
//			std::ofstream out(file);
//			for (unsigned i = 0; i < buffer.size(); i++)
//			{
//				out << buffer[i];
//			}
//			out.close();
//		}
//
//		void retriveNsave(Core::Root* r)
//		{
//			int16_t iterator = 0;
//			std::vector<int8_t> buffer(r->getSize());
//			std::string name = r->getName().substr(0, r->getName().size()).append(".ttc");
//			r->pack(&buffer, &iterator);
//			save(name.c_str(), buffer);
//		}
//	}
//
//	
//
//	Root::Root()
//	:
//	name("unknown"),
//	wrapper(0),
//	nameLenhgt(0),
//	size(sizeof(nameLenhgt)+sizeof(wrapper)+sizeof(size)){}
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
//}