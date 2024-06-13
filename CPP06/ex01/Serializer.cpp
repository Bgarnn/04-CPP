#include "Serializer.hpp"

Serializer::Serializer(void){
	std::cout << "Serializer Constructor created" << '\n';
}
Serializer::Serializer(Serializer const &inst){
	*this = inst;
}
Serializer::~Serializer(void){
	std::cout << "Serializer destroyed" << '\n';
}

Serializer &Serializer::operator=(Serializer const &inst){
	(void)inst;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *> (raw);
}
