/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:10:47 by algultse          #+#    #+#             */
/*   Updated: 2024/12/18 18:10:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
# include "MateriaSource.hpp"

void	testSubject(void)
{
	std::cout	<< CYAN INVERSE
				<< "\n\t\t--- Subject tests ---\n"
				<< RESET << std::endl;

	IMateriaSource*	src = new MateriaSource();

	std::cout << BLUE DIM BOLD "\n   -- Learning Materia --\n" RESET;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << BLUE DIM BOLD "\n   -- Creating Characters --\n" RESET;
	ICharacter*	me = new Character("me");

	std::cout << BLUE DIM BOLD "\n   -- Equipping Materia --\n" RESET;
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << BLUE DIM BOLD "\n   -- Creating Characters --\n" RESET;
	ICharacter*	bob = new Character("bob");

	std::cout << BLUE DIM BOLD "\n   -- Using Materia --\n" RESET;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout	<< std::endl;

	std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete bob;
	delete me;
	delete src;

	std::cout	<< CYAN INVERSE
				<< "\n\t--- End of Subject tests ---\n"
				<< RESET << std::endl;
}

void	testMateriaSource() {
	std::cout << GREEN INVERSE "\n\t=== Test MateriaSource ===\n" RESET << std::endl;

	MateriaSource* source = new MateriaSource();

	std::cout << BLUE DIM BOLD "\n   -- Learning Materia --" RESET << std::endl;
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Cure()); // Overflow test

	std::cout << BLUE DIM BOLD "\n   -- Deep Copy Test --" RESET << std::endl;
	MateriaSource* copySource = new MateriaSource(*source);

	std::cout << BLUE DIM BOLD "\n   -- Should not affect the copy --\n" RESET;
	source->learnMateria(new Ice()); // Should not affect the copy

	std::cout << BLUE DIM BOLD "\n-- Creating Materia --" RESET << std::endl;
	AMateria* ice = source->createMateria("ice");
	AMateria* cure = source->createMateria("cure");
	AMateria* unknown = source->createMateria("rock");

	std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	// if (ice)
		delete ice;
	// if (cure)
		delete cure;
	// if (unknown)
		delete unknown;
	// if (source)
		delete source;
	// if (copySource)
		delete copySource;
	std::cout << GREEN INVERSE << "\n\t--- End of Test Materia Source ---\n" << RESET << std::endl;
}

// void	testMateriaSource()
// {
// 	std::cout << GREEN INVERSE << "\n\t=== Test Materia Source ===\n" << RESET << std::endl;

// 	MateriaSource	source;
// 	source.learnMateria(new Ice());
// 	source.learnMateria(new Cure());
// 	source.learnMateria(new Ice());
// 	source.learnMateria(new Cure());
	// source.learnMateria(new Cure()); // Overflow test

	// std::cout << BLUE DIM BOLD "\n   -- Trying to Learn Duplicate Materia --\n" RESET;
	// source.learnMateria(new Ice());  // Try learning beyond limit

	// std::cout << BLUE DIM BOLD "\n   -- Creating Materia --\n" RESET;
	// AMateria *created = source.createMateria("ice");
	// if (created) {
	// 	std::cout << BLUE DIM BOLD  "Successfully created: " << created->getType() << RESET << std::endl;
	// 	delete created;
	// } else {
	// 	std::cout << BLUE DIM BOLD "Failed to create Materia of type 'ice'." RESET << std::endl;
	// }

	// std::cout << BLUE DIM BOLD "\n   -- Handling Unknown Materia --\n" RESET;
	// created = source.createMateria("unknown");
	// if (!created) {
	// 	std::cout << BLUE DIM BOLD "Correctly handled unknown Materia type." RESET << std::endl;
	// }

// 	std::cout << GREEN INVERSE << "\n\t--- End of Test Materia Source ---\n" << RESET << std::endl;
// }

void	testCharacters() {
	std::cout << PURPLE INVERSE "\n\t=== Test Characters ===\n" RESET << std::endl;

	Character*	alice = new Character("Alice");
	Character*	bob = new Character("Bob");

	std::cout << BLUE DIM BOLD "\n   -- Equipping Materia --" RESET << std::endl;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	alice->equip(ice);
	alice->equip(cure->clone());
	std::cout << BLUE DIM BOLD "\n   -- Invalid slot nullptr test --" RESET << std::endl;
	alice->equip(NULL); // Invalid equip test

	std::cout << BLUE DIM BOLD "\n   -- Using Materia --" RESET << std::endl;
	alice->use(0, *bob);
	alice->use(1, *bob);
	std::cout << BLUE DIM BOLD "\n   -- Invalid slot 5=index[4] test  --" RESET << std::endl;
	alice->use(4, *bob); // Invalid slot test

	std::cout << BLUE DIM BOLD "\n   -- Deep Copy Test --" RESET << std::endl;
	Character*	aliceCopy = new Character(*alice);
	alice->unequip(0);
	aliceCopy->use(0, *bob);

	std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete alice;
	delete bob;
	delete aliceCopy;
	delete ice;
	delete cure;

	std::cout << PURPLE INVERSE << "\n\t--- End of Test Character ---\n" << RESET << std::endl;
}

void	testDuel() {
	std::cout << BLUE INVERSE "\n\t=== Test Materia Duel ===\n" RESET << std::endl;

	Character* igor = new Character("Igor");
	Character* jessica = new Character("Jessica");
	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	std::cout << BLUE DIM BOLD "\n-- Equipping Characters --" RESET << std::endl;
	AMateria*	ice = source->createMateria("ice");
	AMateria*	cure = source->createMateria("cure");
	igor->equip(ice);
	jessica->equip(cure);
	// igor->equip(source->createMateria("ice"));
	// jessica->equip(source->createMateria("cure"));

	std::cout << BLUE DIM BOLD "\n-- Fight --" RESET << std::endl;
	igor->use(0, *jessica);
	jessica->use(0, *igor);

	std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	igor->unequip(0);
	jessica->unequip(0);
	if (igor)
		delete igor;
	if (jessica)
		delete jessica;
	if (source)
		delete source;
	if (ice)
		delete ice;
	if (cure)
		delete cure;

	std::cout << PURPLE INVERSE << "\n\t--- End of Test Materia Duel ---\n" << RESET << std::endl;
}

int	main() {
	std::cout << BOLD INVERSE << "\n\t\t=== Running all tests ===\n" << RESET << std::endl;

	testSubject();
	testMateriaSource();
	testCharacters();
	testDuel();

	std::cout << BOLD INVERSE << "\n\t\t=== All tests completed ===\n" << RESET << std::endl;
	return 0;
}
