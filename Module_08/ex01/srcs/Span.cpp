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
	if (_numbers.size() == _maxSize)
		throw SpanFullException();
	_numbers.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
}

long long	Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	long long minSpan = std::numeric_limits<long long>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		long long diff = static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]);
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return (minSpan);
}

long long	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<long long>(max) - static_cast<long long>(min));
}

std::vector<int>	Span::getNumbers() const {
	return (_numbers);
}

unsigned int	Span::getSize() const {
	return (_maxSize);
}

const char	*Span::SpanFullException::what() const throw() {
	return (RED DIM "Span is full! Cannot add more numbers." RESET);
}

const char	*Span::NotEnoughNumbersException::what() const throw() {
	return (YELLOW DIM "Not enough numbers in Span to calculate a span!" RESET);
}
