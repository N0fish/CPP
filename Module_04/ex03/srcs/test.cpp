/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:40:04 by algultse          #+#    #+#             */
/*   Updated: 2024/12/18 17:25:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void	testSubject(void)
{
	std::cout	<< CYAN INVERSE
				<< "\n\t--- Subject tests ---\n"
				<< RESET << std::endl;

	IMateriaSource*	src = new MateriaSource();

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Learning Materia --\n" RESET;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Creating Characters --\n" RESET;
	ICharacter*	me = new Character("me");

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Equipping Materia --\n" RESET;
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Creating Characters --\n" RESET;
	ICharacter*	bob = new Character("bob");

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Using Materia --\n" RESET;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout	<< std::endl;

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete bob;
	delete me;
	delete src;

	std::cout	<< CYAN INVERSE
				<< "\n\t--- End of Subject tests ---\n"
				<< RESET << std::endl;
}

void	testMateriaSource(void)
{
	std::cout << GREEN INVERSE "\n\t=== Test MateriaSource ===\n" RESET << std::endl;

	MateriaSource* source = new MateriaSource();

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Learning Materia --" RESET << std::endl;
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Overflow test --" RESET << std::endl;
	source->learnMateria(new Cure());

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Deep Copy Test --" RESET << std::endl;
	MateriaSource* copySource = new MateriaSource(*source);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Should not affect the copy --\n" RESET;
	source->learnMateria(new Ice());

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n-- Creating Materia --" RESET << std::endl;
	AMateria* ice = source->createMateria("ice");
	AMateria* cure = source->createMateria("cure");
	AMateria* unknown = source->createMateria("rock");

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete ice;
	delete cure;
	delete unknown;
	delete source;
	delete copySource;
	std::cout << GREEN INVERSE << "\n\t--- End of Test Materia Source ---\n" << RESET << std::endl;
}

void	testCharacters(void)
{
	std::cout << PURPLE INVERSE "\n\t=== Test Characters ===\n" RESET << std::endl;

	Character*	alice = new Character("Alice");
	Character*	bob = new Character("Bob");

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Equipping Materia --" RESET << std::endl;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	alice->equip(ice);
	alice->equip(cure->clone());
	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Invalid slot nullptr test --" RESET << std::endl;
	alice->equip(NULL);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Using Materia --" RESET << std::endl;
	alice->use(0, *bob);
	alice->use(1, *bob);
	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Invalid slot 5=index[4] test  --" RESET << std::endl;
	alice->use(4, *bob);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Deep Copy Test --" RESET << std::endl;
	Character*	aliceCopy = new Character(*alice);
	alice->unequip(0);
	aliceCopy->use(0, *bob);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete alice;
	delete bob;
	delete aliceCopy;
	delete ice;
	delete cure;

	std::cout << PURPLE INVERSE << "\n\t--- End of Test Character ---\n" << RESET << std::endl;
}

void	testDuel(void)
{
	std::cout << BLUE INVERSE "\n\t=== Test Materia Duel ===\n" RESET << std::endl;

	Character* igor = new Character("Igor");
	Character* jessica = new Character("Jessica");
	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n-- Equipping Characters --" RESET << std::endl;
	AMateria*	ice = source->createMateria("ice");
	AMateria*	cure = source->createMateria("cure");
	igor->equip(ice);
	jessica->equip(cure);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n-- Fight --" RESET << std::endl;
	igor->use(0, *jessica);
	jessica->use(0, *igor);

	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	igor->unequip(0);
	jessica->unequip(0);
	
	if (IS_PRINT)
		std::cout << BLUE DIM BOLD "\n   -- Cleanup --\n" RESET;
	delete igor;
	delete jessica;
	delete source;
	delete ice;
	delete cure;

	std::cout << PURPLE INVERSE << "\n\t--- End of Test Materia Duel ---\n" << RESET << std::endl;
}
