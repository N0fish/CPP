/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:38:04 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 19:10:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cure);
		~Cure();

		Cure	&operator=(const Cure &cure);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};

#endif