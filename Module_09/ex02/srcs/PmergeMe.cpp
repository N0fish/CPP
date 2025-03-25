/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.сpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:50:42 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 23:56:44 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_vecSorted = other._vecSorted;
		_deqSorted = other._deqSorted;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ******************************** PARSING ********************************* */

bool	PmergeMe::isValidNumber(const std::string &str) const {
	if (str.empty())
		return (false);
	for (std::size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

void	PmergeMe::parseArguments(int argc, char **argv) {
	if (argc < 2) {
		throw std::runtime_error("at least one positive integer is required");
	}

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		if (!isValidNumber(arg))
			throw std::runtime_error("invalid argument: " + arg);

		long nb = std::atol(argv[i]);
		if (nb > INT_MAX)
			throw std::runtime_error("value exceeds INT_MAX: " + arg);

		for (std::size_t j = 0; j < _vector.size(); ++j) {
			if (_vector[j] == static_cast<int>(nb))
				throw std::runtime_error("duplicate value: " + arg);
		}

		int value = static_cast<int>(nb);
		_vector.push_back(value);
		_deque.push_back(value);
	}
}

/* ******************************** DISPLAY ********************************* */

void	PmergeMe::printBefore() const {
	std::cout << "🍏 Before:\t";
	for (std::size_t i = 0; i < _vector.size(); ++i) {
		std::cout << CYAN << _vector[i] << " ";
	}
	std::cout << RESET << std::endl;
}

void	PmergeMe::printAfter() const {
	std::cout << "🍎 After:\t";
	for (std::size_t i = 0; i < _vecSorted.size(); ++i) {
		std::cout << BLUE ITALIC << _vecSorted[i] << " ";
	}
	std::cout << RESET << std::endl;

	std::cout	<< "Time to process a range of " << _vector.size()
	    		<< " elements with std::vector : " 
				<< CYAN BOLD << _vectorTime << RESET << " µs"
				<< std::endl;
	std::cout	<< "Time to process a range of " << _deque.size()
	        	<< " elements with std::deque  : "
				<< BLUE BOLD << _dequeTime << RESET << " µs"
				<< std::endl;
}

/* ******************************** PAIRING ********************************* */

void	PmergeMe::buildPairs(std::vector<std::pair<int, int> > &pairs, const std::vector<int> &input) {
	for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b) {
			pairs.push_back(std::make_pair(a, b));
		} else {
			pairs.push_back(std::make_pair(b, a));
		}
	}
}

void	PmergeMe::buildPairs(std::deque<std::pair<int, int> > &pairs, const std::deque<int> &input) {
	for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b) {
			pairs.push_back(std::make_pair(a, b));
		} else {
			pairs.push_back(std::make_pair(b, a));
		}
	}
}

std::vector<int>	PmergeMe::extractMain(const std::vector<std::pair<int, int> > &pairs) {
	std::vector<int>	main;
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		main.push_back(pairs[i].second);
	}
	return (main);
}

std::deque<int>	PmergeMe::extractMain(const std::deque<std::pair<int, int> > &pairs) {
	std::deque<int>	main;
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		main.push_back(pairs[i].second);
	}
	return (main);
}

std::vector<int>	PmergeMe::extractPending(const std::vector<std::pair<int, int> > &pairs) {
	std::vector<int>	pending;
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		pending.push_back(pairs[i].first);
	}
	return (pending);
}

std::deque<int>	PmergeMe::extractPending(const std::deque<std::pair<int, int> > &pairs) {
	std::deque<int> pending;
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		pending.push_back(pairs[i].first);
	}
	return (pending);
}

/* ******************************* JACOBSTHAL ******************************* */

int	PmergeMe::getJacobsthal(size_t n) const {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2));
}

std::vector<size_t>	PmergeMe::createJacobsthalIndices(size_t size) const {
	std::vector<size_t>	indices;
	std::vector<bool>	added(size, false);

	indices.push_back(0);
	added[0] = true;

	for (size_t i = 2; ; ++i) {
		int j = getJacobsthal(i);
		if (static_cast<size_t>(j) >= size) {
			break ;
		}
		if (!added[j]) {
			indices.push_back(j);
			added[j] = true;
		}
	}

	for (size_t i = 0; i < size; ++i) {
		if (!added[i]) {
			indices.push_back(i);
		}
	}
	return (indices);
}

/* ******************************* INSERTION ******************************** */

void	PmergeMe::insertPending(std::vector<int> &main, const std::vector<int> &pending, const std::vector<size_t> &indices) {
	for (std::size_t i = 0; i < indices.size(); ++i) {
		size_t idx = indices[i];
		if (idx >= pending.size()) {
			continue ;
		}
		int value = pending[idx];
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), value);
		main.insert(pos, value);
	}
}

void	PmergeMe::insertPending(std::deque<int> &main, const std::deque<int> &pending, const std::vector<size_t> &indices) {
	for (std::size_t i = 0; i < indices.size(); ++i) {
		size_t idx = indices[i];
		if (idx >= pending.size()) {
			continue ;
		}
		int	value = pending[idx];
		std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), value);
		main.insert(pos, value);
	}
}

/* ***************************** HELPER STRUCT ****************************** */

struct CompareBySecond {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
		return (a.second < b.second);
	}
};

/* ********************************** SORT ********************************** */

void	PmergeMe::sortVector() {
	if (_vector.size() < 2) {
		_vecSorted = _vector;
		return ;
	}

	std::vector<std::pair<int, int> > pairs;
	buildPairs(pairs, _vector);

	std::sort(pairs.begin(), pairs.end(), CompareBySecond());

	std::vector<int>	main = extractMain(pairs);
	std::vector<int>	pending = extractPending(pairs);

	int	straggler = (_vector.size() % 2 != 0) ? _vector.back() : -1;
	std::vector<size_t>	indices = createJacobsthalIndices(pending.size());
	insertPending(main, pending, indices);

	if (straggler != -1) {
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler);
		main.insert(pos, straggler);
	}
	_vecSorted = main;
	_vectorTime = clock() - _vectorTime;
}

void	PmergeMe::sortDeque() {
	if (_deque.size() < 2) {
		_deqSorted = _deque;
		return ;
	}

	std::deque<std::pair<int, int> > pairs;
	buildPairs(pairs, _deque);

	std::sort(pairs.begin(), pairs.end(), CompareBySecond());

	std::deque<int>	main = extractMain(pairs);
	std::deque<int>	pending = extractPending(pairs);

	int	straggler = (_deque.size() % 2 != 0) ? _deque.back() : -1;
	std::vector<size_t>	indices = createJacobsthalIndices(pending.size());
	insertPending(main, pending, indices);

	if (straggler != -1) {
		std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler);
		main.insert(pos, straggler);
	}
	_deqSorted = main;
	_dequeTime = clock() - _dequeTime;
}

/* ******************************** EXECUTOR ******************************** */

void	PmergeMe::runSort(int argc, char **argv) {
	parseArguments(argc, argv);
	printBefore();

	_vectorTime = clock();
	sortVector();
	_vectorTime = clock() - _vectorTime;

	_dequeTime = clock();
	sortDeque();
	_dequeTime = clock() - _dequeTime;

	printAfter();
}
