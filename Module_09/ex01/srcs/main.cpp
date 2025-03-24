/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:49:21 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 18:55:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (1);
	}

	try {
		RPN calculator;
		calculator.processExpression(argv[1]);
		std::cout << "✔️ Result: " << calculator.getResult() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
