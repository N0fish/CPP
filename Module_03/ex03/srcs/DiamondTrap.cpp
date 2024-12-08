/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:55:43 by algultse          #+#    #+#             */
/*   Updated: 2024/12/08 23:01:21 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"),
							FragTrap(),
							ScavTrap() {
	_name = "default";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< INVERSE_BLUE_ON_WHILE "💎 DiamondTrap "
				<< BRIGHT_BLACK_ON_BLUE << _name << RESET 
				<< INVERSE_BLUE_ON_WHILE " has been created using the " RESET
				<< BOLD_YELLOW_ON_BLUE "default" RESET
				<< INVERSE_BLUE_ON_WHILE " constructor!" 
				<< std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
											FragTrap(),
											ScavTrap() {
	_name = name;
	_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< INVERSE_BLUE_ON_WHILE "💎 DiamondTrap "
				<< BRIGHT_BLACK_ON_BLUE << _name << RESET
				<< INVERSE_BLUE_ON_WHILE " created with "
				<< BOLD UNDERLINE "name" RESET
				<< INVERSE_BLUE_ON_WHILE " constructor!" RESET
				<< std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
											: ClapTrap(other.ClapTrap::_name),
											FragTrap(other),
											ScavTrap(other),
											_name(other._name) {
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;

	std::cout	<< INVERSE_BLUE_ON_WHILE "💎 DiamondTrap "
				<< BRIGHT_BLACK_ON_BLUE << _name << RESET
				<< INVERSE_BLUE_ON_WHILE " has been " << RESET
				<< BOLD_YELLOW_ON_BLUE << "copied!" RESET
				<< std::endl;
	return ;
}

DiamondTrap::~DiamondTrap() {
	std::cout	<< INVERSE_BLUE_ON_WHILE "💎 DiamondTrap "
				<< BRIGHT_BLACK_ON_BLUE << _name << RESET
				<< INVERSE_BLUE_ON_WHILE " has been "
				<< BOLD UNDERLINE "destroyed." RESET
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) 
	{
		ClapTrap::_name = other.ClapTrap::_name;
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout	<< INVERSE_BLUE_ON_WHILE "💎 DiamondTrap "
				<< BRIGHT_BLACK_ON_BLUE << _name << RESET
				<< INVERSE_BLUE_ON_WHILE " has been assigned!" 
				<< std::endl;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	DiamondTrap::whoAmI(void) {
	if (_hitPoints <= 0)
		std::cout	<< "💀 " << BRIGHT_BLACK_ON_BLUE << _name << RESET
					<< INVERSE_BLUE_ON_WHILE " is destroyed and cannot reveal its identity." RESET
					<< std::endl;
	else
		std::cout	<< "🙌 " << INVERSE_BLUE_ON_WHILE "I am "
					<< BRIGHT_BLACK_ON_BLUE << _name << RESET
					<< INVERSE_BLUE_ON_WHILE ", a mighty DiamondTrap!\n"
					<< "\t\t🤖 ClapTrap name: " RESET
					<< BOLD GREEN << ClapTrap::_name << RESET 
					<< INVERSE_BLUE_ON_WHILE "." RESET << std::endl;
}

void	DiamondTrap::displayStatus() const {
	const int	nameWidth = 20;
	const int	fieldWidth = 10;

	std::cout	<< BRIGHT_BLACK_ON_BLUE << std::left
				<< std::setw(nameWidth) << _name << RESET INVERSE_BLUE_ON_WHILE
				<< "| HP " << std::setw(fieldWidth - 3) << _hitPoints
				<< "| Energy " << std::setw(fieldWidth - 7) << _energyPoints
				<< "| Attack Damage " << _attackDamage << RESET
				<< std::endl;
}
