/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:42:23 by algultse          #+#    #+#             */
/*   Updated: 2024/10/21 20:18:02 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string aName, Weapon& aWeapon);
		~HumanA();

		void	attack() const;
};

#endif