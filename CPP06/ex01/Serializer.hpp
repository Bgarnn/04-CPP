#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "DataStructure.hpp"

class Serializer{
	private:
		Serializer(void);
	public:
		Serializer(Serializer const &inst);
		Serializer &operator=(Serializer const &inst);   
		~Serializer(void);
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif