/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:19 by algultse          #+#    #+#             */
/*   Updated: 2024/12/06 18:58:15 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                         Utility Functions for Testing                      */
/* -------------------------------------------------------------------------- */

static void	printStatus(const ClapTrap& robot)
{
	const int	nameWidth = 10;
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

void	testFragTrap()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing FragTrap ⚙️\n"
				<< RESET << std::endl;

	FragTrap	alpha("Alpha");
	FragTrap	beta("Beta");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing FragTraps..."
				<< RESET << std::endl;
	printStatus(alpha);
	printStatus(beta);

	std::cout	<< YELLOW << "\n🤖 FragTrap Battle Begins!"
				<< RESET << std::endl;

	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getAttackDamage());

	std::cout	<< BLUE << "\n🙌 Testing High Fives..."
				<< RESET << std::endl;
	beta.beRepaired(5);
	beta.highFivesGuys();

	alpha.takeDamage(beta.getHitPoints());
	alpha.takeDamage(beta.getAttackDamage());
	alpha.highFivesGuys();

	std::cout	<< PURPLE << "\n🔧 Final FragTrap Status:"
				<< RESET << std::endl;
	printStatus(alpha);
	printStatus(beta);

	std::cout	<< RED INVERSE << "\n\t⚠️  FragTrap Test Complete ⚠️\n"
				<< RESET << std::endl;
}

void	testMixedTraps()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing Mixed Trap Interactions ⚙️\n"
				<< RESET << std::endl;

	ClapTrap	basic("Basic");
	ScavTrap	scav("Scavy");
	FragTrap	frag("Fraggy");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing Traps..."
				<< RESET << std::endl;
	printStatus(basic);
	printStatus(scav);
	printStatus(frag);

	std::cout	<< YELLOW << "\n🤖 Mixed Battle Begins!"
				<< RESET << std::endl;

	basic.attack(scav.getName());
	scav.takeDamage(basic.getAttackDamage());
	scav.attack(frag.getName());
	frag.takeDamage(scav.getAttackDamage());
	frag.beRepaired(10);

	std::cout	<< "\n🔒 ScavTrap Testing GuardGate Mode..." << std::endl;
	scav.guardGate();

	std::cout	<< "\n🙌 FragTrap Testing High Fives..." << std::endl;
	frag.highFivesGuys();

	std::cout	<< PURPLE << "\n🔧 Final Status of All Traps:"
				<< RESET << std::endl;
	printStatus(basic);
	printStatus(scav);
	printStatus(frag);

	std::cout	<< RED INVERSE << "\n\t⚠️  Mixed Trap Test Complete ⚠️\n"
				<< RESET << std::endl;
}
