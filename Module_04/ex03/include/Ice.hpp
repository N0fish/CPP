/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:11:54 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 18:20:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &ice);
		~Ice();

		Ice	&operator=(const Ice &ice);

		AMateria			*clone(void) const;
		void				use(ICharacter &target);
};

#endif