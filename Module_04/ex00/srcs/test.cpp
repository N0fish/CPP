/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:56:21 by algultse          #+#    #+#             */
/*   Updated: 2024/12/11 00:01:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* -------------------------------------------------------------------------- */
/*                              Utility Functions                             */
/* -------------------------------------------------------------------------- */

void	printAnimalInfo(const Animal* animal) {
	std::cout	<< GREEN << "Type: " << RESET
				<< animal->getType() << " | ";
	std::cout	<< YELLOW << "Sound: " << RESET;
	animal->makeSound();
}

/* -------------------------------------------------------------------------- */
/*                               Test Functions                               */
/* -------------------------------------------------------------------------- */

void	testSubject(void)
{
	std::cout	<< CYAN INVERSE
				<< "\n\t\t--- Subject tests ---\n"
				<< RESET << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout	<< BLUE << "\nAnimal information:"
				<< RESET << std::endl;	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout	<< "\n\t" << YELLOW << "Calling makeSound directly:"
				<< RESET << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout	<< std::endl;
	delete j;
	delete i;
	delete meta;

	std::cout	<< CYAN INVERSE
				<< "\n\t--- End of Subject tests ---\n"
				<< RESET << std::endl;
}

void	testPolymorphism(void)
{
	std::cout	<< PURPLE INVERSE
				<< "\n\t--- Polymorphism tests ---\n"
				<< RESET << std::endl;

	const Animal*	animals[3];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();

	std::cout << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout	<< BRIGHT_BLUE
					<< "Animal [" << i << "]"
					<< RESET << std::endl;
		printAnimalInfo(animals[i]);
	}

	std::cout << std::endl;
	for (int i = 0; i < 3; ++i) {
		delete animals[i];
	}

	std::cout	<< PURPLE INVERSE
				<< "\n\t--- End of Polymorphism tests ---\n"
				<< RESET << std::endl;
}

void	testWrongAnimals(void)
{
	std::cout	<< RED INVERSE
				<< "\n\t--- Wrong Animals tests ---\n"
				<< RESET << std::endl;

	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout	<< BRIGHT_CYAN << "\n\tWrongAnimal information:\n" << RESET;
	std::cout	<< GREEN << "Type: " << RESET
				<< UNDERLINE << wrongMeta->getType() << RESET << " | ";
	std::cout	<< YELLOW << "Sound: " << RESET;
	wrongMeta->makeSound();

	std::cout	<< GREEN << "Type: " << RESET
				<< UNDERLINE << wrongCat->getType() << RESET << " | ";
	std::cout	<< YELLOW << "Sound: " << RESET;
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongMeta;
	delete wrongCat;

	std::cout	<< RED INVERSE
				<< "\n\t--- End of Wrong Animals tests ---\n"
				<< RESET << std::endl;
}
