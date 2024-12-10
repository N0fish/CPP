/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:47:34 by algultse          #+#    #+#             */
/*   Updated: 2024/12/10 23:40:30 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Dog::Dog() {
	_type = "Dog";
	std::cout	<< "A loyal "
				<< PURPLE BOLD << _type << RESET
				" joins the adventure! "
				<< "[Default Constructor]"
				<< std::endl;
	return ;
}

Dog::Dog(const std::string type) {
	_type = type;
	std::cout	<< "A Dog of type \""
				<< PURPLE BOLD << _type << RESET
				<< "\" stands ready for action! "
				<< "[Parameterized Constructor]"
				<< std::endl;
	return ;
}

Dog::Dog(const Dog& other) : Animal(other) {
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
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		_type = other._type;
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
