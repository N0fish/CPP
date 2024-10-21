/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:00:03 by algultse          #+#    #+#             */
/*   Updated: 2024/10/07 17:59:34 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	getInputMain()
{
	std::string	cmd;

	if (!std::getline(std::cin, cmd))
	{
		if (cmd.empty() && std::cin.eof())
			std::cout << "EXIT" << std::endl, cmd = "EXIT";
		else
			std::cin.clear();
	}
	return (stripWhitespace(cmd));
}

static void	displayMenu()
{
	std::cout 	<< std::endl
				<< "\t|------------------- Menu ------------------|" << std::endl
				<< "\t|-------------------------------------------|" << std::endl
				<< "\t|-------- What would you like to do? -------|" << std::endl	
				<< "\t|-- Enter the command (ADD, SEARCH, EXIT): -|" << std::endl
				<< "\t|-------------------------------------------|" << std::endl
				<< std::endl;
}

int	main(int argc, char **argv)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	if (argc != 1)
	{
		std::cerr	<< "Error: " << std::string(argv[0]) 
					<< " needs no arguments from you" 
					<< std::endl;
		return (1);
	}

	std::cout	<< std::endl 
				<< "     Welcome to the 80s and their incredible technology!" << std::endl;

	std::cout	<< "You can store between 1 and 8 contacts ! WOW, that is SO useful!" 
				<< std::endl;
	displayMenu();
	while (true)
	{
		std::cout << "> " << std::flush;

		cmd = getInputMain();

		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			phoneBook.addContact(), displayMenu();
		else if (cmd == "SEARCH")
			phoneBook.searchContacts(), displayMenu();
		else
		{
			std::cout	<< "Please enter the command:" << std::endl
						<< "\tADD\t: add a contact" << std::endl
						<< "\tSEARCH\t: search contact list" << std::endl
						<< "\tEXIT\t: exit the technology of the 80s" << std::endl;
		}
	}
	std::cout << "Thank you for using these incredible technologies !" << std::endl;
	return (0);
}
