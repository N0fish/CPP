/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:22:05 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:20:10 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Colors.hpp"
# include "Brain.hpp"

class Animal {
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& othet);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);

		virtual void		makeSound() const;
};

#endif