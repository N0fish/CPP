/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:45:53 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 20:03:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< PURPLE "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< RESET << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);
	std::cout	<< "\n/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Starting Main Program ⚙️\n" 
				<< RESET << std::endl;

	std::cout	<< "\nTesting ClapTrap functionality..." << std::endl;
	testClapTrap();
	std::cout	<< "\n/* -------------------------------------------------------------------------- */" << std::endl;

	std::cout	<< "\nTesting ScavTrap functionality..." << std::endl;
	testScavTrap();
	std::cout	<< "\n/* -------------------------------------------------------------------------- */" << std::endl;

	std::cout	<< "\nTesting ScavTrap GuardGate functionality..." << std::endl;
	testScavTrapGuardGate();

	std::cout	<< RED INVERSE << "\n\t⚠️  Program Complete ⚠️\n"
				<< RESET << std::endl;
	std::cout	<< "/* -------------------------------------------------------------------------- */" << std::endl;
	return (0);
}
