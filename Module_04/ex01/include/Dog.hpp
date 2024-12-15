/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:34:06 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:21:59 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const std::string& type, const std::string& firstIdea);
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		Brain*	getBrain() const;
		void	setBrain(Brain const &brain);
		void	makeSound() const;
};

#endif