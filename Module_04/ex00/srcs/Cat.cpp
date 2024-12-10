/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:52:00 by algultse          #+#    #+#             */
/*   Updated: 2024/12/10 23:29:53 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Cat::Cat() {
	_type = "Cat";
	std::cout	<< "A curious "
				<< CYAN BOLD << _type << RESET
				<< " appears on the scene! "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

Cat::Cat(const std::string type) {
	_type = type;
	std::cout	<< "A Cat of type \""
				<< CYAN BOLD << _type << RESET
				<< "\" has gracefully stepped into the spotlight! "
				<< "[Parameterized Constructor]"
				<< std::endl;
	return ;
}

Cat::Cat(const Cat& other) : Animal(other) {
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
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		_type = other._type;
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
