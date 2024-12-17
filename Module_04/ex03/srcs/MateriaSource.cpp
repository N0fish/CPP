/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:54 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 21:50:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

MateriaSource::MateriaSource() {
	for (int i = 0; i < _maxMateria; ++i)
		_learnedMateria[i] = nullptr;
	std::cout	<< RED DIM "MateriaSource" RESET
				<< " has been initialized! [Default Constructor]"
				<< std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < _maxMateria; ++i) {
		if (other._learnedMateria[i]) {
			_learnedMateria[i] = other._learnedMateria[i]->clone();
			std::cout << RED DIM "Cloning materia at slot " << i << RESET<< std::endl;
			if (!_learnedMateria[i]) {
				std::cerr << RED DIM "Error: clone() returned nullptr for slot " << i << RESET << std::endl;
			}
		}
		else
			_learnedMateria[i] = nullptr;
	}
	std::cout	<< RED DIM "MateriaSource" RESET
				<< " has been duplicated! [Copy Constructor]"
				<< std::endl;
	return ;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _maxMateria; ++i)
	{
		if (_learnedMateria[i]) {
			delete _learnedMateria[i];
			_learnedMateria[i] = nullptr;
		}
	}
	std::cout	<< RED DIM  "MateriaSource" RESET
				<< " has been destroyed! [Destructor]"
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _maxMateria; ++i) {
			if (_learnedMateria[i])
				delete _learnedMateria[i];
			if (other._learnedMateria[i]) {
				_learnedMateria[i] = other._learnedMateria[i]->clone();
				if (!_learnedMateria[i]) {
					std::cerr << RED DIM "Error: clone() returned nullptr for slot " << i << RESET << std::endl;
				}
			}
			else
				_learnedMateria[i] = nullptr;
		}
	}
	std::cout	<< RED DIM "MateriaSource" RESET
				<< " has been reassigned! [Assignment Operator]"
				<< std::endl;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout	<< "Cannot learn a null "
					<< RED DIM "materia!" RESET
					<< std::endl;
		return;
	}
	for (int i = 0; i < _maxMateria; ++i) {
		if (!_learnedMateria[i]) {
			_learnedMateria[i] = m->clone();
			std::cout	<< "Materia \""
						<< RED DIM << m->getType() << RESET
						<< "\" learned in slot ["
						<< RED DIM << i << RESET
						<< "]." << std::endl;
			return;
		}
	}
	std::cout	<< RED DIM "MateriaSource" RESET
				<< " is full! Cannot learn more materia."
				<< std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string & type) {
	for (int i = 0; i < _maxMateria; ++i) {
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type)
		{
			std::cout	<< "Materia \""
						<< RED DIM << type << RESET
						<< "\" created from slot ["
						<< RED DIM << i << RESET
						<< "]." << std::endl;
			return (_learnedMateria[i]->clone());
		}
	}
	std::cout	<< "No matching materia found for type \""
				<< RED DIM << type << RESET
				<< "\"." << std::endl;
	return (nullptr);
}
