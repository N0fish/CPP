/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:05:33 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:54 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string			_name;
		static int const	_inventorySize = 4;
		AMateria*			_inventory[_inventorySize];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		Character	&operator=(const Character &other);

		std::string const	&getName(void) const;

		void				equip(AMateria *m);					// добавлнение
		void				unequip(int idx);					// сброс
		void				use(int idx, ICharacter &target);	// использование

		void				_deleteInventory();
};

#endif