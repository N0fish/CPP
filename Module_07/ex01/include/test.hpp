/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:12:14 by algultse          #+#    #+#             */
/*   Updated: 2025/03/09 16:12:10 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "Colors.hpp"

template <typename T>
void	printElement(T const &elem) {
	if (typeid(elem) == typeid(double) || typeid(elem) == typeid(float)) {
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout << elem << " ";
	// std::cout << "Type: " << typeid(elem).name() << " | Value: " << elem << std::endl;
}

template <typename T>
void	addOne(T &elem) {
	elem += 1;
}

void	multiplyByTwo(int &elem) {
	elem *= 2;
}

void	roundDouble(double &elem) {
	elem = std::round(elem);
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