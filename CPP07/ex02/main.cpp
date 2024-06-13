// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Array.hpp"
# define DEFAULT	"\033[0m"
# define CYAN		"\033[36m"
# define PINK		"\033[35m"

int main(void){

	std::cout << "\n--------------------------------[ Mandatory Test ]---------------------------------\n";

	std::cout << "-->[arr_int]\n";
	Array<int> arr_int(10);
	std::cout << "-->[empty_str]: (void)\n";
	Array<int> empty;
	std::cout << "-->[arr_double]\n";
	Array<double> arr_double(10);
	std::cout << "-->[arr_str]\n";
	Array<std::string> arr_str(3);


	std::cout << "-->[arr_str]\n";
	arr_str[0] = "Karn";
	arr_str[1] = "Kawin";
	for (int i = 0; i < 3; i++)
		std::cout << PINK << arr_str[i] << " ";
	std::cout << DEFAULT << '\n';


	std::cout << "-->[arr_int]\n";
	for (int i = 0; i < 10; i++)
		arr_int[i] = i + 1;
	for (int i = 0; i < 10; i++)
		std::cout << PINK << arr_int[i] << " ";
	std::cout << DEFAULT << '\n';   

	std::cout << "-->[arr_double]\n";
	for (int i = 0; i < 10; i++)
		arr_double[i] = i + 1.5;
	for (int i = 0; i < 10; i++)
		std::cout << PINK  << arr_double[i] << " ";
	std::cout << DEFAULT << '\n';


	std::cout << "\n-----------------------[ Const instance: Reading Only test ]-----------------------\n";
	
	std::cout << "-->[const_string]\n";
	const Array<std::string> const_string = static_cast <const Array<std::string> >(arr_str);
	std::cout << "-->[const_int]\n";
	const Array<int> const_int = static_cast <const Array<int> >(arr_int);
	std::cout << "-->[const_double]\n";
	const Array<double> const_double = static_cast <const Array<double> >(arr_double);

	std::cout << "-->[const_string]\n";
	for (int i = 0; i < 3; i++)
		std::cout << CYAN << const_string[i] << " ";
	std::cout << DEFAULT << '\n';

	std::cout << "-->[const_int]\n";
	for (int i = 0; i < 10; i++)
		std::cout << CYAN << const_int[i] << " ";
	std::cout << DEFAULT << '\n';

	std::cout << "-->[const_double]\n";
	for (int i = 0; i < 10; i++)
		std::cout << CYAN << const_double[i] << " ";
	std::cout << DEFAULT << "\n\n";
	
	return 0;
}
