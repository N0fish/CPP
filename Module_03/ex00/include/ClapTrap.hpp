/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:47:10 by algultse          #+#    #+#             */
/*   Updated: 2024/12/04 16:03:29 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPRTAP_HPP
# define CLAPRTAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Colors.hpp"

class ClapTrap {
	private:
		std::string	_name;
		int			_hitPoints;		//сколько здоровья у робота.
		int			_energyPoints;	//сколько у него энергии.
		int			_attackDamage;	//какой урон он наносит.

	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &other);

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
		void		setName(std::string const &name);
		void		setHitPoints(int const &value);
		void		setEnergyPoints(int const &value);
		void		setAttackDamage(int const &value);

		void		attack(const std::string& target);	//атакует цель.
		void		takeDamage(unsigned int amount);	//получает урон.
		void		beRepaired(unsigned int amount);	//восстанавливает здоровье.
		void		displayStatus() const;
};

#endif