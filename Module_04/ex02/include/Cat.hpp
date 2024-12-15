/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:32:32 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 20:04:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const std::string& type, const std::string& firstIdea);
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		Brain*	getBrain() const;
		void	setBrain(Brain const &brain);
		void	makeSound() const;
};

#endif