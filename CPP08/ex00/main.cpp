#include "easyfind.hpp"

int main(void){
	//container_vector
	std::vector<int> container_vector;
	container_vector.push_back(1);
	container_vector.push_back(42);
	std::cout << "\n---------------------[Vector: ";
	for(std::vector<int>::iterator it = container_vector.begin(); it != container_vector.end(); it++)   
		std::cout << *it << " ";
	std::cout << "]---------------------\n";
	easyfind(container_vector, 42);

	//container_list
	std::list<int>  container_list;
	container_list.push_front(3);
	container_list.push_back(42);
	std::cout << "\n---------------------[List: ";
	for(std::list<int>::iterator it = container_list.begin(); it != container_list.end(); it++)   
		std::cout << *it << " ";
	std::cout << "]---------------------\n";
	easyfind(container_list, 42);

	container_list.pop_back();
	container_list.push_front(24);
	std::cout << "\n---------------------[List: ";
	for(std::list<int>::iterator it = container_list.begin(); it != container_list.end(); it++)   
		std::cout << *it << " ";
	std::cout << "]---------------------\n";
	easyfind(container_list, 42);

	//container_deque
	std::deque<int> container_deque;
	container_deque.push_front(2);
	container_deque.push_back(42);
	std::cout << "\n---------------------[Deque: ";
	for(std::deque<int>::iterator it = container_deque.begin(); it != container_deque.end(); it++)   
		std::cout << *it << " ";
	std::cout << "]---------------------\n";
	easyfind(container_deque, 242);
	std::cout << std::endl;
	return (0);
}