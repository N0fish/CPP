/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:00:43 by algultse          #+#    #+#             */
/*   Updated: 2024/10/14 17:17:55 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc != 1) {
		std::cerr	<< "Error: " << std::string(argv[0]) 
					<< " needs no arguments from you" 
					<< std::endl;
		return (1);
	}

	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;
	std::cout << std::endl;

	randomChump("StackZombie");
	std::cout << std::endl;

	Zombie	zombie("StackMainZombie");
	zombie.announce();

	return (0);
}
