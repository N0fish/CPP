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

void	double_print()
{
    std::cout << "DBL_MIN: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "DBL_MAX: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "DBL_EPSILON: " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "Infinity: " << std::numeric_limits<double>::infinity() << std::endl;
    std::cout << "NaN: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
}

int	main(int argc, char **argv)
{
	// double_print();
	if (argc != 2) {
		std::cerr << RED << "Usage: ./convert <literal>" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
