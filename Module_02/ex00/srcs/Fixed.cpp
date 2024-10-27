/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:52:30 by algultse          #+#    #+#             */
/*   Updated: 2024/10/27 22:40:52 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout	<< PURPLE "Default constructor called" RESET 
				<< std::endl;
	return ;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout	<< YELLOW "Copy constructor called" RESET 
				<< std::endl;
	this->_value = other.getRawBits();
	return ;
}

Fixed::~Fixed() {
	std::cout	<< BLUE "Destructor called" RESET 
				<< std::endl;
	return ;
}

Fixed	&Fixed::operator=( const Fixed &rhs ) {
	std::cout	<< YELLOW "Copy assignment operator called." RESET
				<< std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout	<< GREEN "getRawBits member function called." RESET
				<< std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout	<< GREEN "setRawBits member funtion called." RESET
				<< std::endl;
	this->_value = raw;
}
