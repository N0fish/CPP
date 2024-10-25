/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:15 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:56:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 2)
		return ;
	std::cerr	<< PURPLE
				<< "Error! Usage: " << std::string(argv[0])
				<< " [DEBUG|INFO|WARNING|ERROR]"
				<< RESET << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	Harl harl;
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}
