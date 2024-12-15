/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:43:19 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 20:07:13 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

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

	std::cout << BOLD INVERSE << "\n\t\t=== Running all tests ===\n" << RESET << std::endl;

	testSubject();
	testAAnimalArray();
	testDeepCopy();

	std::cout << BOLD INVERSE << "\n\t\t=== All tests completed ===\n" << RESET << std::endl;
	return (0);
}
