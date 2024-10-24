/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:30:32 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 19:20:21 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug( void ) {
	std::cout	<< BLUE << "[ DEBUG ]" << RESET << std::endl
				<< "I love having extra bacon for my "
				   "7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				   "I really do !" 
				<< std::endl;
}

void	Harl::info( void ) {
	std::cout	<< GREEN << "[ INFO ]" << RESET << std::endl
				<< "I cannot believe adding extra bacon costs more money.\n"
				   "You didn’t put enough bacon in my burger !\n"
				   "If you did, I wouldn’t be asking for more !"
				<< std::endl;
}

void	Harl::warning( void ) {
	std::cout	<< YELLOW << "[ WARNING ]" << RESET << std::endl
				<< "I think I deserve to have some extra bacon for free.\n"
				   "I’ve been coming for years whereas you started working here since last month."
				<< std::endl;
}

void	Harl::error( void ) {
	std::cout	<< RED << "[ ERROR ]" << RESET << std::endl
				<< "This is unacceptable ! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain( std::string level )
{
	typedef	void (Harl::*fptr)(void);

	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	fptr		actions[4] = { &Harl::debug,
							   &Harl::info,
							   &Harl::warning,
							   &Harl::error };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout	<< CYAN << "[ INVALID ]" << RESET << std::endl
				<< "Invalid level \"" << level << "\"." << std::endl;
}
