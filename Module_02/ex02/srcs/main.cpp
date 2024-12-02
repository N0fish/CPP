/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:14:27 by algultse          #+#    #+#             */
/*   Updated: 2024/10/29 22:07:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	std::cout << BOLD GREEN "==== Subject Tests ====" RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << BOLD PURPLE "\n==== Custom Tests ====" RESET << std::endl;
	std::cout << INVERSE CYAN "--- Comparison Tests ---" RESET << std::endl;
	Fixed	c(42.42f);
	Fixed	d(-10);
	Fixed	g(d);

	testComparisonOperators(a, b);
	testComparisonOperators(c, d);
	testComparisonOperators(d, g);

	std::cout << INVERSE CYAN "\n--- Arithmetic Tests ---" RESET << std::endl;
	testArithmeticOperators(c, d);
	testArithmeticOperators(b, c);
	testArithmeticOperators(d, g);

	std::cout << INVERSE CYAN "\n--- Increment/Decrement Tests ---" RESET << std::endl;
	testIncrementDecrement(a);
	testIncrementDecrement(b);
	testIncrementDecrement(g);

	std::cout << INVERSE CYAN "\n--- Min/Max Tests ---" RESET << std::endl;
	testMinMax(a, b);
	testMinMax(c, d);
	testMinMax(d, g);

	std::cout << INVERSE CYAN "\n--- Special Cases ---" RESET << std::endl;
	Fixed e(INT_MIN);
	Fixed f(INT_MAX);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	testArithmeticOperators(e, f);

	return (0);
}
