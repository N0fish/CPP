/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:30:23 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 20:01:11 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

void	testClapTrap()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing ClapTrap ⚙️\n"
				<< RESET << std::endl;

	ClapTrap	alpha("Alpha");
	ClapTrap	beta("Beta");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing ClapTraps..."
				<< RESET << std::endl;
	printStatus(alpha);
	printStatus(beta);

	std::cout	<< YELLOW << "\n🤖 ClapTrap Battle Begins!"	
				<< RESET << std::endl;
	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getAttackDamage());
	beta.beRepaired(5);

	std::cout	<< PURPLE << "\n🔧 Final ClapTrap Status:"
				<< RESET << std::endl;
	printStatus(alpha);
	printStatus(beta);

	std::cout	<< RED INVERSE << "\n\t⚠️  ClapTrap Test Complete ⚠️\n"
				<< RESET << std::endl;
}

void	testScavTrap()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing ScavTrap ⚙️\n"
				<< RESET << std::endl;

	ScavTrap	scav("Scavy");
	ScavTrap	guard("Guardian");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing ScavTraps..."
				<< RESET << std::endl;
	printStatus(scav);
	printStatus(guard);

	std::cout	<< YELLOW << "\n🤖 ScavTrap Battle Begins!"
				<< RESET << std::endl;
	scav.attack(guard.getName());
	guard.takeDamage(scav.getAttackDamage());
	guard.beRepaired(10);

	std::cout	<< "\n🔒 Activating Guard Gate Mode..." << std::endl;
	guard.guardGate();

	std::cout	<< PURPLE << "\n🔧 Final ScavTrap Status:"
				<< RESET << std::endl;
	printStatus(scav);
	printStatus(guard);

	std::cout	<< RED INVERSE << "\n\t⚠️  ScavTrap Test Complete ⚠️\n"
				<< RESET << std::endl;
}

void	testScavTrapGuardGate()
{
	std::cout	<< CYAN INVERSE << "\n\t⚙️  Testing ScavTrap GuardGate ⚙️\n"
				<< RESET << std::endl;

	ScavTrap	scav("Scavy");

	std::cout	<< GREEN BOLD << "\n🔧 Initializing ScavTrap..."
				<< RESET << std::endl;
	scav.displayStatus();

	std::cout	<< YELLOW << "\n🔒 Testing Guard Gate Mode..."
				<< RESET << std::endl;

	// Проверка: ScavTrap с полным здоровьем
	scav.guardGate();

	// Уменьшаем здоровье до 0
	scav.takeDamage(scav.getHitPoints());
	std::cout	<< YELLOW << "\n💥 ScavTrap takes fatal damage..."
				<< RESET << std::endl;

	// Проверка: ScavTrap с нулевым здоровьем
	scav.guardGate();

	std::cout	<< PURPLE << "\n🔧 Final ScavTrap Status:"
				<< RESET << std::endl;
	scav.displayStatus();

	std::cout	<< RED INVERSE << "\n\t⚠️  ScavTrap GuardGate Test Complete ⚠️\n"
				<< RESET << std::endl;
}
