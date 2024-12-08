/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:10:32 by algultse          #+#    #+#             */
/*   Updated: 2024/12/06 18:59:39 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap() : _name("default"),
					_hitPoints(CLAPTRAP_DEFAULT_HIT_POINTS),
					_energyPoints(CLAPTRAP_DEFAULT_ENERGY_POINTS),
					_attackDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE) {
	std::cout	<< BOLD BLACK "ClapTrap created with "
				<< RESET YELLOW "default"
				<< BOLD BLACK " name: " GREEN
				<< _name << RESET
				<< std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name.empty() ? "default" : name),
									_hitPoints(10),
									_energyPoints(10),
									_attackDamage(0) {
	std::cout	<< BOLD BLACK "ClapTrap " GREEN
				<< this->_name << RESET
				<< BOLD BLACK " was " RESET "constructed." RESET
				<< std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name),
											_hitPoints(other._hitPoints),
											_energyPoints(other._energyPoints),
											_attackDamage(other._attackDamage) {
	std::cout	<< BOLD BLACK "ClapTrap " GREEN
				<< this->_name << RESET
				<< YELLOW " copied!" RESET
				<< std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout	<< BOLD BLACK "ClapTrap " GREEN
				<< this->_name << RESET
				<< BOLD BLACK " was " RESET BLUE "destroyed." RESET
				<< std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout	<< BOLD BLACK "ClapTrap " GREEN
				<< this->_name << RESET
				<< PURPLE " assigned!" RESET
				<< std::endl;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

std::string	ClapTrap::getName() const {
	return (this->_name);
}

int	ClapTrap::getHitPoints() const {
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints() const {
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string const &name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(int const &value) {
	this->_hitPoints = value;
}

void	ClapTrap::setEnergyPoints(int const &value) {
	this->_energyPoints = value;
}

void	ClapTrap::setAttackDamage(int const &value) {
	this->_attackDamage = value;
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	ClapTrap::attack(const std::string& target) {
	std::string	adjustedTarget;

	if (_hitPoints <= 0) {
		std::cout	<< "💀 " GREEN BOLD << this->getName() << RESET
					<< " can't " RED "attack" RESET " because it is destroyed!"
					<< std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout	<< "🔋 " GREEN BOLD << this->getName() << RESET
					<< " can't " RED "attack" RESET " because it has no energy left!"
					<< std::endl;
		return;
	}
	adjustedTarget = target;
	if (adjustedTarget == this->_name)
		adjustedTarget = "itself";
	std::cout	<< "⚔️ " GREEN BOLD << this->getName() << RESET
				<< RED DIM " attacks " RESET GREEN BOLD << adjustedTarget << RESET
				<< ", causing " << _attackDamage << " points of damage!"
				<< std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout	<< "💀 " GREEN BOLD << this->getName() << RESET
					<< " is already destroyed and can't " DIM "take" RESET " more damage!"
					<< std::endl;
		return ;
	}
	if (amount >= (unsigned int)this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout	<< "💥 " GREEN BOLD << this->getName() << RESET
					<< DIM " takes " RESET << amount << " damage and is destroyed!"
					<< std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout	<< "💥 " GREEN BOLD << this->getName() << RESET
				<< DIM " takes " RESET << amount
				<< " damage and now has " << this->_hitPoints << " HP left!"
				<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout	<< "💀 " GREEN BOLD << this->getName() << RESET
					<< " can't be " DIM YELLOW "repaired" RESET " because it is destroyed!"
					<< std::endl;
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout	<< "🔋 " GREEN BOLD << this->getName() << RESET
					<< " can't " DIM YELLOW  "repair" RESET " itself because it has no energy left!"
					<< std::endl;
		return ;
	}
	std::cout	<< "🔧 " GREEN BOLD << this->getName() << RESET
				<< DIM YELLOW " repairs" RESET " itself for " << amount 
				<< " points and now has " << _hitPoints + amount << " HP!"
				<< std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

void	ClapTrap::displayStatus() const
{
	const int	nameWidth = 6;
	const int	fieldWidth = 9;

	std::cout	<< GREEN BOLD << std::left
				<< std::setw(nameWidth) << _name << RESET GREEN
				<< "| HP " << std::setw(fieldWidth - 3) << _hitPoints
				<< "| Energy " << std::setw(fieldWidth - 7) << _energyPoints
				<< "| Attack Damage " << _attackDamage
				<< RESET << std::endl;
}
