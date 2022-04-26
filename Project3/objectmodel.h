#pragma once
#include <string>
#include <vector>
#include <bitset>
#include <fstream>


namespace Core
{
	class Root;

	namespace Util
	{
		bool isLittleEndian();

		void save(const  char* file, std::vector<int8_t> buffer);

		void retriveNsave(Root* r);
	}

	//TEMPLATES
	template<typename T>
	void encode(std::vector<int8_t>* buffer, int16_t* iterator, T value)
	{
		for (unsigned i = 0, j = 0; i < sizeof T; i++)
		{
			(*buffer)[(*iterator)++] = value >> ((sizeof(T) * 8 - 8) - ((i == 0) ? j : j += 8));
		}
	}
	template<>
	void encode<float>(std::vector<int8_t>* buffer, int16_t* iterator, float value)
	{
		int32_t result = *reinterpret_cast<int32_t*>(&value);
		encode<int32_t>(buffer, iterator, value);
	}
	template<>
	void encode<double>(std::vector<int8_t>* buffer, int16_t* iterator, double value)
	{
		int64_t result = *reinterpret_cast<int64_t*>(&value);  ////
		encode<int64_t>(buffer, iterator, value);
	}
	template<>
	void encode<std::string>(std::vector<int8_t>* buffer, int16_t* iterator, std::string value)
	{
		for (unsigned i = 0; i < value.size(); i++)
		{
			encode<int8_t>(buffer, iterator, value[i]);
		}
	}
	template<typename T>
	void encode(std::vector<int8_t>* buffer, int16_t* iterator, std::vector<T> value)
	{
		for (unsigned i = 0; i < value.size(); i++)
		{
			encode<T>(buffer, iterator, value[i]);
		}
	}
	//TEMPLATES

	enum class Wrapper : int8_t
	{
		PRIMITIVE = 1,
		ARRAY,
		STRING,
		OBJECT
	};
	enum class Type : int8_t
	{
		I8 = 1,
		I16,
		I32,
		I64,

		U8,
		U16,
		U32,
		U64,

		FLOAT,
		DOUBLE,

		BOOL
	};

	class Root
	{
	protected:
		std::string name;
		int16_t nameLenhgt;
		int8_t wrapper;
		int32_t size;
		Root();
	public:
		void virtual pack(std::vector<int8_t>*, int16_t*);
		int32_t getSize();
		void setName(std::string str);
		std::string getName();
		virtual ~Root() {}
	};


	class Primitive : public Root
	{
	private:
		int8_t type = 0;
		std::vector<int8_t>* data = nullptr;
	private:
		Primitive();
	public:
		void pack(std::vector<int8_t>*, int16_t*);
		template<typename T>
		static Primitive* create(std::string name, Type type, T value)
		{
			Primitive* p = new Primitive();
			p->setName(name);
			p->wrapper = static_cast<int8_t>(Wrapper::PRIMITIVE);
			p->type = static_cast<int8_t>(type);
			p->data = new std::vector<int8_t>(sizeof(value));
			p->size += p->data->size();
			int16_t iterator = 0;
			Core::template encode<T>(p->data, &iterator, value);

			return p;
		}
	};

	class Array : public Root
	{
	public:
		Array();

		template<typename T>
		static Array* createArray(std::string name, Type type, std::vector<T> value)
		{
			Array* p = new Array();
			p->setName(name);
			p->wrapper = static_cast<int8_t>(Wrapper::ARRAY);
			p->type = static_cast<int8_t>(type);
			p->count = value.size();
			p->data = new std::vector<int8_t>(p->count * sizeof(T));
			p->size += value.size() * sizeof(T);

			int16_t iterator = 0;
			Core::template encode<T>(p->data, &iterator, value);

			return p;
		}

