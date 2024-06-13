#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>

void iter(T *array, int size, void(*f)(T const &)) 
{
	if (size <= 0)
		std::cout << "incorrect array size: " << size << std::endl;
	for (int i = 0; i < size; i++) 
	{
		f(array[i]);
	}
}

#endif