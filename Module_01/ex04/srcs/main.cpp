/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:30:03 by algultse          #+#    #+#             */
/*   Updated: 2024/10/14 19:38:06 by algultse         ###   ########.fr       */
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
