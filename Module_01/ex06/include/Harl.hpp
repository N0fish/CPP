/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:23:25 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:55:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"

typedef enum Actions {
	NONE = -1,
	DEBUG,
	INFO,
	WARNING,
	ERROR
}			Actions;

class Harl {
	private:
		static const std::string	levels[4];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	invalid( void );

		void	doAction(Actions);

	public:
		Harl();
		~Harl();

		void	complain( std::string level );
};

#endif