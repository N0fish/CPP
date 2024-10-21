/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:32:04 by algultse          #+#    #+#             */
/*   Updated: 2024/10/21 19:52:26 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string bName) : _name( bName ), _weapon( NULL )
{
	std::cout	<< YELLOW
				<< this->_name << " cautiously enters the arena, looking around for a weapon..."
				<< RESET << std::endl;
	return ;
}

HumanB::~HumanB() {
	std::cout	<< CYAN
				<< "HumanB " << HumanB::_name << " destroyed."
				<< RESET << std::endl;
}

void	HumanB::attack() const
{
	std::cout	<< HumanB::_name << " attacks with their ";
	if (HumanB::_weapon != NULL && HumanB::_weapon->getType() != "")
		std::cout	<< HumanB::_weapon->getType();
	else
		std::cout	<< "bare hands";
	std::cout	 << "!" << std::endl;
}

void	HumanB::setWeapon(Weapon& bWeapon) {
	HumanB::_weapon = &bWeapon;
}
