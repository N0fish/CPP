/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:56:21 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:45:50 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
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

void	printBrainIdeas(const Brain* brain, int start = 0, int end = 5)
{
	for (int i = start; i < end; ++i)
	{
		std::cout	<< "Idea [" << i << "]: "
					<< brain->getIdea(i)
					<< std::endl;
	}
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
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << GREEN << "\n○○ Animal Types: ○○\n" << RESET;
	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << YELLOW << "\n○○ Animal Sounds: ○○\n" << RESET;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout	<< CYAN INVERSE
				<< "\n\t--- End of Subject tests ---\n"
				<< RESET << std::endl;
}

void	testAnimalArray(void)
{
	std::cout	<< PURPLE INVERSE
				<< "\n\t--- Animal Array Test ---\n"
				<< RESET << std::endl;

	const int	arraySize = 6;
	Animal*		animals[arraySize];

	// Create an array of Dogs and Cats
	for (int i = 0; i < arraySize; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Make all animals speak
	std::cout	<< YELLOW << "\n○○ Making all animals speak: ○○"
				<< RESET << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		animals[i]->makeSound();
	}

	// Delete all animals
	std::cout	<< RED << "\n○○ Deleting all animals: ○○"
				<< RESET << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		delete animals[i];
	}

	std::cout	<< PURPLE INVERSE
				<< "\n\t--- End of Animal Array Test ---\n"
				<< RESET << std::endl;
}

void	testDeepCopy(void)
{
	std::cout	<< RED INVERSE
				<< "\n\t--- Deep Copy Test ---\n"
				<< RESET << std::endl;

	// Test deep copy for Cat
	Cat*	originalCat = new Cat();
	originalCat->getBrain()->setIdea(0, "Chase the mouse");
	originalCat->getBrain()->setIdea(1, "Nap in the sun");

	std::cout	<< BLUE << "○○ Original Cat Brain Ideas: ○○"
				<< RESET << std::endl;
	printBrainIdeas(originalCat->getBrain());
	std::cout	<< std::endl;

	Cat* copiedCat = new Cat(*originalCat);
	std::cout	<< BLUE << "○○ Copied Cat Brain Ideas: ○○"
				<< RESET  << std::endl;
	printBrainIdeas(copiedCat->getBrain());

	std::cout	<< YELLOW << "\n○○ Modifying Original Cat's Brain: ○○"
				<< RESET  << std::endl;
	originalCat->getBrain()->setIdea(0, "Climb the tree");
	printBrainIdeas(originalCat->getBrain());

	std::cout	<< BLUE << "○○ Copied Cat Brain Should Remain Unchanged: ○○"
				<< RESET << std::endl;
	printBrainIdeas(copiedCat->getBrain());

	std::cout	<< std::endl;
	delete originalCat;
	delete copiedCat;
	std::cout	<< std::endl;

	// Test deep copy for Dog
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Fetch the ball");
	originalDog.getBrain()->setIdea(1, "Bark at the mailman");

	std::cout	<< BLUE << "○○ Original Dog Brain Ideas: ○○"
				<< RESET << std::endl;
	printBrainIdeas(originalDog.getBrain());
	std::cout	<< std::endl;

	Dog copiedDog = originalDog;
	std::cout	<< BLUE << "○○ Copied Dog Brain Ideas: ○○"
				<< RESET << std::endl;
	printBrainIdeas(copiedDog.getBrain());

	std::cout	<< YELLOW << "\n○○ Modifying Original Dog's Brain: ○○"
				<< RESET << std::endl;
	originalDog.getBrain()->setIdea(0, "Guard the house");
	printBrainIdeas(originalDog.getBrain());

	std::cout	<< BLUE << "○○ Copied Dog Brain Should Remain Unchanged: ○○"
				<< RESET << std::endl;
	printBrainIdeas(copiedDog.getBrain());

	std::cout	<< RED INVERSE
				<< "\n\t--- Deep Copy Test ---\n"
				<< RESET << std::endl;
}
