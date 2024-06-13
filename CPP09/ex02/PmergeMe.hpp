#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <exception>
#include <climits>
#include <iterator>
#include <cstdlib>

template <typename Container, typename T>
class PmergeMe {
public:
	PmergeMe(void);
	PmergeMe(char **arg);
	~PmergeMe(void);
	PmergeMe(const PmergeMe &inst);
	PmergeMe &operator=(const PmergeMe &inst);

	void merge_insertion_sort(void);
	Container getStorage(void) const;
	double getTime(void) const;
	
private:
	Container	_storage;
	int			_remaining_num;
	double		_time_end;

	void validate_storage(const std::string &num_str);
	void is_sort(void);
	T build_pairs(void);
	void sort_pairs(T &pairs);
	typename Container::iterator binary_search(typename Container::iterator begin, typename Container::iterator end, int needle);
};

#endif
