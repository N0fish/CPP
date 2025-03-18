/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:12:14 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 16:48:37 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "Colors.hpp"

template <typename T>
void	printElement(T const &elem) {
	std::cout << elem << " ";
}

template <typename T>
void	addOne(T &elem) {
	elem += 1;
}

void	multiplyByTwo(int &elem) {
	elem *= 2;
}

void	roundDouble(double &elem) {
	elem = (elem >= 0) ? floor(elem + 0.5) : ceil(elem - 0.5);
}

void	toUpperCase(char &elem) {
	elem = std::toupper(elem);
}

void	capitalizeString(std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
}

void	appendSuffix(std::string &str) {
	str += "_suffix";
}

#endif