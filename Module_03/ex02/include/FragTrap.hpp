/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:48:17 by algultse          #+#    #+#             */
/*   Updated: 2024/12/05 20:19:40 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_DEFAULT_HIT_POINTS 100
# define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
# define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap	&operator=(const FragTrap& other);

		void	highFivesGuys(void) const;
		void	displayStatus() const;
};

#endif