/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:16:05 by algultse          #+#    #+#             */
/*   Updated: 2024/10/20 21:30:25 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cctype>

# define NC "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"

class Zombie {
	private:
		std::string	name;

	public:
		Zombie();
		Zombie( std::string	name );
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);
void	getZombieData(int& N, std::string& name);

#endif