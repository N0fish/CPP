/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:45:53 by algultse          #+#    #+#             */
/*   Updated: 2024/12/06 18:42:27 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout	<< CYAN INVERSE << "\n\t⚙️  Starting FragTrap Main Program ⚙️\n"
				<< RESET << std::endl;

	std::cout << "Testing FragTrap functionality..." << std::endl;
	testFragTrap();
	std::cout << "\n/* -------------------------------------------------------------------------- */" << std::endl;

	std::cout << "\nTesting Mixed Trap functionality..." << std::endl;
	testMixedTraps();

	std::cout	<< RED INVERSE << "\n\t⚠️  Program Complete ⚠️\n"
				<< RESET << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;

	return (0);
}
