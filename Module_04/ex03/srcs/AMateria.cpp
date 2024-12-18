/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:59:05 by algultse          #+#    #+#             */
/*   Updated: 2024/12/16 22:03:10 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

AMateria::AMateria() : _type("Unknown") {
	std::cout	<< "AMateria of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" has been created! [Default Constructor]" 
				<< std::endl;
	return ;
}

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout	<< "AMateria of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" has been crafted! [Parameterized Constructor]" 
				<< std::endl;
	return ;
}

AMateria::AMateria(const AMateria &amateria) : _type(amateria._type) {
	std::cout	<< "AMateria of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" has been duplicated! [Copy Constructor]" 
				<< std::endl;
	return ;
}

AMateria::~AMateria() {
	std::cout	<< "AMateria of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" has been consumed! [Destructor]" 
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

AMateria	&AMateria::operator=(const AMateria &amateria) {
	if (this != &amateria)
	{
		this->_type = amateria._type;
		std::cout	<< "AMateria of type \""
					<< PURPLE BOLD << _type << RESET
					<< "\" has been reassigned! [Assignment Operator]" 
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             GETTER and SETTER                              */
/* -------------------------------------------------------------------------- */

std::string const	&AMateria::getType(void) const {
	return (this->_type);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void		AMateria::use(ICharacter &target) {
	std::cout	<< "* uses " 
				<< PURPLE BOLD << _type << RESET
				<< " on "
				<< BOLD << target.getName() << RESET << " *" 
				<< std::endl;
}
