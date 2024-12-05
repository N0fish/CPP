/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:13 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 16:40:34 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< PURPLE "Error: " << std::string(argv[0])
				<< " needs no arguments from you" RESET
				<< std::endl;
	exit(EXIT_FAILURE);
}

static void	printClapTrapStatus(const ClapTrap& robot)
{
	std::cout << GREEN BOLD << robot.getName() << RESET GREEN
				<< " HP: " << robot.getHitPoints()
				<< ", Energy: " << robot.getEnergyPoints()
				<< ", Attack Damage: " << robot.getAttackDamage()
				<< RESET << std::endl;
}

void testClapTrap()
{
	std::cout	<< CYAN INVERSE
				<< "\n\t⚙️  Starting ClapTrap Test ⚙️\n"
				<< RESET << std::endl;

	// Создаём два робота
	ClapTrap	robot1("Alpha");
	ClapTrap	robot2("Beta");

	std::cout	<< GREEN << "\n🔧 Initializing robots..." << RESET << std::endl;
	printClapTrapStatus(robot1);
	printClapTrapStatus(robot2);

	std::cout	<< YELLOW << "\n🤖 Starting battle sequence..."
				<< RESET << std::endl;

	// Атака и получение урона
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());

	// printClapTrapStatus(robot1);
	// printClapTrapStatus(robot2);

	robot2.attack(robot1.getName());
	robot1.takeDamage(robot2.getAttackDamage());

	// printClapTrapStatus(robot1);
	// printClapTrapStatus(robot2);

	// Попытка атаковать без энергии
	for (int i = 0; i < 10; i++) {
		robot1.attack(robot2.getName());
		// robot1.displayStatus();
		// robot2.displayStatus();
	}

	// printClapTrapStatus(robot1);
	// printClapTrapStatus(robot2);

	std::cout << CYAN << "\n💡 Testing repair functionality..." << RESET << std::endl;

	// Восстановление
	robot1.beRepaired(5);
	robot2.beRepaired(10);

	std::cout << BLUE << "\n💥 Damage stress test..." << RESET << std::endl;
	// printClapTrapStatus(robot1);
	// printClapTrapStatus(robot2);
	// std::cout << std::endl;

	// Стресс-тест урона
	robot1.takeDamage(15);
	robot2.takeDamage(50);

	std::cout	<< PURPLE << "\n🔧 Final state of robots:"
				<< RESET << std::endl;
	// Итоговое состояние
	printClapTrapStatus(robot1);
	printClapTrapStatus(robot2);

	std::cout	<< RED INVERSE
				<< "\n\t⚠️  End of ClapTrap Test ⚠️\n"
				<< RESET << std::endl;
}

void	testClapTrap2()
{
	std::cout	<< CYAN INVERSE
				<< "\n\t⚙️  Starting ClapTrap Test ⚙️\n"
				<< RESET << std::endl;

	// Создаём два робота
	ClapTrap	robot1("Alpha");
	ClapTrap	robot2("Beta");

	std::cout	<< GREEN << "\n🔧 Initializing robots..." << RESET << std::endl;
	printClapTrapStatus(robot1);
	printClapTrapStatus(robot2);

	std::cout	<< YELLOW << "\n🤖 Starting battle sequence..."
				<< RESET << std::endl;

	// Атака и получение урона (по умолчанию урон 0)
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());

	// Изменяем урон через сеттер
	std::cout	<< CYAN << "\n🔨 Adjusting attack damage..."
				<< RESET << std::endl;
	robot1.setAttackDamage(5);
	robot2.setAttackDamage(3);

	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.attack(robot1.getName());
	robot1.takeDamage(robot2.getAttackDamage());

	std::cout	<< CYAN << "\n💡 Testing repair functionality..."
				<< RESET << std::endl;
	// Восстановление
	robot1.beRepaired(5);
	robot2.beRepaired(10);

	std::cout	<< BLUE << "\n💥 Damage stress test..."
				<< RESET << std::endl;
	// Стресс-тест урона
	robot1.takeDamage(15);
	robot2.takeDamage(50);

	std::cout	<< PURPLE << "\n🔧 Final state of robots:"
				<< RESET << std::endl;
	// Итоговое состояние
	printClapTrapStatus(robot1);
	printClapTrapStatus(robot2);

	std::cout	<< RED INVERSE
				<< "\n\t⚠️  End of ClapTrap Test ⚠️\n"
				<< RESET << std::endl;
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);
	testClapTrap();
	return (0);
}
