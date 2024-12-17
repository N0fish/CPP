/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:40:04 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 23:58:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
# include "MateriaSource.hpp"

// void	testMateriaUsage()
// {
// 	std::cout << CYAN INVERSE << "\n\t--- Test Materia Usage ---\n" << RESET << std::endl;

// 	AMateria	*ice = new Ice();
// 	AMateria	*cure = new Cure();

// 	Character	character("Adventurer");

// 	std::cout	<< BLUE DIM BOLD << "\n   Equipping Materia..." << RESET
// 				<< std::endl;
// 	character.equip(ice);
// 	character.equip(cure);

// 	std::cout	<< BLUE DIM BOLD << "\n   Using Materia..." << RESET
// 				<< std::endl;
// 	character.use(0, character);
// 	character.use(1, character);

// 	std::cout	<< BLUE DIM BOLD << "\n   Unequipping Materia..." << RESET
// 				<< std::endl;
// 	character.unequip(0);
// 	character.unequip(1);

// 	std::cout	<< BLUE DIM BOLD << "\n   Deleting Materia..." << RESET
// 				<< std::endl;
// 	delete ice;
// 	delete cure;

// 	std::cout << CYAN INVERSE << "\n\t--- End of Test Materia Usage ---\n" << RESET << std::endl;
// }

// void	testCharacterInteraction()
// {
// 	std::cout << PURPLE INVERSE << "\n\t--- Test Character Interaction ---\n" << RESET << std::endl;

// 	Character	alice("Alice");
// 	Character	bob("Bob");

// 	AMateria	*ice = new Ice();
// 	AMateria	*cure = new Cure();

// 	std::cout	<< std::endl;
// 	alice.equip(ice);
// 	alice.equip(cure);

// 	std::cout	<< BLUE DIM BOLD << "\n   Alice uses Materia on Bob..." << RESET
// 				<< std::endl;
// 	alice.use(0, bob);
// 	alice.use(1, bob);

// 	std::cout	<< BLUE DIM BOLD << "\n   Bob tries to use an empty inventory slot..." << RESET
// 				<< std::endl;
// 	bob.use(0, alice);

// 	std::cout	<< BLUE DIM BOLD << "\n   Unequipping Materia from Alice..." << RESET
// 				<< std::endl;
// 	alice.unequip(0);
// 	alice.unequip(1);

// 	delete ice;
// 	delete cure;

// 	std::cout << PURPLE INVERSE << "\n\t--- End of Test Character Interaction ---\n" << RESET << std::endl;
// }

// void	testMateriaUsage()
// {
//     std::cout << CYAN INVERSE << "\n\t=== Test Materia Usage ===\n" << RESET << std::endl;

// 	MateriaSource	source;
// 	source.learnMateria(new Ice());
// 	source.learnMateria(new Cure());

// 	Character	adventurer("Adventurer");

// 	std::cout << BLUE DIM BOLD "\n   -- Equipping Materia --\n" RESET;
// 	adventurer.equip(source.createMateria("ice"));
// 	adventurer.equip(source.createMateria("cure"));

// 	std::cout << BLUE DIM BOLD "\n   -- Using Materia --\n" RESET;
// 	adventurer.use(0, adventurer);
// 	adventurer.use(1, adventurer);

// 	std::cout << BLUE DIM BOLD "\n   -- Unequipping Materia --\n" RESET;
// 	adventurer.unequip(0);
// 	adventurer.unequip(1);

// 	std::cout << CYAN INVERSE << "\n\t--- End of Test Materia Usage ---\n" << RESET << std::endl;
// }

// void	testCharacterInteraction()
// {
//     std::cout << PURPLE INVERSE << "\n=== Test Character Interaction ===\n"<< RESET << std::endl;

// 	MateriaSource	source;
// 	source.learnMateria(new Ice());
// 	source.learnMateria(new Cure());

// 	Character	alice("Alice");
// 	Character	bob("Bob");

// 	std::cout << BLUE DIM BOLD "\n   -- Equipping Materia for Alice --\n" RESET;
// 	alice.equip(source.createMateria("ice"));
// 	alice.equip(source.createMateria("cure"));

// 	std::cout << BLUE DIM BOLD "\n   -- Alice Uses Materia on Bob --\n" RESET;
// 	alice.use(0, bob);
// 	alice.use(1, bob);

// 	std::cout << BLUE DIM BOLD "\n   -- Bob Tries Using Empty Slots --\n" RESET;
// 	bob.use(0, alice);  // Empty slot

// 	std::cout << BLUE DIM BOLD "\n   -- Unequipping Materia from Alice --\n" RESET;
// 	alice.unequip(0);
// 	alice.unequip(1);

// 	std::cout << PURPLE INVERSE << "\n\t--- End of Test Character Interaction ---\n" << RESET << std::endl;
// }

void	testMateriaSource()
{
	std::cout << GREEN INVERSE << "\n\t=== Test Materia Source ===\n" << RESET << std::endl;

	MateriaSource	source;
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());

	std::cout << BLUE DIM BOLD "\n   -- Trying to Learn Duplicate Materia --\n" RESET;
	source.learnMateria(new Ice());  // Try learning beyond limit

	std::cout << BLUE DIM BOLD "\n   -- Creating Materia --\n" RESET;
	AMateria *created = source.createMateria("ice");
	if (created) {
		std::cout << BLUE DIM BOLD  "Successfully created: " << created->getType() << RESET << std::endl;
		delete created;
	} else {
		std::cout << BLUE DIM BOLD "Failed to create Materia of type 'ice'." RESET << std::endl;
	}

	std::cout << BLUE DIM BOLD "\n   -- Handling Unknown Materia --\n" RESET;
	created = source.createMateria("unknown");
	if (!created) {
		std::cout << BLUE DIM BOLD "Correctly handled unknown Materia type." RESET << std::endl;
	}

	std::cout << GREEN INVERSE << "\n\t--- End of Test Materia Source ---\n" << RESET << std::endl;
}

// int	main()
// {
// 	std::cout << BOLD INVERSE << "\n\t\t=== Running all tests ===\n" << RESET << std::endl;

// 	testSubject();
// 	// testMateriaUsage();
// 	// testCharacterInteraction();
// 	testMateriaUsage();
// 	testCharacterInteraction();
// 	testMateriaSource();

// 	std::cout << BOLD INVERSE << "\n\t\t=== All tests completed ===\n" << RESET << std::endl;
// 	return (0);
// }
