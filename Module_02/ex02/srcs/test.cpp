/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:01:21 by algultse          #+#    #+#             */
/*   Updated: 2024/12/03 22:06:28 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits>

void	testComparisonOperators(const Fixed &a, const Fixed &b)
{
	std::cout	<< UNDERLINE BLUE "Testing comparison operators:" RESET 
				<< std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << std::endl;
}

void	testArithmeticOperators(const Fixed &a, const Fixed &b)
{
	std::cout	<< UNDERLINE BLUE "Testing arithmetic operators:" RESET
				<< std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;

	if (b != Fixed(0)) {
		std::cout << "a / b = " << (a / b) << std::endl;
	} else {
		std::cout << "a / b = Division by zero is not allowed!" << std::endl;
	}
	std::cout << std::endl;
}

void	testIncrementDecrement(Fixed &a)
{
	std::cout	<< UNDERLINE BLUE "Testing increment and decrement operators:" RESET
				<< std::endl;
	std::cout << "Original a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << " -> " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << " -> " << a << std::endl;
	std::cout << std::endl;
}

void	testIncrementDecrement(const Fixed &b)
{
	std::cout	<< UNDERLINE BLUE "Testing increment and decrement operators:" RESET
				<< std::endl;
	std::cout << "Original b: " << b << std::endl;
	std::cout << "Increments/Decrements cannot be tested on const objects!" << std::endl;
	std::cout << std::endl;
}

void	testMinMax(const Fixed &a, const Fixed &b)
{
	std::cout	<< UNDERLINE BLUE "Testing min and max functions:" RESET
				<< std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
}
