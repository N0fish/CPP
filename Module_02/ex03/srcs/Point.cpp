/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:06:30 by algultse          #+#    #+#             */
/*   Updated: 2024/12/03 22:54:51 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	return ;
}

Point::Point(float xVal, float yVal) : _x(xVal), _y(yVal) {
	return ;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {
	return ;
}

Point::~Point() {
	return ;
}

Point	&Point::operator=(const Point & /* other */) throw() {
	std::cerr	<< YELLOW "\nAssignment operator cannot reassign const members." RESET
				<< std::endl;
	std::cerr	<< BOLD BLACK "\tUse a Point copy constructor instead.\n" RESET
				<< std::endl;
	return (*this);
}

Fixed	Point::getX() const {
	return (_x);
}

Fixed	Point::getY() const {
	return (_y);
}
