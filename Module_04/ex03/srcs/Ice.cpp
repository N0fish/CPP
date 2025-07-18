/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:18:39 by algultse          #+#    #+#             */
/*   Updated: 2024/12/18 17:09:52 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Ice::Ice() : AMateria("ice") {
	if (IS_PRINT) {
		std::cout	<< CYAN BOLD "Ice" RESET
					<< " materia has been created! [Default Constructor]"
					<< std::endl;
	}
	return ;
}

Ice::Ice(const Ice &ice) : AMateria("ice") {
	if (IS_PRINT) {
		std::cout	<< CYAN BOLD "Ice" RESET
					<< " materia has been duplicated! [Copy Constructor]"
					<< std::endl;
	}
	*this = ice;
	return ;
}

Ice::~Ice() {
	if (IS_PRINT) {
		std::cout	<< CYAN BOLD "Ice" RESET
					<< " materia has been destroyed! [Destructor]"
					<< std::endl;
	}
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Ice	&Ice::operator=(const Ice &ice) {
	if (this != &ice)
	{
		AMateria::operator=(ice);
		if (IS_PRINT) {
			std::cout	<< CYAN BOLD "Ice" RESET
						<< " materia has been reassigned! [Assignment Operator]"
						<< std::endl;
		}
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

AMateria	*Ice::clone(void) const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	std::cout	<< "* shoots an ice bolt at " 
				<< CYAN BOLD << target.getName() << RESET 
				<< " *" << std::endl;
}
