/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:23:26 by algultse          #+#    #+#             */
/*   Updated: 2024/10/14 18:26:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 1) {
		std::cout	<< "Error: " << std::string(argv[0]) 
					<< " needs no arguments from you" 
					<< std::endl;
		return (1);
	}
	return (0);
}
