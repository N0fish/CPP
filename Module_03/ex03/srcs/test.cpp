/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:15:43 by algultse          #+#    #+#             */
/*   Updated: 2024/12/08 23:17:26 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                         Utility Functions for Testing                      */
/* -------------------------------------------------------------------------- */

static void printStatus(const ClapTrap& robot)
{
	const int	nameWidth = 20;
	const int	statWidth = 8;

	std::cout	<< GREEN BOLD << std::left
				<< std::setw(nameWidth) << robot.getName() << RESET GREEN
				<< "| HP: " << std::setw(statWidth) << robot.getHitPoints()
				<< "| Energy: " << std::setw(statWidth) << robot.getEnergyPoints()
				<< "| Attack Damage: " << robot.getAttackDamage()
				<< RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                Test Functions                              */
/* -------------------------------------------------------------------------- */

void	testDiamondTrap()
{
	std::cout	<< CYAN INVERSE << "\n\t💎 Testing DiamondTrap 💎\n"
				<< RESET << std::endl;

	DiamondTrap	diamondTrap("Shiny");
	DiamondTrap	copyTrap(diamondTrap);

	std::cout	<< GREEN BOLD << "\n🔧 Initializing DiamondTraps..."
				<< RESET << std::endl;
	printStatus(diamondTrap);

	std::cout	<< YELLOW << "\n🤖 DiamondTrap Battle Begins!" << RESET << std::endl;

	diamondTrap.attack("a target");
	diamondTrap.takeDamage(20);
	diamondTrap.beRepaired(10);
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();

	std::cout	<< "\n🆔 Testing WhoAmI..." << std::endl;
	diamondTrap.whoAmI();

	std::cout	<< "\n🔁 Testing Copy and Assignment..." << std::endl;
	copyTrap.whoAmI();
	copyTrap = DiamondTrap("CopyBot");
	copyTrap.whoAmI();

	std::cout	<< PURPLE << "\n🔧 Final DiamondTrap Status:" << RESET << std::endl;
	printStatus(diamondTrap);
	printStatus(copyTrap);

	std::cout	<< RED INVERSE << "\n\t⚠️  DiamondTrap Test Complete ⚠️\n" << RESET << std::endl;
}

void	testMixedTraps()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing Mixed Trap Interactions ⚙️\n"
				<< RESET << std::endl;

	ClapTrap	basic("Basic");
	ScavTrap	scav("Scavy");
	FragTrap	frag("Fraggy");
	DiamondTrap	diamond("Diamondy");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing All Traps..." << RESET << std::endl;
	printStatus(basic);
	printStatus(scav);
	printStatus(frag);
	printStatus(diamond);

	std::cout	<< YELLOW << "\n🤖 Mixed Trap Battle Begins!" << RESET << std::endl;

	basic.attack(scav.getName());
	scav.takeDamage(basic.getAttackDamage());
	scav.attack(frag.getName());
	frag.takeDamage(scav.getAttackDamage());
	frag.beRepaired(15);
	diamond.attack(frag.getName());
	frag.takeDamage(diamond.getAttackDamage());
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	std::cout	<< PURPLE << "\n🔧 Final Status of All Traps:" << RESET << std::endl;
	printStatus(basic);
	printStatus(scav);
	printStatus(frag);
	printStatus(diamond);

	std::cout	<< RED INVERSE << "\n\t⚠️  Mixed Trap Test Complete ⚠️\n" << RESET << std::endl;
}
