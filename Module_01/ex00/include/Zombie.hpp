/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:03:42 by algultse          #+#    #+#             */
/*   Updated: 2024/10/14 17:13:44 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie( std::string name);
		~Zombie();

		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif