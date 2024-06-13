#include "Serializer.hpp"
# define YELLOW		"\033[33m"
# define GREEN		"\033[32m"
# define DEFAULT	"\033[0m"

int main(void){

	std::cout << YELLOW << "\n------------------------[Serialize: (Data*)-->(uintptr_t)]------------------------\n" << DEFAULT;
	Data 		*data_ptr_address_1 = new Data();
	data_ptr_address_1->dataChar = 'A';
	data_ptr_address_1->dataInt = 100;
	
	std::cout << "-->(data_ptr_address_1) --> " << data_ptr_address_1 << '\n';
	std::cout << "                        --> name: " << data_ptr_address_1->dataChar << '\n';
	std::cout << "                        --> age : " << data_ptr_address_1->dataInt << '\n';

	std::cout << "-->[uintptr_t uintptr_t_address = Serializer::serialize(data_ptr_address_1)]\n";
	uintptr_t	uintptr_t_address = Serializer::serialize(data_ptr_address_1); // convert the memory address held by the pointer from hexa to uint pointer.
	
	std::cout << "-->(uintptr_t_address): " << uintptr_t_address << '\n';

	std::cout << GREEN << "\n------------------------[Deserialize: (uintptr_t)-->(Data*)]------------------------\n" << DEFAULT;
	std::cout << "-->(uintptr_t_address): " << uintptr_t_address << '\n';

	Data 		*data_ptr_address_2 = Serializer::deserialize(uintptr_t_address);
	std::cout << "-->[Data *data_ptr_address_2 = Serializer::deserialize(uintptr_t_address)]\n";

	std::cout << "-->(data_ptr_address_2) --> " << data_ptr_address_2 << '\n';
	std::cout << "                        --> name: " << data_ptr_address_2->dataChar << '\n';
	std::cout << "                        --> age : " << data_ptr_address_2->dataInt << "\n\n";  
	return(0);
}