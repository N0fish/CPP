/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:47:34 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 20:05:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Dog::Dog() {
	_type = "Dog";
	_brain = new Brain();
	std::cout	<< "A loyal "
				<< PURPLE BOLD << _type << RESET
				" joins the adventure! "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

Dog::Dog(const std::string& type, const std::string& firstIdea)
													: AAnimal(type),
													_brain(new Brain()) {
	_brain->setIdea(0, firstIdea);
	std::cout	<< "A Dog of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" with the idea \"" << firstIdea
				<< "\" stands ready for action! "
				<< "[Parameterized Constructor]" << std::endl;
	return ;
}


Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	_type = other._type;
	std::cout	<< "A Dog has been cloned from \""
				<< PURPLE BOLD << _type << RESET
				<< "\"! "
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

Dog::~Dog() {
	std::cout	<< "The "
				<< PURPLE "Dog" RESET
				<< " of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" returns to its kennel. "
				<< "[Destructor]"
				<< std::endl;
	delete _brain;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		AAnimal::operator=(other);
		_type = other._type;
		*_brain = *other._brain;
		std::cout	<< "A Dog of type \""
					<< PURPLE BOLD << _type << RESET
					<< "\" has learned new tricks! "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Dog::makeSound() const {
	std::cout	<< PURPLE ITALIC << "Woof! Woof! 🐕 (Dog barking)"
				<< RESET << std::endl;
}

Brain*	Dog::getBrain() const {
	return (_brain);
}

void	Dog::setBrain(Brain const &brain) {
	*this->_brain = brain;
}
