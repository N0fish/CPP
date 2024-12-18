/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:05:18 by algultse          #+#    #+#             */
/*   Updated: 2024/12/18 17:28:40 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Character::Character() : _name("Unknown") {
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	if (IS_PRINT) {
		std::cout	<< "Character \""
					<< YELLOW BOLD << _name << RESET
					<< "\" has entered the world! [Default Constructor]"
					<< std::endl;
	}
	return ;
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	if (IS_PRINT) {
		std::cout	<< "Character \""
					<< YELLOW BOLD << _name << RESET
					<< "\" is ready for adventure! [Parameterized Constructor]"
					<< std::endl;
	}
	return ;
}

Character::Character(const Character &other) : _name(other._name) {
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	*this = other;
	if (IS_PRINT) {
		std::cout	<< "Character \""
					<< YELLOW BOLD << _name << RESET 
					<< "\" has been duplicated! [Copy Constructor]"
					<< std::endl;
	}
	return ;
}

Character::~Character() {
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	if (IS_PRINT) {
		std::cout	<< "Character \""
					<< YELLOW BOLD << _name << RESET
					<< "\" has left the world! [Destructor]"
					<< std::endl;
	}
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Character	&Character::operator=(const Character &other) {
	if (this != &other)
	{
		_name = other._name;
		_deleteInventory();
		for (int i = 0; i < _inventorySize; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
		if (IS_PRINT) {
			std::cout	<< "Character \""
						<< YELLOW BOLD << _name << RESET
						<< "\" has been reassigned! [Assignment Operator]"
						<< std::endl;
		}
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             GETTER and SETTER                              */
/* -------------------------------------------------------------------------- */

std::string const	&Character::getName(void) const {
	return (_name);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Character::equip(AMateria *m) {
	if (!m)	{
		if (IS_PRINT) {
			std::cout	<< BLUE BOLD << this->_name << RESET
						<< ": cannot equip a nullptr materia."
						<< std::endl;
		}
		return ;
    }
	for (int i = 0; i < _inventorySize; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			if (IS_PRINT) {
				std::cout	<< "Materia \""
							<< YELLOW BOLD << m->getType() << RESET
							<< "\" equipped in slot [" 
							<< BOLD << i << RESET
							<< "]." << std::endl;
			}
			return ;
		}
	}
	if (IS_PRINT) {
		std::cout	<< "Inventory full! Cannot equip materia \""
					<< YELLOW BOLD << m->getType() << RESET
					<< "\"." << std::endl;
	}
	if (m)
		delete m;
	return ;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= _inventorySize) {
		if (IS_PRINT) {
			std::cout	<< "Invalid slot [" 
						<< YELLOW BOLD << idx << RESET
						<< "] for unequip."
						<< std::endl;
		}
		return;
	}
	if (!_inventory[idx]) {
		if (IS_PRINT) {
			std::cout	<< "Slot ["
						<< YELLOW BOLD << idx << RESET
						<< "] is already empty."
						<< std::endl;
		}
		return;
	}
	if (IS_PRINT) {
		std::cout	<< "Materia \""
					<< YELLOW BOLD << _inventory[idx]->getType() << RESET
					<< "\" unequipped from slot ["
					<< BOLD << idx << RESET
					<< "]." << std::endl;
	}
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= _inventorySize) {
		if (IS_PRINT) {
			std::cout	<< "Invalid slot [" 
						<< YELLOW BOLD << idx << RESET
						<< "] for use." << std::endl;
		}
		return ;
	}
	if (_inventory[idx]) {
		if (IS_PRINT) {
			std::cout	<< "Using materia \""
						<< YELLOW BOLD << _inventory[idx]->getType() << RESET
						<< "\" on \""
						<< YELLOW BOLD << target.getName() << RESET
						<< "\"." << std::endl;
		}
		_inventory[idx]->use(target);
		return ;
	}
	if (IS_PRINT) {
		std::cout	<< "Slot ["
					<< YELLOW BOLD << idx << RESET
					<< "] is empty. Nothing to use."
					<< std::endl;
	}
}

void	Character::_deleteInventory() {
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	return ;
}
