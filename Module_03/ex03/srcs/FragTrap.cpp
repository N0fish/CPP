/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:01:11 by algultse          #+#    #+#             */
/*   Updated: 2024/12/06 19:10:13 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< GRAY_ON_WHITE "FragTrap from ClapTrap " 
				<< BOLD GREEN_ON_WHITE << _name << RESET
				<< GRAY_ON_WHITE " initialized with " 
				<< BOLD YELLOW_ON_WHITE "default" RESET
				<< INVERSE GRAY_ON_WHITE " constructor!" RESET
				<< std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;

	std::cout	<< GRAY_ON_WHITE "FragTrap "
				<< BOLD GREEN_ON_WHITE << _name << RESET
				<< BOLD GRAY_ON_WHITE " constructed!" RESET
				<< std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout	<< GRAY_ON_WHITE "FragTrap "
				<< BOLD GREEN_ON_WHITE << _name
				<< BOLD YELLOW_ON_WHITE << " copied." RESET
				<< std::endl;
	return ;
}

FragTrap::~FragTrap() {
	std::cout	<< GRAY_ON_WHITE "FragTrap "
				<< BOLD GREEN_ON_WHITE << _name << RESET
				<< BOLD BLUE_ON_WHITE " destroyed." 
				<< RESET << std::endl;
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

FragTrap	&FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout	<< GRAY_ON_WHITE "FragTrap " 
				<< BOLD GREEN_ON_WHITE << _name << RESET 
				<< PURPLE_ON_WHITE " assigned!" RESET
				<< std::endl;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	FragTrap::highFivesGuys(void) const {
	if (_hitPoints <= 0) {
		std::cout	<< "💀 " 
					<< BOLD GREEN_ON_WHITE << _name << RESET 
					<< GRAY_ON_WHITE << " tries to ask for a high five, but unfortunately, it's already destroyed..."
					<< RESET << std::endl;
		return ;
	}
	std::cout	<< "🙌 " << GRAY_ON_WHITE "FragTrap "
				<< BOLD GREEN_ON_WHITE << _name << RESET
				<< GRAY_ON_WHITE " is asking for a high five!" RESET " ✋"
				<< std::endl;
}

void	FragTrap::displayStatus() const {
	const int	nameWidth = 7;
	const int	fieldWidth = 10;

	std::cout	<< BOLD GREEN_ON_WHITE << std::left
				<< std::setw(nameWidth) << _name << RESET GRAY_ON_WHITE
				<< "| HP " << std::setw(fieldWidth - 3) << _hitPoints
				<< "| Energy " << std::setw(fieldWidth - 7) << _energyPoints
				<< "| Attack Damage " << _attackDamage
				<< RESET << std::endl;
}
