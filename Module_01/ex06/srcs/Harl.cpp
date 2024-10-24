/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:22:47 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 21:30:05 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

const std::string	Harl::levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

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

void	Harl::invalid( void ) {
	std::cout	<< CYAN << "[ INVALID ]" << RESET << std::endl
				<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
}

void Harl::doAction(Actions actions) {
	switch (actions) {
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break ;
		default:
			this->invalid();
	}
}

void	Harl::complain( std::string level )
{
	Actions	actions = NONE;

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			actions = (Actions)i;
			break ;
		}
	}
	this->doAction(actions);
}
