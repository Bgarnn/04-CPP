#include "PmergeMe.hpp"

/*   Orthodox Canonical   */

template <typename Container, typename T>
PmergeMe<Container, T>::~PmergeMe(void) {}

template <typename Container, typename T>
PmergeMe<Container, T>::PmergeMe(const PmergeMe &inst) {
	*this = inst;
}

template <typename Container, typename T>
PmergeMe<Container, T> &PmergeMe<Container, T>::operator=(const PmergeMe &inst) {
	if (this != &inst) {
		_storage = inst._storage;
		_remaining_num = inst._remaining_num;
		_time_end = inst._time_end;
	}
	return *this;
}

template <typename Container, typename T>
PmergeMe<Container, T>::PmergeMe(void) : _storage(), _remaining_num(-1), _time_end(0) {}

/*   initiate object   */

template <typename Container, typename T>
PmergeMe<Container, T>::PmergeMe(char **arg) : _storage(), _remaining_num(-1), _time_end(0) {
	try {
		std::stringstream stream;
		std::string num_str;

		for (std::size_t i = 0; arg[i] != NULL; i++) {
			stream.clear();
			stream.str(arg[i]);
			while (stream >> num_str) { 
				validate_storage(num_str);
			}
		}
		is_sort();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << std::endl << DEFAULT;
		exit(1);
	}
}

/*   validate and store input   */

template <typename Container, typename T>
void PmergeMe<Container, T>::validate_storage(const std::string &num_str) {
	//validate
	if (num_str.empty())
		throw std::invalid_argument("Error: empty argument");
	if (num_str[0] == '-')
		throw std::invalid_argument("Error: negative integer");
	if (num_str[0] == '+' && num_str.length() == 1)
		throw std::invalid_argument("Error: non-integer");

	std::size_t i = (num_str[0] == '+' && num_str.length() != 0) ? 1 : 0;
	for (; i < num_str.length(); i++) {
		if (!std::isdigit(num_str[i]))
			throw std::invalid_argument("Error: non-integer");
	}

	//str to long
	std::stringstream stream(num_str);
	long num_long;
	stream >> num_long;
	if (num_long > INT_MAX)
		throw std::overflow_error("Error: overflow");

	//store
	_storage.push_back(num_long);
	
}

template <typename Container, typename T>
void PmergeMe<Container, T>::is_sort(void) {
	if (_storage.size() == 0)
			throw std::invalid_argument("Error: empty argument");

	typename Container::iterator it = _storage.begin();
	typename Container::iterator next_it = it;
	++next_it;
	for (; next_it != _storage.end(); ++it, ++next_it) {
		if (*it > *next_it)
			break;
	}
	if (next_it == _storage.end())
		throw std::invalid_argument("All integers are sorted");
}

/*   sorting   */

template <typename Container, typename T>
void PmergeMe<Container, T>::merge_insertion_sort(void) {
	std::clock_t begin = std::clock();

	//build and sort within each pair
	T pairs_container = build_pairs(); 

	//ascending sort <second number of each pair>
	sort_pairs(pairs_container); //correct

	//main chain 1: add <first pair> + <all second number of other pair>
	_storage.clear();
	_storage.push_back(pairs_container.front().first);
	typename T::iterator it;
	for (it = pairs_container.begin(); it != pairs_container.end(); ++it) {
		_storage.push_back(it->second);
	}

	//main chain 2: add <first number of remaining pairs>
	for (it = ++pairs_container.begin(); it != pairs_container.end(); ++it) {
		typename Container::iterator index_to_insert = binary_search(_storage.begin(), _storage.end(), it->first);
		_storage.insert(index_to_insert, it->first);
	}

	//main chain 3: add <remaining number>
	if (_remaining_num != -1) {
		typename Container::iterator index_to_insert = binary_search(_storage.begin(), _storage.end(), _remaining_num);
		_storage.insert(index_to_insert, _remaining_num);
	}

	_time_end = static_cast<double>(std::clock() - begin) / CLOCKS_PER_SEC * 1000000;
}

//build and sort within each pair
template <typename Container, typename T>
T PmergeMe<Container, T>::build_pairs(void) {
	T new_pairs_container;

	//store _remaining_num & remove from _storage
	if (_storage.size() % 2 != 0) {
		_remaining_num = _storage.back();
		_storage.pop_back();
	}

	//sort within pair
	typename Container::iterator it = _storage.begin();
	while (it != _storage.end()) {
		typename Container::iterator next_it = it;
		++next_it;
		if (next_it == _storage.end())
			break;
		if (*it > *next_it)
			std::swap(*it, *next_it);
		new_pairs_container.push_back(std::make_pair(*it, *next_it));
		it = ++next_it;
	}

	return new_pairs_container;
}

