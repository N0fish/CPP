/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:45:50 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 22:01:14 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout	<< "A wild "
				<< GREEN BOLD << _type << RESET
				<< " appears! "
				<< "[Default Constructor]"
				<< std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	std::cout	<< "An \""
				<< GREEN BOLD << _type << RESET
				<< "\" has been created to roam the world! "
				<< "[Parameterized Constructor]"
				<< std::endl;
}

AAnimal::AAnimal(const AAnimal& othet) : _type(othet._type){
	std::cout	<< "An AAnimal of type \""
				<< GREEN BOLD << _type << RESET
				<< "\" has been duplicated!"
				<< "[Copy Constructor]"
				<< std::endl;
	return ;
}

AAnimal::~AAnimal() {
	std::cout	<< "The "
				<< GREEN "AAnimal" RESET
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

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
	{
		_type = other._type;
		std::cout	<< "An AAnimal of type \""
					<< GREEN BOLD << _type << RESET
					<< "\" has been reassigned! "
					<< "[Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                   GETTER                                   */
/* -------------------------------------------------------------------------- */

std::string	const	&AAnimal::getType(void) const {
	return (this->_type);
}
