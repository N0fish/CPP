/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:34:27 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:23:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout	<< "An unusual "
				<< GREEN BOLD << _type << RESET
				<< " is here... "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
	std::cout	<< "A peculiar WrongAnimal of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" has awkwardly emerged! "
				<< "[Parameterized Constructor]"
				<< std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout	<< "A WrongAnimal of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" has been awkwardly duplicated! "
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

WrongAnimal::~WrongAnimal() {
	std::cout	<< "The "
				<< GREEN "WrongAnimal" RESET
				<< " of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" fades away in confusion. "
				<< "[Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
	{
		_type = other._type;
		std::cout	<< "A WrongAnimal has reluctantly accepted new traits of type \"" 
					<< GREEN BOLD << _type << RESET
					<< "\". "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

std::string	WrongAnimal::getType() const {
	return (this->_type);
}

void	WrongAnimal::setType(std::string const &type) {
	this->_type = type;
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	WrongAnimal::makeSound() const {
	std::cout	<< GREEN ITALIC << "* Strange and unrecognizable sounds... *"
				<< RESET << std::endl;
}
