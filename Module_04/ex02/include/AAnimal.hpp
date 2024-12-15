/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:22:05 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 22:06:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Colors.hpp"
# include "Brain.hpp"

class AAnimal {
	protected:
		std::string	_type;

		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& othet);

	public:
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& other);

		std::string const	&getType(void) const;

		virtual void		makeSound() const = 0;
};

#endif