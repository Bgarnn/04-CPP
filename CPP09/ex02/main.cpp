#include "PmergeMe.hpp"
#include <cstdlib>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " <numbers>" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		/*   std:: vector   */
		// Perform sorting using std::vector
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > v(av + 1); //validate and store int
		v.merge_insertion_sort(); //sorting

		// Print input numbers before sorting
		std::cout << "Before: ";
		for (int i = 1; i < ac; ++i)
			std::cout << av[i] << " ";
		std::cout << std::endl;

		// Print sorted numbers after sorting for std::vector
		std::cout << "After: ";
		std::vector<int> sortedNumbers = v.getStorage();
		for (std::vector<int>::iterator it = sortedNumbers.begin(); it != sortedNumbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Print time report for std::vector
		std::cout << "Time to process a range of " << sortedNumbers.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << v.getTime() << " us" << std::endl;

		/*   std:: list   */
		// Perform sorting using std::list
		PmergeMe<std::list<int>, std::list<std::pair<int, int> > > l(av + 1); //validate and store int
		l.merge_insertion_sort(); //sorting

		// Print time report for std::list
		std::cout << "Time to process a range of " << l.getStorage().size() << " elements with std::list : " << std::fixed << std::setprecision(5) <<l.getTime() << " us" << std::endl;

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

