/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:35:25 by algultse          #+#    #+#             */
/*   Updated: 2024/10/23 23:40:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>
# include <string>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"

class Harl {
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		Harl();
		~Harl();

		void	complain( std::string level );
};

#endif