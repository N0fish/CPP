/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:10:47 by algultse          #+#    #+#             */
/*   Updated: 2024/12/18 17:30:48 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
# include "MateriaSource.hpp"

int	main()
{
	std::cout << BOLD INVERSE << "\n\t\t=== Running all tests ===\n" << RESET << std::endl;

	testSubject();
	testMateriaSource();
	testCharacters();
	testDuel();

	std::cout << BOLD INVERSE << "\n\t\t=== All tests completed ===\n" << RESET << std::endl;
	return 0;
}
