/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:53:11 by algultse          #+#    #+#             */
/*   Updated: 2024/10/27 22:42:29 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< RED
				<< "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< RESET << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// a.setRawBits( 42 );
	// std::cout << a.getRawBits() << std::endl;

	return (0);
}
