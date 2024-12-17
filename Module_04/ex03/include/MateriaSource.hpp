/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:05 by algultse          #+#    #+#             */
/*   Updated: 2024/12/17 20:23:37 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		static const int	_maxMateria = 4;
		AMateria*			_learnedMateria[_maxMateria];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(const std::string & type);
};

#endif
