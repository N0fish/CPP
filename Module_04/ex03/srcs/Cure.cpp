/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:19:51 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 19:01:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Cure::Cure() : AMateria("cure") {
	std::cout	<< GREEN BOLD  "Cure" RESET
				<< " materia has been created! [Default Constructor]"
				<< std::endl;
	return ;
}

Cure::Cure(const Cure &cure) : AMateria("cure") {
	std::cout	<< GREEN BOLD  "Cure" RESET
				<< " materia has been duplicated! [Copy Constructor]"
				<< std::endl;
	*this = cure;
	return ;
}

Cure::~Cure() {
	std::cout	<< GREEN BOLD  "Cure" RESET
				<< " materia has been destroyed! [Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Cure	&Cure::operator=(const Cure &cure) {
	if (this != &cure) {
		AMateria::operator=(cure);
		// _type = cure._type;
		std::cout	<< GREEN BOLD  "Cure" RESET
					<< " materia has been reassigned! [Assignment Operator]"
					<< std::endl;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

AMateria	*Cure::clone(void) const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	std::cout	<< "* heals " 
				<< GREEN BOLD << target.getName() << RESET 
				<< "'s wounds *" << std::endl;
}
