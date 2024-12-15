/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:29:53 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 19:59:44 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Brain::Brain() {
	std::cout	<< YELLOW BOLD "Brain" RESET
				<< " created! [Default Constructor]"
				<< std::endl;
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain& other) {
	std::cout	<< YELLOW BOLD "Brain" RESET
				<< " copied! [Copy Constructor]"
				<< std::endl;
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain() {
	std::cout	<< YELLOW BOLD "Brain" RESET
				<< " destroyed! [Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		std::cout	<< YELLOW BOLD "Brain" RESET
					<< " assigned! [Assignment Operator]"
					<< std::endl;
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

std::string const	&Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return (_ideas[index]);
	else
	{
		static std::string	invalidIdea = "No idea!";
		return (invalidIdea);
	}
}

void	Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
	else
		std::cout	<< YELLOW BOLD "Error:" RESET
					<< " Index out of bounds!"
					<< std::endl;
}
