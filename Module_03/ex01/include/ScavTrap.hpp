/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:48:17 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:18 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_DEFAULT_HIT_POINTS 100
# define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
# define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &other);

		void	attack(const std::string& target);
		void	guardGate() const ;
		void	displayStatus() const;
};

#endif