/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:01 by algultse          #+#    #+#             */
/*   Updated: 2024/12/08 23:20:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return;
	std::cerr	<< PURPLE "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< RESET << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	std::cout	<< CYAN INVERSE << "\n\t⚙️  Starting DiamondTrap Main Program ⚙️\n"
				<< RESET << std::endl;

	std::cout	<< "\nTesting DiamondTrap functionality..." << std::endl;
	testDiamondTrap();
	std::cout << "\n/* -------------------------------------------------------------------------- */" << std::endl;

	std::cout	<< "\nTesting Mixed Trap functionality..." << std::endl;
	testMixedTraps();

	std::cout	<< RED INVERSE << "\n\t⚠️  Program Complete ⚠️\n" << RESET << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;

	return (0);
}
