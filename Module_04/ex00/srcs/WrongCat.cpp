/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:33:04 by algultse          #+#    #+#             */
/*   Updated: 2024/12/10 23:42:34 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout	<< "A mischievous "
				<< BLUE BOLD << _type << RESET
				<< " sneaks in! "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

WrongCat::WrongCat(const std::string type) {
	_type = type;
	std::cout	<< "A WrongCat of type \""
				<< BLUE BOLD << _type << RESET
				<< "\" appears with suspicious intent! "
				<< "[Parameterized Constructor]"
				<< std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	_type = other._type;
	std::cout	<< "A WrongCat of type \""
				<< BLUE BOLD << _type << RESET
				<< "\" has been sneakily duplicated! "
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

WrongCat::~WrongCat() {
	std::cout	<< "The "
				<< BLUE "WrongCat" RESET
				<< " of type \""
				<< BLUE BOLD << _type << RESET
				<< "\" slinks away into the shadows. "
				<< "[Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

WrongCat	&WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		_type = other._type;
		std::cout	<< "A WrongCat has reluctantly adopted the traits of type \"" 
					<< BLUE BOLD << _type << RESET
					<< "\". "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	WrongCat::makeSound() const {
	std::cout	<< BLUE ITALIC << "Meow?? 🐾 (WrongCat trying to sound like a Cat)"
				<< RESET << std::endl;
}
