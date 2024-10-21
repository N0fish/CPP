/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:23:26 by algultse          #+#    #+#             */
/*   Updated: 2024/10/21 17:43:27 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#define NC "\e[0m"
#define RED "\e[31m"
#define PURPLE "\e[35m"

void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cout	<< RED
				<< "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< PURPLE
				<< "______________________________________________________________"
				<< NC << std::endl;

	std::cout	<< PURPLE << "|" << NC << std::setfill(' ') << std::setw(17) << RED
				<< "name"
				<< PURPLE << "  |  " << NC << std::setw(7) << RED
				<< "memory address"
				<< PURPLE << "  |  " << NC << std::setw(16) << RED
				<< "value"
				<< PURPLE << "  |  " << NC << std::endl;

	std::cout	<< PURPLE << "|" << NC << std::setfill(' ') << std::setw(16)
				<< "string"
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< &str
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< str
				<< PURPLE << "  |  " << NC << std::endl;

	std::cout	<< PURPLE << "|" << NC << std::setfill(' ') << std::setw(16)
				<< "stringPTR"
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< stringPTR
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< *stringPTR
				<< PURPLE << "  |  " << NC << std::endl;

	std::cout	<< PURPLE << "|" << NC << std::setfill(' ') << std::setw(16)
				<< "stringREF"
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< &stringREF
				<< PURPLE << "  |  " << NC << std::setw(16)
				<< stringREF
				<< PURPLE << "  |  " << NC << std::endl;

	std::cout	<< PURPLE
				<< "--------------------------------------------------------------"
				<< NC << std::endl;
	return (0);
}
