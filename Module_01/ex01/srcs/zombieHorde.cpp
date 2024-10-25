/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:19:05 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:46:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0) {
		std::cout	<< RED << "Sending the horde back to their graves... May they rest... for now." 
					<< NC << std::endl;
		exit(1);
	}

	Zombie* horde = new Zombie[N];
	for(int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}
