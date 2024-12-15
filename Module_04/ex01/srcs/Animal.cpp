/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:45:50 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:22:31 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Animal::Animal() : _type("Animal") {
	std::cout	<< "A wild "
				<< GREEN BOLD << _type << RESET
				<< " appears! "
				<< "[Default Constructor]"
				<< std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
	std::cout	<< "An \""
				<< GREEN BOLD << _type << RESET
				<< "\" has been created to roam the world! "
				<< "[Parameterized Constructor]"
				<< std::endl;
}


Animal::Animal(const Animal& othet) : _type(othet._type){
	std::cout	<< "An Animal of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" has been duplicated!"
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

Animal::~Animal() {
	std::cout	<< "The "
				<< GREEN "Animal" RESET
				<< " of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" disappears into the void. "
				<< "[Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other)
	{
		_type = other._type;
		std::cout	<< "An Animal of type \""
					<< GREEN BOLD << _type << RESET
					<< "\" has been reassigned! "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

std::string	const	&Animal::getType(void) const {
	return (this->_type);
}

void	Animal::setType(std::string const &type) {
	this->_type = type;
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Animal::makeSound() const {
	std::cout	<< GREEN ITALIC << "* A faint rustling sound can be heard... *"
				<< RESET << std::endl;
}
