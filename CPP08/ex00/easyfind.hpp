#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

#include <vector>
#include <list>
#include <deque>

template <typename T>
void easyfind(T const& container, int const val){

	if (std::find(container.begin(), container.end(), val) != container.end())
		std::cout << val << " : found\n";
	else
		std::cout << val << " : not found\n";
}

#endif