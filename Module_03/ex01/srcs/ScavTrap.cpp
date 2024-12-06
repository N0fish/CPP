/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:52:35 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 20:05:12 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< INVERSE ITALIC BLACK "ScavTrap from ClapTrap " RESET GREEN_BLACK
				<< _name << RESET INVERSE ITALIC BLACK " created with "
				<< RESET ITALIC_YELLOW_ON_BLACK "default" RESET
				<< INVERSE ITALIC BLACK " constructor!" RESET
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< INVERSE ITALIC BLACK "ScavTrap " RESET GREEN_BLACK
				<< _name << RESET INVERSE_BLACK_WHITE " constructed!" RESET
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout	<< INVERSE ITALIC BLACK "ScavTrap " RESET GREEN_BLACK
				<< _name << RESET ITALIC_YELLOW_ON_BLACK << " copied." RESET
				<< std::endl;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout	<< INVERSE ITALIC BLACK "ScavTrap " RESET GREEN_BLACK
				<< _name << RESET ITALIC_BLUE_BLACK " destroyed!" RESET
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout	<< INVERSE ITALIC BLACK "ScavTrap " RESET GREEN_BLACK
				<< _name << RESET ITALIC_PURPLE_ON_BLACK " assigned!" RESET
				<< std::endl;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout	<< "⚰️ " GREEN_BLACK << _name << RESET 
					<< INVERSE_BLACK_WHITE " can't " RESET
					<< ITALIC_RED_ON_BLACK "attack" RESET
					<< INVERSE_BLACK_WHITE" because it's destroyed!" RESET
					<< std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout	<< "🔋 " GREEN_BLACK << _name << RESET
					<< INVERSE_BLACK_WHITE " has no energy left to " RESET
					<< ITALIC_RED_ON_BLACK "attack!" RESET
					<< std::endl;
		return;
	}

	std::string	adjustedTarget = (target == _name) ? "itself" : target;
	std::cout	<< "💥🛡️ " GREEN_BLACK << _name << RESET
				<< INVERSE_BLACK_WHITE " launches a powerful " RESET
				<< ITALIC_RED_ON_BLACK "attack" RESET
				<< INVERSE_BLACK_WHITE " on " << adjustedTarget
				<< ", causing " << _attackDamage << " points of damage!" RESET
				<< std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate() const {
	if (_hitPoints <= 0)
		std::cout	<< "🔒 " GREEN_BLACK << _name << RESET
					<< INVERSE_BLACK_WHITE " cannot enter Gate Keeper Mode because it is destroyed!" RESET
					<< std::endl;
	else
		std::cout	<< "🔒 " GREEN_BLACK << _name << RESET
					<< INVERSE_BLACK_WHITE " is now in Gate Keeper Mode, guarding the gate with honor!" RESET
					<< std::endl;

}

void	ScavTrap::displayStatus() const {
	const int	nameWidth = 6;
	const int	fieldWidth = 10;

	std::cout	<< GREEN_BLACK << std::left
				<< std::setw(nameWidth) << _name << RESET ITALIC_BLUE_BLACK
				<< "| HP " << std::setw(fieldWidth - 3) << _hitPoints
				<< "| Energy " << std::setw(fieldWidth - 7) << _energyPoints
				<< "| Attack Damage " << _attackDamage
				<< RESET << std::endl;
}
