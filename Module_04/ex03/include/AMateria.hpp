/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:59:05 by algultse          #+#    #+#             */
/*   Updated: 2024/12/16 14:36:27 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAMATERIA_HPP
# define AAMATERIA_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Colors.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &amateria);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &amateria);

		std::string const	&getType(void) const; //Returns the materia type

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif