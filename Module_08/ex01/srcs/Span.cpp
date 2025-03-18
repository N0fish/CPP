/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:21 by algultse          #+#    #+#             */
/*   Updated: 2025/03/17 17:59:02 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
}

int	Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++) {
		int diff = std::abs(sorted[i + 1] - sorted[i]);
		if (diff < minSpan) {
			minSpan = diff;
		}
	}

	return (minSpan);
}

int	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	int minElement = *std::min_element(_numbers.begin(), _numbers.end());
	int maxElement = *std::max_element(_numbers.begin(), _numbers.end());

	return (maxElement - minElement);
}

// template <typename Container>
// void	addNumbers(typename Container::iterator begin, typename Container::iterator end) {
// 	if (_numbers.size() + std::distance(begin, end) > _maxSize)
// 		throw SpanFullException();
// 	_numbers.insert(_numbers.end(), begin, end);
// }

std::vector<int>	Span::getNumbers() const {
	return (_numbers);
}

// ✅ Геттер для максимального размера
unsigned int	Span::getSize() const {
	return (_maxSize);
}

// ✅ Реализация исключений
const char	*Span::SpanFullException::what() const throw() {
	return ("Span is full! Cannot add more numbers.");
}

const char	*Span::NotEnoughNumbersException::what() const throw() {
	return ("Not enough numbers in Span to calculate a span!");
}