//ascending sort <second number of each pair>
template <typename Container, typename T>
void PmergeMe<Container, T>::sort_pairs(T &pairs_container) {
	//no pair, @recursive sorting: return when 1 pair left --> start merge when 2 pair @compare & merge step
	if (pairs_container.size() <= 1)
		return;

	//create 2 containers (for each half)
	typename T::iterator middle_pair = pairs_container.begin();
	std::advance(middle_pair, pairs_container.size() / 2); //void advance (InputIterator& it, Distance n);
	T left_half_container(pairs_container.begin(), middle_pair);
	T right_half_container(middle_pair, pairs_container.end());

	//recursive sorting for each half
	sort_pairs(left_half_container);
	sort_pairs(right_half_container);

	//start @compare & merge step
	pairs_container.clear();
	typename T::iterator left_it = left_half_container.begin();
	typename T::iterator right_it = right_half_container.begin();

	//compare <second number of pair> -> add <lesser number> into <pairs_container>
	while (left_it != left_half_container.end() && right_it != right_half_container.end()) {
		if (left_it->second < right_it->second)
			pairs_container.push_back(*left_it++);
		else
			pairs_container.push_back(*right_it++);
	}

	//add <remaining pair> from <half container> into <pairs_container>
	//if no <pair> left in each <half container> -> will not insert any element
	pairs_container.insert(pairs_container.end(), left_it, left_half_container.end()); 
	pairs_container.insert(pairs_container.end(), right_it, right_half_container.end()); 
	//.insert(1, 2, 3)
	//	1: where the new elements should be inserted (inserted at the end)
	//	2, 3: range of elements to be inserted (2: start, 3: end) 
}

//search for where to insert index within <main chain>
template <typename Container, typename T>
typename Container::iterator PmergeMe<Container, T>::binary_search(typename Container::iterator begin_it, typename Container::iterator end_it, int needle_int) {
	typename Container::iterator left_it = begin_it;
	typename Container::iterator right_it = end_it;

	while (left_it != right_it) {
		//mark the <middle number> within <main chain> 
		typename Container::difference_type search_range_middle = std::distance(left_it, right_it) / 2;
		typename Container::iterator middle_it = left_it;
		for (typename Container::difference_type i = 0; i < search_range_middle; ++i) {
			++middle_it;
		}
		//mark new <boarder> of <search range>
		if (*middle_it < needle_int)
			left_it = ++middle_it;
		else
			right_it = middle_it;
	}
	return left_it;
}

/*   Getters   */
template <typename Container, typename T>
Container PmergeMe<Container, T>::getStorage(void) const {
	return _storage;
}

template <typename Container, typename T>
double PmergeMe<Container, T>::getTime(void) const {
	return _time_end;
}

/*   Explicit instantiation   */
template class PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >;
template class PmergeMe<std::list<int>, std::list<std::pair<int, int> > >;


/*                               DEBUG                               */

//debug __build_pairs()
	// std::cout << "Pairs built & sort within pair: ";
	// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it) {
	//     std::cout << "(" << it->first << ", " << it->second << ") ";
	// }
	// std::cout << std::endl;

//debug __sort_pairs(pairs_container);
	// std::cout << "Pairs sorted (second number): ";
	// for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it) {
	//     std::cout << "(" << it->first << ", " << it->second << ") ";
	// }
	// std::cout << std::endl;

//debug main chain 1 
	// std::cout << "Main chain (first pair + second number of others): ";
	// for (typename Container::iterator sit = _storage.begin(); sit != _storage.end(); ++sit) {
	//     std::cout << *sit << " ";
	// }
	// std::cout << std::endl;

//debug main chain 2
	// std::cout << "MAin chain (insert other first number): ";
	// for (typename Container::iterator sit = _storage.begin(); sit != _storage.end(); ++sit) {
	//     std::cout << *sit << " ";
	// }
	// std::cout << std::endl;

//debug main chain 3
	// std::cout << "Main chain (insert remaining number): ";
	// for (typename Container::iterator sit = _storage.begin(); sit != _storage.end(); ++sit) {
	//     std::cout << *sit << " ";
	// }
	// std::cout << std::endl;
