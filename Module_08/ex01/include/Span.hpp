/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:33:09 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 00:45:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "Colors.hpp"

class Span {
	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
		// template <typename Container>
		// void	addNumbers(typename Container::iterator begin, typename Container::iterator end);
		template <typename Container> 
		void	addNumbers(typename Container::iterator begin, typename Container::iterator end) {
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan() const;
		int		longestSpan() const;

		std::vector<int>	getNumbers() const;
		unsigned int		getSize() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// class SpanFullException : public std::exception {
// 	public:
// 		virtual const char* what() const throw() {
// 			return ("Span is full! Cannot add more numbers.");
// 		}
// };

// class NotEnoughNumbersException : public std::exception {
// 	public:
// 		virtual const char* what() const throw() {
// 			return ("Not enough numbers in Span to calculate a span!");
// 		}
// };

#endif