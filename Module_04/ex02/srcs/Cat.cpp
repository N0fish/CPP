/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:52:00 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 20:10:01 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout	<< "A curious "
				<< CYAN BOLD << _type << RESET
				<< " appears on the scene! "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

Cat::Cat(const std::string& type, const std::string& firstIdea)
													: AAnimal(type),
													_brain(new Brain()) {
	_brain->setIdea(0, firstIdea);
	std::cout	<< "A Cat of type \""
				<< CYAN BOLD << _type << RESET
				<< "\" with the idea \"" << firstIdea
				<< "\" has gracefully stepped into the spotlight! "
				<< "[Parameterized Constructor]"
				<< std::endl;
	return ;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	_type = other._type;
	std::cout	<< "A Cat has been perfectly mirrored from \""
				<< CYAN BOLD << _type << RESET
				<< "\"! "
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

Cat::~Cat() {
	std::cout	<< "The "
				<< CYAN "Cat" RESET
				<< " of type \""
				<< CYAN BOLD << _type << RESET
				<< "\" vanishes into the shadows. "
				<< "[Destructor]"
				<< std::endl;
	delete _brain;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other)
	{
		AAnimal::operator=(other);
		_type = other._type;
		*_brain = *other._brain;
		std::cout	<< "A Cat of type \""
					<< CYAN BOLD << _type << RESET
					<< "\" has refined its habits! "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Cat::makeSound() const {
	std::cout	<< CYAN ITALIC << "Meow~ 🐈 (Cat purring)"
				<< RESET << std::endl;
	return ;
}

Brain*	Cat::getBrain() const {
	return (_brain);
}

void	Cat::setBrain(Brain const &brain) {
	*this->_brain = brain;
}
