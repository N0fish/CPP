/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:31:09 by algultse          #+#    #+#             */
/*   Updated: 2025/03/04 20:00:16 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << RED << "Usage: ./convert <literal>" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
