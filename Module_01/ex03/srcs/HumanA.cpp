/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:36:30 by algultse          #+#    #+#             */
/*   Updated: 2024/10/21 20:20:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string aName, Weapon& aWeapon) 
				: _name(aName),	_weapon(aWeapon)
{
	std::cout	<< YELLOW
				<< this->_name << " enters the battle with unwavering determination, gripping their "
				<< this->_weapon.getType() << "!"
				<< RESET << std::endl;
	return ;
}

HumanA::~HumanA() {
	std::cout	<< CYAN
				<< "HumanA " << HumanA::_name << " destroyed."
				<< RESET << std::endl;
}

void	HumanA::attack() const
{
	std::cout	<< HumanA::_name << " attacks with their ";
	if (_weapon.getType().empty())
		std::cout	<< "bare hands!";
	else
		std::cout	<< HumanA::_weapon.getType() << ".";
	std::cout	<< std::endl;
}
