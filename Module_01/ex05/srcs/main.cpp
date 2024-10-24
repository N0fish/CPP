/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:22:06 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 19:19:45 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< PURPLE
				<< "Error: " << std::string(argv[0])
				<< " needs no arguments from you"
				<< std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID");

	return (EXIT_SUCCESS);
}
