/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:12:55 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:45:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	colorZombieName(const std::string& color, const std::string& name) 
{
	return (color + name + NC);
}

void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< RED
				<< "Error: " << std::string(argv[0]) 
				<< " needs no arguments from you" 
				<< NC << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	int			N;
	std::string	name;

	getZombieData(N, name);
	std::cout	<< std::endl
				<< GREEN << "Brewing dark potions... preparing to unleash \'" 
				<< name << "\', of " << N << " fiendish creatures!" << NC 
				<< std::endl;
	std::cout	<< GREEN << "Allocating space for zombies..." << NC 
				<< std::endl;

	Zombie* horde = zombieHorde(N, colorZombieName(YELLOW, name));
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;

	return (0);
}
