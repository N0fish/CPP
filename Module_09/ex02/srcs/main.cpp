/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:30 by algultse          #+#    #+#             */
/*   Updated: 2025/03/25 14:03:52 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		PmergeMe	sorter;
		sorter.runSort(argc, argv);
	} catch (const std::exception &e) {
		std::cerr << RED DIM << "Error: " << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}
