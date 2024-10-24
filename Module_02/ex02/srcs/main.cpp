/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:14:27 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 22:22:03 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< PURPLE
				<< "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);


	return (EXIT_SUCCESS);
}

// int main( void ) {

// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;
	
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }