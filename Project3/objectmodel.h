#pragma once
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

namespace Core
{
	namespace Util
	{
		bool isLittleEndian();
	}
	template<typename T>
	void encode(std::vector<int8_t>* buffer, int16_t *iterator, T value);


	enum class Wrapper : int8_t
	{
	PRIMITIVE=1,
	ARRAY,
	STRING,
	OBJECT	
	};
	enum class Type : int8_t
	{
		I8=1,
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
	void virtual pack(std::vector<int8_t>*, int16_t *);
	int32_t getSize();
	void setName(std::string str);
	std::string getName();

};


class Primitive : public Root
{
private:
	int8_t type = 0;
	std::vector<int8_t>* data=nullptr;
private:
	Primitive();
public:
	void pack(std::vector<int8_t>*, int16_t*);
	static Primitive* createI32(std::string name, Type type, int32_t value);
};

class Array : public Root
{

};

class Object : public Root
{

};

}