		template<typename T>
		static Array* createString(std::string name, Type type, T value)
		{
			Array* str = new Array();
			str->setName(name);
			str->wrapper = static_cast<int8_t>(Wrapper::STRING);
			str->type = static_cast<int8_t>(type);
			str->data = new std::vector<int8_t>(value.size());
			str->size += value.size();
			str->count = value.size();
			int16_t iterator = 0;
			Core::template encode<T>(str->data, &iterator, value);

			return str;
		}


		void   pack(std::vector<int8_t>* buffer, int16_t* iterator);
	private:
		int8_t type = 0;
		int32_t count = 0;
		std::vector<int8_t>* data = nullptr;
	};

	class Object : public Root
	{
	private:
		std::vector<Root*> entities;
		int16_t count = 0;
	public:
		Object(std::string name);

	public:
		void addEntitie(Root* r);
		void pack(std::vector<int8_t>* buffer, int16_t* iterator);
		Root* findByName(std::string);

	};

}





namespace Core
{
	namespace Util
	{
		bool isLittleEndian()
		{
			int8_t a = 5; // 0101
			std::string result = std::bitset<8>(a).to_string();
			if (result.back() == '1')
			{
				return true;
			}
			return false;
		}

		void save(const  char* file, std::vector<int8_t> buffer)
		{
			std::ofstream out;
			out.open(file, std::ios::app);
			for (unsigned i = 0; i < buffer.size(); i++)
			{
				out << buffer[i];
			}
			out.close();
		}

		void retriveNsave(Root* r)
		{
			int16_t iterator = 0;
			std::vector<int8_t> buffer(r->getSize());
			std::string name = r->getName().substr(0, r->getName().size()).append(".abc");
			r->pack(&buffer, &iterator);
			save(name.c_str(), buffer);
		}

	}

	Root::Root()
		:
		name("unknown"),
		wrapper(0),
		nameLenhgt(0),
		size(sizeof(nameLenhgt) + sizeof(wrapper) + sizeof(size)) {}

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
	void  Primitive::pack(std::vector<int8_t>* buffer, int16_t* iterator)
	{
		Core::encode<std::string>(buffer, iterator, name);
		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
		Core::encode<int8_t>(buffer, iterator, wrapper);
		Core::encode<int8_t>(buffer, iterator, type);
		Core::encode<int8_t>(buffer, iterator, *data);
		Core::encode<int32_t>(buffer, iterator, size);

	}

	Array::Array()
	{
		size += sizeof(type) + sizeof(count);
	}

	void  Array::pack(std::vector<int8_t>* buffer, int16_t* iterator)
	{
		Core::encode<std::string>(buffer, iterator, name);
		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
		Core::encode<int8_t>(buffer, iterator, wrapper);
		Core::encode<int8_t>(buffer, iterator, type);
		Core::encode<int32_t>(buffer, iterator, count);
		Core::encode<int8_t>(buffer, iterator, *data);
		Core::encode<int32_t>(buffer, iterator, size);

	}



	Object::Object(std::string name)
	{
		setName(name);
		wrapper = static_cast<int8_t>(Wrapper::OBJECT);
		size += sizeof(count);
	}


	void Object::addEntitie(Root* r)
	{
		this->entities.push_back(r);
		count += 1;
		size += r->getSize();
	}
	void Object::pack(std::vector<int8_t>* buffer, int16_t* iterator)
	{
		Core::encode<std::string>(buffer, iterator, name);
		Core::encode<int16_t>(buffer, iterator, nameLenhgt);
		Core::encode<int8_t>(buffer, iterator, wrapper);
		Core::encode<int32_t>(buffer, iterator, count);

		for (Root* r : entities)
		{
			r->pack(buffer, iterator);
		}
		Core::encode<int16_t>(buffer, iterator, size);
	}

	Root* Object::findByName(std::string name)
	{
		for (auto& r : entities)
		{
			if (r->getName() == name)
			{
				return r;
			}
		}
		std::cout << "not found";
		return new Object("ERROR: NOT FOUND");
	}

}