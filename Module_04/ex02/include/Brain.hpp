/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:27:10 by algultse          #+#    #+#             */
/*   Updated: 2024/12/15 20:03:12 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"

# define BRAIN_SIZE	100

class Brain {
	private:
		std::string	_ideas[BRAIN_SIZE];

	public:
		Brain();
		Brain(const Brain& othet);
		~Brain();

		Brain&	operator=(const Brain& other);

		std::string const	&getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);
};

#endif